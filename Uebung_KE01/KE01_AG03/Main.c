#include <stdio.h>

// Main function
int main(void)
{
   // Declare variables
   char cVal = 'x';
   short int siVal = 1;
   int iVal = 123456;
   float fVal = 1.23F;
   double dVal = 3.14156;

   // Print values
   printf("%c\n", cVal);
   printf("%i\n", siVal);
   printf("%i\n", iVal);
   printf("%.2f\n", fVal);
   printf("%f\n", dVal);

   // Declare constant
   const int ciVal = 5;

   // Print constant
   printf("%i\n", ciVal);

   // What happens when compiling if you do not assign a value to the constant variable definition?
   // Warning: Local Variable 'ciVal' is uninitialized

   // Is it possible to change the value afterwards?
   // No, since ciVal is declared as const, its value cannot be changed after initialization. Attempting to change the value would lead to a compilation error.

   // Return success
   return 0;
}