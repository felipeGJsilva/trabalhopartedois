# 4-Bit Adder with Carry Bit

This is a program for an Arduino that simulates a 4-bit adder. It reads two 4-bit binary numbers from the input pins, adds them together, and displays the result on the output pins. If the sum exceeds 4 bits, it also calculates and displays the carry bit.

## How the Code Works

### Variables and Pin Setup

```cpp
int soma = 13;
int carryBit = 0;
int nib1a, nib1b, nib1c, nib1d = 0;
int nib2a, nib2b, nib2c, nib2d = 0;
int res1a, res1b, res1c, res1d = 0;
```

- `soma`: A variable to store the state of the sum operation.
- `carryBit`: A variable to store the carry bit after addition.
- `nib1a, nib1b, nib1c, nib1d`: Variables to store the first 4-bit number.
- `nib2a, nib2b, nib2c, nib2d`: Variables to store the second 4-bit number.
- `res1a, res1b, res1c, res1d`: Variables to store the result of the addition.

### `setup` Function

The `setup` function initializes the input and output pins.

```cpp
void setup()
{
    pinMode(0, INPUT);
    pinMode(1, INPUT);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, INPUT);
}
```

- Pins 0 to 4: Inputs for the first 4-bit number and the sum operation signal.
- Pins 5 to 8: Inputs for the second 4-bit number.
- Pins 9 to 12: Outputs for the result of the addition.
- Pin 13: Output for the carry bit.

### Addition Functions

#### `somaBit` Function

This function calculates the sum of two bits and a carry bit.

```cpp
int somaBit(int b1a, int b2a, int cBit)
{
    int bitResult = 0;
    if ((b1a ^ b2a) ^ cBit)
    {
        bitResult = 1;
    }
    else
    {
        bitResult = 0;
    }
    return bitResult;
}
```

- `b1a`, `b2a`: The bits to be added.
- `cBit`: The carry bit.
- Returns the result of the addition.

#### `somaCarryBit` Function

This function calculates the carry bit from the addition of two bits and an existing carry bit.

```cpp
int somaCarryBit(int b1a, int b2a, int cBit)
{
    if ((b1a && b2a) || (b1a && cBit) || (b2a && cBit))
    {
        cBit = 1;
    }
    else
    {
        cBit = 0;
    }
    return cBit;
}
```

- `b1a`, `b2a`: The bits to be added.
- `cBit`: The carry bit.
- Returns the new carry bit.

### `loop` Function

The `loop` function continuously reads the input pins, performs the addition if the `soma` signal is high, and writes the result to the output pins.

```cpp
void loop()
{
    soma = digitalRead(0);
    nib1a = digitalRead(1);
    nib1b = digitalRead(2);
    nib1c = digitalRead(3);
    nib1d = digitalRead(4);
    nib2a = digitalRead(5);
    nib2b = digitalRead(6);
    nib2c = digitalRead(7);
    nib2d = digitalRead(8);
    if (soma == 1)
    {
        carryBit = 0;
        res1a = somaBit(nib1a, nib2a, carryBit);
        carryBit = somaCarryBit(nib1a, nib2a, carryBit);
        res1b = somaBit(nib1b, nib2b, carryBit);
        carryBit = somaCarryBit(nib1b, nib2b, carryBit);
        res1c = somaBit(nib1c, nib2c, carryBit);
        carryBit = somaCarryBit(nib1c, nib2c, carryBit);
        res1d = somaBit(nib1d, nib2d, carryBit);
        carryBit = somaCarryBit(nib1d, nib2d, carryBit);
    }
    digitalWrite(9, res1a);
    digitalWrite(10, res1b);
    digitalWrite(11, res1c);
    digitalWrite(12, res1d);
    digitalWrite(13, carryBit);
}
```

- Reads the input pins to get the two 4-bit numbers and the sum operation signal.
- If the sum operation signal (`soma`) is high, performs the addition bit by bit.
- Writes the result of each bit addition to the corresponding output pin.
- Writes the carry bit to pin 13.

## Step-by-Step Instructions

1. **Set up the Arduino:**
   - Connect the input pins (0-8) to your binary number sources.
   - Connect the output pins (9-13) to your display or LEDs.
2. **Upload the code:**
   - Compile and upload the code to your Arduino board.
3. **Perform the addition:**
   - Set the input pins to represent two 4-bit numbers.
   - Set pin 0 high to perform the addition.
   - Observe the result on the output pins (9-12) and the carry bit on pin 13.

This documentation provides an overview of the 4-bit adder program, detailing each function and the main logic of the program.