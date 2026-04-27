#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

// Explanation of runtime difference:
// Printing to the console is orders of magnitude slower than doing pure computations.
// Each printf causes formatting work and system I/O (context switches / buffer handling).
// Therefore CalcPrintSqrt() spends most time in I/O, making it much slower than CalcSqrt().

double CalcSqrt(void);
double CalcPrintSqrt(void);

// main is first according to project style rules
int main(void)
{
   clock_t uiStart = (clock_t)0;
   clock_t uiEnd = (clock_t)0;
   double dElapsed = 0.0;
   double dChecksum = 0.0;

   uiStart = clock();
   dChecksum = CalcSqrt();
   uiEnd = clock();
   dElapsed = (double)(uiEnd - uiStart) / (double)CLOCKS_PER_SEC;
   printf("CalcSqrt: elapsed = %.6f s, checksum = %.10f\n", dElapsed, dChecksum);

   uiStart = clock();
   dChecksum = CalcPrintSqrt();
   uiEnd = clock();
   dElapsed = (double)(uiEnd - uiStart) / (double)CLOCKS_PER_SEC;
   printf("CalcPrintSqrt: elapsed = %.6f s, checksum = %.10f\n", dElapsed, dChecksum);

   return 0;
}

double CalcSqrt(void)
{
   int i = 0;
   double dResult = 0.0;
   double dSum = 0.0;

   for (i = 1; i <= 10000; ++i)
   {
      dResult = sqrt((double)i);
      dSum += dResult;
   }

   return dSum;
}

double CalcPrintSqrt(void)
{
   int i = 0;
   double dResult = 0.0;
   double dSum = 0.0;

   for (i = 1; i <= 10000; ++i)
   {
      dResult = sqrt((double)i);
      dSum += dResult;
      printf("%d -> %.10f\n", i, dResult);
   }

   return dSum;
}
