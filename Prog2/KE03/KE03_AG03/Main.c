#include <stdio.h>
#include <conio.h>
#include <Utilities.h>

main(void)
{
	printf("Input iVar:");
	int iVar = _getch();
	printf("\n");
	printf("iVar %c\n", iVar);
	printf("iVar as ASCII = %d\n", iVar);

	printf("Input iVar2:");
	int iVar2 = _getch();
	printf("\n");

	_clrscr();

	printf("GoTo X: %i Y: %i",iVar2 % 10,iVar2 % 10);

	_gotoxy(iVar2 % 10, iVar2 % 10);



}

