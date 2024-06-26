Here is a simplified version of your 4-bit adder Arduino program with clear explanations and essential details.

### Program Overview

This Arduino program simulates a 4-bit adder. It reads two 4-bit binary numbers from the input pins, adds them together, and displays the result on the output pins. If the sum exceeds 4 bits, it also calculates and displays the carry bit.

### Variables and Pin Setup

```cpp
int soma = 13;
int carryBit = 0;
int nib1[4] = {0, 0, 0, 0};
int nib2[4] = {0, 0, 0, 0};
int res[4] = {0, 0, 0, 0};
```

- `soma`: A variable to store the state of the sum operation.
- `carryBit`: A variable to store the carry bit after addition.
- `nib1`: Array to store the first 4-bit number.
- `nib2`: Array to store the second 4-bit number.
- `res`: Array to store the result of the addition.

### setup Function

The setup function initializes the input and output pins.

```cpp
void setup() {
    for (int i = 0; i <= 8; i++) {
        pinMode(i, INPUT);
    }
    for (int i = 9; i <= 12; i++) {
        pinMode(i, OUTPUT);
    }
    pinMode(13, OUTPUT);
}
```

### Addition Functions

#### somaBit Function

This function calculates the sum of two bits and a carry bit.

```cpp
int somaBit(int b1, int b2, int c) {
    return (b1 ^ b2) ^ c;
}
```

#### somaCarryBit Function

This function calculates the carry bit from the addition of two bits and an existing carry bit.

```cpp
int somaCarryBit(int b1, int b2, int c) {
    return (b1 & b2) | (b1 & c) | (b2 & c);
}
```

### loop Function

The loop function continuously reads the input pins, performs the addition if the `soma` signal is high, and writes the result to the output pins.

```cpp
void loop() {
    soma = digitalRead(0);
    for (int i = 0; i < 4; i++) {
        nib1[i] = digitalRead(i + 1);
        nib2[i] = digitalRead(i + 5);
    }

    if (soma == 1) {
        carryBit = 0;
        for (int i = 0; i < 4; i++) {
            res[i] = somaBit(nib1[i], nib2[i], carryBit);
            carryBit = somaCarryBit(nib1[i], nib2[i], carryBit);
        }
    }

    for (int i = 0; i < 4; i++) {
        digitalWrite(i + 9, res[i]);
    }
    digitalWrite(13, carryBit);
}
```

### Step-by-Step Instructions

1. **Set up the Arduino:**
   - Connect the input pins (0-8) to your binary number sources.
   - Connect the output pins (9-13) to your display or LEDs.
   
2. **Upload the code:**
   - Compile and upload the code to your Arduino board.

3. **Perform the addition:**
   - Set the input pins to represent two 4-bit numbers.
   - Set pin 0 high to perform the addition.
   - Observe the result on the output pins (9-12) and the carry bit on pin 13.

This simplified documentation provides a clear overview of the 4-bit adder program, detailing each function and the main logic of the program.