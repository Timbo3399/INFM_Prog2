#include <stdio.h>
#include "tax.h"

int main(void)
{
   // Declare local variables
   double dNet = 0.0;
   double dVat = 0.0;
   double dGross = 0.0;

   // Prompt user for net value input
   printf("Enter net value: ");
   scanf_s("%lf", &dNet);

   // Get value added tax
   dVat = GetValueAddedTax();
   // Calculate gross value
   dGross = dNet * (1.0 + dVat);

   // Print value added tax
   printf("Value added tax: %.2f %%\n", dVat * 100);
   // Print gross value
   printf("Gross value: %.2f EUR\n", dGross);

   // Return success
   return 0;
}