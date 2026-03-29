#include <stdio.h>

unsigned long long int CalcFacultyIterativ(unsigned int uiN);
unsigned long long int CalcFacultyRecursiv(unsigned int uiN);
unsigned long long int CalcSumIterativ(unsigned int uiN);
unsigned long long int CalcSumRecursiv(unsigned int uiN);

int main(void)
{
	unsigned int uiN;

	printf("n: ");
	scanf_s("%u", &uiN);

	printf("CalcFacultyIterativ: %llu\n", CalcFacultyIterativ(uiN));
	printf("CalcFacultyRecursiv: %llu\n", CalcFacultyRecursiv(uiN));
	printf("CalcSumIterativ: %llu\n", CalcSumIterativ(uiN));
	printf("CalcSumRecursiv: %llu\n", CalcSumRecursiv(uiN));
}

unsigned long long int CalcFacultyIterativ(unsigned int uiN)
{
	unsigned long long int result = 1;

	for (unsigned int i = 1; i <= uiN; i++)
	{
		result *= i;
	}

	return result;
}

unsigned long long int CalcFacultyRecursiv(unsigned int uiN)
{
	unsigned long long int ulliRet;
	if (uiN == 0)
	{
		ulliRet = 1;
	}
	else
	{
		ulliRet = uiN * CalcFacultyRecursiv(uiN - 1);
	}
	return ulliRet;
}

unsigned long long int CalcSumIterativ(unsigned int uiN)
{
	unsigned long long int result = 0;

	for (unsigned int i = 0; i <= uiN; i++)
	{
		result += i;
	}

	return result;
}

unsigned long long int CalcSumRecursiv(unsigned int uiN)
{
	unsigned long long int ulliRet;
	if (uiN == 0)
	{
		ulliRet = 0;
	}
	else
	{
		ulliRet = uiN + CalcSumRecursiv(uiN - 1);
	}
	return ulliRet;
}