#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Main function to determine triangle type
int main(int iArgc, char* pacArgv[])
{
   // Declare local variables
   char cAppendix = ' ';
   int iReturn = 0;
   double dA = 0.0;
   double dB = 0.0;
   double dC = 0.0;
   const double cdEps = 1e-9;
   int bAb = 0;
   int bAc = 0;
   int bBc = 0;

   // Check argument count
   if (iArgc != 4)
   {
      printf("Call: %s Too few parameters\n", pacArgv[0]);
      iReturn = 1;
   }
   else
   {
      // Replace commas with dots in arguments
      for (int iI = 1; iI < iArgc; ++iI)
      {
         for (char* pcP = pacArgv[iI]; *pcP; ++pcP)
         {
            if (*pcP == ',')
            {
               *pcP = '.';
               cAppendix = '?';
            }
         }
      }

      // Parse arguments to doubles
      dA = atof(pacArgv[1]);
      dB = atof(pacArgv[2]);
      dC = atof(pacArgv[3]);

      // Check if sides are positive
      if (dA <= cdEps || dB <= cdEps || dC <= cdEps)
      {
         printf("not a triangle\n");
         iReturn = 2;
      }
      else
      {
         // Check triangle inequality
         if (!((dA + dB) > dC + cdEps && (dA + dC) > dB + cdEps && (dB + dC) > dA + cdEps))
         {
            printf("not a triangle\n");
            iReturn = 3;
         }
         else
         {
            // Check for equal sides
            bAb = fabs(dA - dB) <= cdEps;
            bAc = fabs(dA - dC) <= cdEps;
            bBc = fabs(dB - dC) <= cdEps;

            // Determine triangle type
            if (bAb && bAc && bBc)
            {
               printf("equilateral%c\n", cAppendix);
            }
            else
            {
               if (bAb || bAc || bBc)
               {
                  printf("isosceles%c\n", cAppendix);
               }
               else
               {
                  printf("scalene%c\n", cAppendix);
               }
            }
         }
      }
   }

   // Return result
   return iReturn;
}
