#include <stdio.h>
#define ARRAY_LEN 12

char acArray[ARRAY_LEN] = "Hello World";

ChangePointer(char **ppcVal);

int main(void)
{
	char* pcVal = &acArray[3];

	ChangePointer(&pcVal);

	printf("%c",*pcVal);

	return 0;
}


ChangePointer(char **ppcVal)
{
	if (**ppcVal == 'l')
	{
		(*ppcVal) += 2;
	}
}