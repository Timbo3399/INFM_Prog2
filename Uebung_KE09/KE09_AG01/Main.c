#include <stdio.h>
#include <errno.h>

int main(void)
{
	FILE* pFMessage = NULL; // pointer to file
	errno_t iErrorCode;

	char acInput[260];
	char acLine[512];


	if (scanf_s("%259s", acInput, (unsigned)sizeof(acInput)) != 1)
	{
		printf("Eingabefehler\n");
		return 1;
	}

	iErrorCode = fopen_s(&pFMessage, acInput, "r");

	if (iErrorCode == 0 && pFMessage != NULL)
	{

		while (fgets(acLine, (int)sizeof(acLine), pFMessage) != NULL)
		{
			printf("%s", acLine);
		}

		fclose(pFMessage);
		pFMessage = NULL;
	}
	else
	{
		printf("Kann Datei nicht öffnen: ErrorCode: %i\n", iErrorCode);
		return 1;
	}

	return 0;
}
