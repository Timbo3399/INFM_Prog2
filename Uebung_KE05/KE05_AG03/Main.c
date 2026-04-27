#include <stdio.h>

#define ARRAY_LEN (10)

int main(void)
{
	int aiArray[ARRAY_LEN];

	for (int i = 0; i< ARRAY_LEN;i++)
	{
		aiArray[i] = 42;
	}

	for (int i = 0; i< Array_LEN;i++)
	{
		printf("%i\n", aiArray[i]);
	}

	printf("%d", aiArray[10]);
	return 0;
}