#include <stdio.h>
#define ARRAY_LEN 5

void OutputString1(void);

void OutputString2(void);

void OutputString3(void);

void OutputString4(void);

void OutputString5(void);

int main(void)
{
	void (*os[ARRAY_LEN])(void) = { OutputString1 , OutputString2 , OutputString3 , OutputString4 , OutputString5 };

	for (int i = 0; i < ARRAY_LEN; i++)
	{
		os[i]();
	}

	printf("\nNeue Zuweisungen\n\n");

	os[0] = OutputString2;
	os[1] = OutputString3;
	os[2] = OutputString4;
	os[3] = OutputString5;
	os[4] = OutputString1;

	for (int i = 0; i < ARRAY_LEN; i++)
	{
		os[i]();
	}

	return 0;
}

void OutputString1(void)
{
	printf("OutputString1 called\n");
}

void OutputString2(void)
{
	printf("OutputString2 called\n");
}

void OutputString3(void)
{
	printf("OutputString3 called\n");
}

void OutputString4(void)
{
	printf("OutputString4 called\n");
}

void OutputString5(void)
{
	printf("OutputString5 called\n");
}