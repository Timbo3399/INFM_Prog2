#include <stdio.h>
#include <conio.h>
#include <Utilities.h>

main(void)
{
	int iVar = _getch();
	printf("iVar %d\n", iVar);
	printf("iVar as ASCII = %c\n", iVar);

	int iVar2 = _getch();

	_clrscr();

	_gotoxy(iVar, iVar2);



}