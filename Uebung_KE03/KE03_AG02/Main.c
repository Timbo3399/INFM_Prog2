#include <stdio.h>

int TestGlobal(void);
int iVar = 42;

//„Bei namensgleichen Variablen (Namenskonflikt) verwendet der Compiler die Variable mit dem globalen Gültigkeitsbereich!“
main(void)
{
	TestGlobal();
	printf("iVar = %d\n", iVar);
	printf("TestGlobal = %d\n", TestGlobal());
}

int TestGlobal(void)
{
	int iVar = 72;
	iVar++;
	printf("iVar = %d\n", iVar);
	return iVar;
}

// * Welche Variable verwendet Ihr Programm in main und in TestGlobal?
// * iVar = 42in main und = 72 in TestGlobal;