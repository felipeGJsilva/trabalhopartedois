int soma = 13; // Guarda o estado do botão de soma
int carryBit = 0; // Guarda o carry bit (extras da soma)
int nib1a, nib1b, nib1c, nib1d = 0; // Nibbles do primeiro número, pinos 0 a 3
int nib2a, nib2b, nib2c, nib2d = 0; // Nibbles do segundo número, pinos 4 a 7
int res1a, res1b, res1c, res1d = 0; // Resultado da soma dos nibbles

void setup()
{
    // Configura os pinos como entrada ou saída
    pinMode(0, INPUT); // Pino 0 como entrada para nib1a
    pinMode(1, INPUT); // Pino 1 como entrada para nib1b
    pinMode(2, INPUT); // Pino 2 como entrada para nib1c
    pinMode(3, INPUT); // Pino 3 como entrada para nib1d
    pinMode(4, INPUT); // Pino 4 como entrada para nib2a
    pinMode(5, INPUT); // Pino 5 como entrada para nib2b
    pinMode(6, INPUT); // Pino 6 como entrada para nib2c
    pinMode(7, INPUT); // Pino 7 como entrada para nib2d
    pinMode(8, OUTPUT); // Pino 8 como saída para res1a
    pinMode(9, OUTPUT); // Pino 9 como saída para res1b
    pinMode(10, OUTPUT); // Pino 10 como saída para res1c
    pinMode(11, OUTPUT); // Pino 11 como saída para res1d
    pinMode(12, OUTPUT); // Pino 12 como saída para carryBit
    pinMode(13, INPUT); // Pino 13 como entrada para o botão de soma
}

// Soma os bits, considerando o carry bit anterior
int somaBit(int b1a, int b2a, int cBit)
{
    return (b1a ^ b2a) ^ cBit; // XOR para somar os bits
}

// Calcula o novo carry bit
int somaCarryBit(int b1a, int b2a, int cBit)
{
    // O carry bit será 1 se pelo menos dois dos três bits de entrada forem 1
    return (b1a && b2a) || (b1a && cBit) || (b2a && cBit);
}

void loop()
{
    // Lê o estado do botão de soma
    soma = digitalRead(13);

    // Lê os nibbles dos pinos correspondentes
    nib1a = digitalRead(0);
    nib1b = digitalRead(1);
    nib1c = digitalRead(2);
    nib1d = digitalRead(3);
    nib2a = digitalRead(4);
    nib2b = digitalRead(5);
    nib2c = digitalRead(6);
    nib2d = digitalRead(7);

    if (soma == 1) // Se o botão de soma está pressionado
    {
        carryBit = 0; // Inicializa o carry bit

        // Soma bit a bit dos nibbles, incluindo o carry bit
        res1a = somaBit(nib1a, nib2a, carryBit); // Soma do primeiro bit
        carryBit = somaCarryBit(nib1a, nib2a, carryBit); // Atualiza o carry bit
        res1b = somaBit(nib1b, nib2b, carryBit); // Soma do segundo bit
        carryBit = somaCarryBit(nib1b, nib2b, carryBit); // Atualiza o carry bit
        res1c = somaBit(nib1c, nib2c, carryBit); // Soma do terceiro bit
        carryBit = somaCarryBit(nib1c, nib2c, carryBit); // Atualiza o carry bit
        res1d = somaBit(nib1d, nib2d, carryBit); // Soma do quarto bit
        carryBit = somaCarryBit(nib1d, nib2d, carryBit); // Atualiza o carry bit
    }

    // Escreve o resultado da soma nos pinos de saída
    digitalWrite(8, res1a); // Define o resultado do primeiro bit nos pinos de saída
    digitalWrite(9, res1b); // Define o resultado do segundo bit nos pinos de saída
    digitalWrite(10, res1c); // Define o resultado do terceiro bit nos pinos de saída
    digitalWrite(11, res1d); // Define o resultado do quarto bit nos pinos de saída
    digitalWrite(12, carryBit); // Define o carry bit final nos pinos de saída
}
