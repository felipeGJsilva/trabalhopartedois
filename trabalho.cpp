int sum = 13; // Holds the state of the sum button
int carryBit = 0; // Holds the carry bit (sum overflow)
int nib1a, nib1b, nib1c, nib1d = 0; // Nibbles of the first number, pins 0 to 3
int nib2a, nib2b, nib2c, nib2d = 0; // Nibbles of the second number, pins 4 to 7
int res1a, res1b, res1c, res1d = 0; // Result of the nibbles' sum

void setup()
{
    // Configure the pins as input or output
    pinMode(0, INPUT); // Pin 0 as input for nib1a
    pinMode(1, INPUT); // Pin 1 as input for nib1b
    pinMode(2, INPUT); // Pin 2 as input for nib1c
    pinMode(3, INPUT); // Pin 3 as input for nib1d
    pinMode(4, INPUT); // Pin 4 as input for nib2a
    pinMode(5, INPUT); // Pin 5 as input for nib2b
    pinMode(6, INPUT); // Pin 6 as input for nib2c
    pinMode(7, INPUT); // Pin 7 as input for nib2d
    pinMode(8, OUTPUT); // Pin 8 as output for res1a
    pinMode(9, OUTPUT); // Pin 9 as output for res1b
    pinMode(10, OUTPUT); // Pin 10 as output for res1c
    pinMode(11, OUTPUT); // Pin 11 as output for res1d
    pinMode(12, OUTPUT); // Pin 12 as output for carryBit
    pinMode(13, INPUT); // Pin 13 as input for the sum button
}

// Sums the bits, considering the previous carry bit
int sumBit(int b1a, int b2a, int cBit)
{
    return (b1a ^ b2a) ^ cBit; // XOR to sum the bits
}

// Calculates the new carry bit
int sumCarryBit(int b1a, int b2a, int cBit)
{
    // The carry bit will be 1 if at least two of the three input bits are 1
    return (b1a && b2a) || (b1a && cBit) || (b2a && cBit);
}

void loop()
{
    // Reads the state of the sum button
    sum = digitalRead(13);

    // Reads the nibbles from the corresponding pins
    nib1a = digitalRead(0);
    nib1b = digitalRead(1);
    nib1c = digitalRead(2);
    nib1d = digitalRead(3);
    nib2a = digitalRead(4);
    nib2b = digitalRead(5);
    nib2c = digitalRead(6);
    nib2d = digitalRead(7);

    if (sum == 1) // If the sum button is pressed
    {
        carryBit = 0; // Initialize the carry bit

        // Sum bit by bit of the nibbles, including the carry bit
        res1a = sumBit(nib1a, nib2a, carryBit); // Sum of the first bit
        carryBit = sumCarryBit(nib1a, nib2a, carryBit); // Update the carry bit
        res1b = sumBit(nib1b, nib2b, carryBit); // Sum of the second bit
        carryBit = sumCarryBit(nib1b, nib2b, carryBit); // Update the carry bit
        res1c = sumBit(nib1c, nib2c, carryBit); // Sum of the third bit
        carryBit = sumCarryBit(nib1c, nib2c, carryBit); // Update the carry bit
        res1d = sumBit(nib1d, nib2d, carryBit); // Sum of the fourth bit
        carryBit = sumCarryBit(nib1d, nib2d, carryBit); // Update the carry bit
    }

    // Write the sum result to the output pins
    digitalWrite(8, res1a); // Set the result of the first bit on the output pins
    digitalWrite(9, res1b); // Set the result of the second bit on the output pins
    digitalWrite(10, res1c); // Set the result of the third bit on the output pins
    digitalWrite(11, res1d); // Set the result of the fourth bit on the output pins
    digitalWrite(12, carryBit); // Set the final carry bit on the output pins
}
