#include <stdio.h>
#define ARRAY_LEN 100

int aiArray[ARRAY_LEN] = {0};

void printArray(void);

void DoBubbleSortWithPointerMethod1(int* paiA, unsigned int uiSize);

void DoBubbleSortWithPointerMethod2(int* paiA, unsigned int uiSize);

void DoBubbleSortWithEquivalencePointerArray(int* paiA, unsigned int uiSize);


//Welcher Nutzen hat das „-uiY“ in der inneren Schleife? 
//nach dem ersten durchlauf ist das größte element ganz rechts heißt er muss mit dem nicht mehr prüfen also minus die anzahl itterationen

int main(void)
{

	int iValue = 50;
	for (int i = 0; i < ARRAY_LEN; i++)
	{
		aiArray[i] = iValue;
		iValue--;
	}

	printArray();

	DoBubbleSortWithEquivalencePointerArray(aiArray,ARRAY_LEN);

	printArray();

	return 0;
}


void printArray(void)
{
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        printf("%i\t", aiArray[i]);

        if (((i + 1) % 10) == 0)
        {
            printf("\n");
        }
    }

	printf("\n\n");
}

void DoBubbleSortWithPointerMethod1(int* paiA, unsigned int uiSize)
{
	unsigned uiY;
	unsigned uiX;
	int* paiDummy;
	int iDummy;
	for (uiY = 0U; uiY < (uiSize - 1U); uiY++)
	{
		paiDummy = paiA;
		for (uiX = 0U; uiX < (uiSize - 1U - uiY); uiX++)
		{
			if (*(paiDummy + 0) > *(paiDummy + 1))
			{
				iDummy = *(paiDummy + 0);
				*(paiDummy + 0) = *(paiDummy + 1);
				*(paiDummy + 1) = iDummy;
			}
			paiDummy++;
		}
	}
}

void DoBubbleSortWithPointerMethod2(int* paiA, unsigned int uiSize) {
	unsigned uiY;
	unsigned uiX;
	int iDummy;
	for (uiY = 0U; uiY < (uiSize - 1U); uiY++)
	{
		for (uiX = 0U; uiX < (uiSize - 1U - uiY); uiX++)
		{
			if (*(paiA + uiX + 0) > *(paiA + uiX + 1))
			{
				iDummy = *(paiA + uiX + 0);
				*(paiA + uiX + 0) = *(paiA + uiX + 1);
				*(paiA + uiX + 1) = iDummy;
			}
		}
	}
}

void DoBubbleSortWithEquivalencePointerArray(int* paiA,	unsigned int uiSize) {
	unsigned uiY;
	unsigned uiX;
	int iDummy;
	for (uiY = 0U; uiY < (uiSize - 1U); uiY++)
	{
		for (uiX = 0U; uiX < (uiSize - 1U - uiY); uiX++)
		{
			if (paiA[uiX] > paiA[uiX + 1])
			{
				iDummy = paiA[uiX];
				paiA[uiX] = paiA[uiX + 1];
				paiA[uiX + 1] = iDummy;
			}
		}
	}
}