#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    char cAppendex = ' ';

    if (argc != 4)
    {
        printf("Aufruf: %s Zu wenig Parameter\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        for (char* p = argv[i]; *p; ++p)
        {
            if (*p == ',')
            {
                *p = '.';
                cAppendex = '?';
            }
        }
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    const double eps = 1e-9;

    if (a <= eps || b <= eps || c <= eps)
    {
        printf("kein Dreieck\n");
        return 2;
    }

    if (! ( (a + b) > c + eps && (a + c) > b + eps && (b + c) > a + eps ))
    {
        printf("kein Dreieck\n");
        return 3;
    }

    int ab = fabs(a - b) <= eps;
    int ac = fabs(a - c) <= eps;
    int bc = fabs(b - c) <= eps;

    if (ab && ac && bc)
    {
        printf("gleichseitig%c\n", cAppendex);
    }
    else if (ab || ac || bc)
    {
        printf("gleichschenklig%c\n", cAppendex);
    }
    else
    {
        printf("normal%c\n", cAppendex);
    }

    return 0;
}
