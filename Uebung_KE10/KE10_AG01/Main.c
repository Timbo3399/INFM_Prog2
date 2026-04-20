#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Aufruf: %s seite1 seite2 seite3\n", argv[0]);
        return 1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    const double eps = 1e-9;

    if (a <= eps || b <= eps || c <= eps)
    {
        printf("Fehler: Alle Seiten müssen > 0 sein.\n");
        return 2;
    }

    if (! ( (a + b) > c + eps && (a + c) > b + eps && (b + c) > a + eps ))
    {
        printf("Fehler: Die Seitenlängen erfüllen nicht die Dreiecksungleichung.\n");
        return 3;
    }

    int ab = fabs(a - b) <= eps;
    int ac = fabs(a - c) <= eps;
    int bc = fabs(b - c) <= eps;

    if (ab && ac && bc)
    {
        printf("gleichseitig\n");
    }
    else if (ab || ac || bc)
    {
        printf("gleichschenklig\n");
    }
    else
    {
        printf("normal\n");
    }

    return 0;
}
