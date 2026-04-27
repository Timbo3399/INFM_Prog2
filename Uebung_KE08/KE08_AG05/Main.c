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
	float afSalary[ARRAY_LEN] = { 5.2F, 1.1F, 9.9F, 3.3F, 7.7F, 2.2F, 8.8F, 6.6F, 4.4F, 0.5F };

	sMonthlySalary_t asMonthlySalary[ARRAY_LEN] = {
        {1001, 3200.5F},
        {1002, 2100.0F},
        {1003, 4500.0F},
        {1004, 1800.0F},
        {1005, 3900.0F},
        {1006, 2750.0F},
        {1007, 5100.0F},
        {1008, 3050.0F},
        {1009, 1500.0F},
        {1010, 4200.0F}
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