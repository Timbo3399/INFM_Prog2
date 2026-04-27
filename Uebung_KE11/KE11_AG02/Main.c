#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_LEN 10
#define RAND_HIGH 10
#define RAND_LOW -10

typedef struct
{
   double dX;
   double dY;
   double dLen;
} sPoint_t;

static double drand(double low, double high);
static int Compare(const void* a, const void* b);

int main(void)
{
   // Seed once for the whole program and prepare data
   unsigned int uiSeed = 0U;
   sPoint_t aSP1[ARRAY_LEN] = { 0.0 };
   int i = 0;

   uiSeed = (unsigned int)time(NULL);
   srand(uiSeed);

   for (i = 0; i < ARRAY_LEN; i++)
   {
      aSP1[i].dX = drand(RAND_LOW, RAND_HIGH);
      aSP1[i].dY = drand(RAND_LOW, RAND_HIGH);
      aSP1[i].dLen = sqrt(aSP1[i].dX * aSP1[i].dX + aSP1[i].dY * aSP1[i].dY);
   }

   qsort(aSP1, ARRAY_LEN, sizeof(aSP1[0]), Compare);

   for (i = 0; i < ARRAY_LEN; i++)
   {
      printf("(%f/%f) Len:%f\n", aSP1[i].dX, aSP1[i].dY, aSP1[i].dLen);
   }

   return 0;
}

static double drand(double low, double high)
{
   // Return a double in [low, high]
   double dRange = 0.0;
   double dUnit = 0.0;
   double dResult = 0.0;

   dRange = high - low;
   dUnit = (double)rand() / (double)RAND_MAX;
   dResult = low + dRange * dUnit;

   return dResult;
}

static int Compare(const void* a, const void* b)
{
   int iReturn = 0; 
   const sPoint_t* psA = (const sPoint_t*)a;
   const sPoint_t* psB = (const sPoint_t*)b;
   double dDiff = 0.0;

   dDiff = psA->dLen - psB->dLen;
   if (dDiff < 0.0)
   {
      iReturn = -1;
   }
   if (dDiff > 0.0)
   {
      iReturn = 1;
   }
   return iReturn;
}
