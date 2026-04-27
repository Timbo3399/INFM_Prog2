#include <math.h>
#include <stdio.h>

int main(int iArgc, char* pacArgv[])
{
   const double cdPi = 3.14159265358979323846;
   double dX;
   double dY;
   if (iArgc == 3)
   {
      dX = atof(pacArgv[1]);
      dY = atof(pacArgv[2]);
   }
   else
   {
      printf("Enter X and Y values: \nX: ");
      scanf_s("%lf", &dX);
      printf("Y: ");
      scanf_s("%lf", &dY);
   }


   double dLen = sqrt(dX * dX + dY * dY);
   double dAngle1 = atan(dY / dX) * 180.0 / cdPi;
   double dAngle2 = atan2(dY, dX) * 180.0 / cdPi;

   printf("Length: %lf\n", dLen);
   printf("atan: %lf\n", dAngle1);
   printf("atan2: %lf\n", dAngle2);

   return 0;
}
