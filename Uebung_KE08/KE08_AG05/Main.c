#include <stdio.h>
#include <stdlib.h>
#define ARRAY_LEN 10

struct MonthlySalary
{
	unsigned int uiEmployeeNumber;
	float fSalary;
};
typedef struct MonthlySalary sMonthlySalary_t;
typedef sMonthlySalary_t* psMonthlySalary_t;

int CompareFloat(const void* pcv1, const void* pcv2);

int CompareSalary(const void* pcv1, const void* pcv2);


//Wie könnte durch Anpassung von struct MonthlySalary die Compare-Funktion für struct MonthlySalary einspart werden ?

//Die Compare-Funktion für struct MonthlySalary könnte eingespart werden,
//wenn die Struktur so geändert wird, dass das Sortierkriterium(fSalary)
//an erster Stelle im struct steht oder die Struktur nur aus fSalary besteht.
//Dann könnte man theoretisch einen generischen Float-Compare verwenden,
//indem man direkt auf den Anfang des Structs zeigt(Cast auf float*).
//Dadurch wäre keine separate Compare - Funktion für das Struct nötig,
//da das Sortierkriterium direkt mit dem Speicheranfang übereinstimmt.

int main(void)
{
	float afSalary[ARRAY_LEN] = { 5.2f, 1.1f, 9.9f, 3.3f, 7.7f, 2.2f, 8.8f, 6.6f, 4.4f, 0.5f };

	sMonthlySalary_t asMonthlySalary[ARRAY_LEN] = {
        {1001, 3200.5f},
        {1002, 2100.0f},
        {1003, 4500.0f},
        {1004, 1800.0f},
        {1005, 3900.0f},
        {1006, 2750.0f},
        {1007, 5100.0f},
        {1008, 3050.0f},
        {1009, 1500.0f},
        {1010, 4200.0f}
    };


	qsort(afSalary, ARRAY_LEN, sizeof(float), CompareFloat);
	qsort(asMonthlySalary, ARRAY_LEN, sizeof(sMonthlySalary_t), CompareSalary);

    // Ausgabe float Array
    printf("Sorted float array:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f ", afSalary[i]);
    }
    printf("\n\n");

    // Ausgabe Struct Array
    printf("Sorted salaries:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Employee %u -> %.2f\n",
            asMonthlySalary[i].uiEmployeeNumber,
            asMonthlySalary[i].fSalary);
    }

	return 0;
}

int CompareFloat(const void* pcv1, const void* pcv2) { 
    int iRet;
    float* piV1 = (float*)pcv1;
    float* piV2 = (float*)pcv2;
    if (*piV1 < *piV2) iRet = -1;
    else if (*piV1 > *piV2) iRet = 1;
    else iRet = 0;
    return iRet;
}

int CompareSalary(const void* pcv1, const void* pcv2)
{
    int iRet;
    sMonthlySalary_t* piV1 = (sMonthlySalary_t*)pcv1;
    sMonthlySalary_t* piV2 = (sMonthlySalary_t*)pcv2;
    if (piV1->fSalary < piV2->fSalary) iRet = -1;
    else if (piV1->fSalary > piV2->fSalary) iRet = 1;
    else iRet = 0;
    return iRet;
}