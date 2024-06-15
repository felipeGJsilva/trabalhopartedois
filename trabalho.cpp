//TÉCNICO EM DESENVOLVIMENTO DE SISTEMAS - SENAC NH
//Programa base para TRABALHO 2
//PROF.: Glauber Kiss de Souza
//DISC.: Analizar Orient. Técnicas

int soma = 13;
int carryBit = 0;
int nib1a,nib1b,nib1c,nib1d = 0;
int nib2a,nib2b,nib2c,nib2d = 0;
int res1a,res1b,res1c,res1d = 0;
// Comentarios
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

int somaBit(int b1a, int b2a, int cBit)
{
	int bitResult = 0;
	int aux1, aux2 = 0;
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

int somaCarryBit(int b1a, int b2a, int cBit)
{
	int aux1, aux2 = 0;
	if ((b1a && b2a)||(b1a && cBit)||(b2a && cBit))
	{
		cBit = 1;
	}
	else
	{
		cBit = 0;
	}
	return cBit;
}

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
		res1a = somaBit(nib1a,nib2a,carryBit);
		carryBit = somaCarryBit(nib1a,nib2a,carryBit);
		res1b = somaBit(nib1b,nib2b,carryBit);
		carryBit = somaCarryBit(nib1b,nib2b,carryBit);
		res1c = somaBit(nib1c,nib2c,carryBit);
		carryBit = somaCarryBit(nib1c,nib2c,carryBit);
		res1d = somaBit(nib1d,nib2d,carryBit);
		carryBit = somaCarryBit(nib1d,nib2d,carryBit);
	}
	digitalWrite(9,res1a);
	digitalWrite(10,res1b);
	digitalWrite(11,res1c);
	digitalWrite(12,res1d);
	digitalWrite(13,carryBit);
}
