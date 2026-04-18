#include <stdio.h>
#include <stdlib.h>

void DoBubbleSortWithEquivalencePointerArray(short int* paiA, unsigned int uiSize);


//Verbesserung der Laufzeit von BubbleSort:
//Man kann eine Abbruchbedingung einbauen(Flag / Boolean), das prüft,
//ob in einem Durchlauf überhaupt noch Vertauschungen stattfinden.
//Wenn kein Tausch mehr erfolgt, ist das Array bereits sortiert und
//der Algorithmus kann frühzeitig beendet werden.
//Das verbessert die Laufzeit besonders bei fast sortierten Arrays
//von O(n ^ 2) auf im Bestfall O(n).

int main(void)
{
	short int* piMemory = NULL; // CSG: DV14
	// CSG: DV15
	piMemory = (short int*)malloc(100 * sizeof(short int));

	if (piMemory != NULL)
	{
		// Dynamic memory allocation successful
		// Do something with allocated memory

		short int* piTwo = piMemory;

		for (short int i = 100; i > 0; i--)
		{
			*piTwo = i;
			piTwo++;
		}

		printf("Vor dem Sortieren:\n");
		for (int i = 0; i < 100; i++)
		{
			printf("%d ", piMemory[i]);
		}
		printf("\n");

		DoBubbleSortWithEquivalencePointerArray(piMemory,100);

		printf("Nach dem Sortieren:\n");
		for (int i = 0; i < 100; i++)
		{
			printf("%d ", piMemory[i]);
		}
		printf("\n");
		// If allocated memory not needed anymore
		free(piMemory);
		piMemory = NULL; // CSG: DV16
	}
	return 0;
}

void DoBubbleSortWithEquivalencePointerArray(short int* paiA,	unsigned int uiSize) {
	unsigned uiY;
	unsigned uiX;
	short int iDummy;
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