#include <stdio.h>
#include "tax.h"

int main(void)
{
    double net = 0.0;
    double vat = 0.0;
    double gross = 0.0;

    printf("Nettowarenwert eingeben: ");
    scanf_s("%lf", &net);

    vat = GetValueAddedTax();
    gross = net * (1.0 + vat);

    printf("Mehrwertsteuer: %.2f %%\n", vat * 100);
    printf("Bruttowarenwert: %.2f EUR\n", gross);

    return 0;
}