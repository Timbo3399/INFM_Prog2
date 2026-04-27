#include <stdlib.h>
#include <stdio.h>

int main(int iArgc, char* pacArgv[])
{
   int iReturn = 0;
   double dVal = 0.0;
   char* pcEnd = NULL;

   if (iArgc < 2)
   {
      printf("Zu wenig Übergabeparameter");
      iReturn = 1;
   }
   else if (iArgc > 2)
   {
      printf("Zu viele Übergabeparameter");
      iReturn = 1;
   }
   else
   {
      dVal = strtod(pacArgv[1], &pcEnd);
      if (pcEnd == pacArgv[1] || *pcEnd != '\0')
      {
         printf("Keine Fließkommazahl");
         iReturn = 1;
      }
      else
      {
         printf("Fließkommazahl");
         iReturn = 0;
      }
   }

   return iReturn;
}
