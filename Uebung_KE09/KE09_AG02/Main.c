#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    FILE *pIn = NULL;
    FILE *pOut = NULL;
    errno_t err;

    char acInput[260];
    char acLine[512];

    
    if (scanf_s("%259s", acInput, (unsigned)sizeof(acInput)) != 1)
    {
        return 1;
    }

    err = fopen_s(&pIn, acInput, "r");
    if (err != 0 || pIn == NULL)
    {
        printf("Kann Datei nicht öffnen: %s\n", acInput);
        return 1;
    }

    int phdCount = 0;

    while (fgets(acLine, (int)sizeof(acLine), pIn) != NULL)
    {
        
        size_t len = strlen(acLine);
        while (len > 0 && (acLine[len-1] == '\n' || acLine[len-1] == '\r'))
        {
            acLine[--len] = '\0';
        }

        
        char *token1 = strtok(acLine, ";");
        char *token2 = strtok(NULL, ";");
        char *token3 = strtok(NULL, ";");

        if (token1 != NULL && token2 != NULL && token3 != NULL)
        {
            printf("%s\n%s\n%s\n", token1, token2, token3);
            if (strcmp(token3, "PhD") == 0)
            {
                phdCount++;
            }
        }
    }

    fclose(pIn);

    
    err = fopen_s(&pOut, "NerdsRead.txt", "w");
    if (err == 0 && pOut != NULL)
    {
        fprintf(pOut, "%d\n", phdCount);
        fclose(pOut);
    }

    return 0;
}
