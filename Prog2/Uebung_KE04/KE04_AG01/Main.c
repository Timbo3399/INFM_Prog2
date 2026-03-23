#include <stdio.h>

main(void)
{
	int iVarA;
	printf("Enter iVarA: ");
	scanf_s("%d", &iVarA);

	//1.1
	if(iVarA > 7)
	{
		printf("Wert von iVarA ist groesser als 7");
	}

	//1.2
	int iVarB;
	printf("Enter iVarB: ");
	scanf_s("%d", &iVarB);

	if (iVarB > 7)
	{
		printf("Wert von iVarB ist groesser als 7");
	}
	else
			{
		printf("Wert von iVarB ist kleiner oder gleich 7");
	}

	//1.3
	int iVarC;
	int iVarD;
	printf("Enter iVarC: ");
	scanf_s("%d", &iVarC);

	switch (iVarC)
	{
		case 0:
			iVarD = -5;
			break;
		case 1:
			iVarD = 47711;
			break;
		case 2:
			iVarD = 5;
			break;
		case 3:
			iVarD = 3;
			break;
		case 4:
			iVarD = 73;
			break;
		default:
			iVarD = 42;
			break;
	}
	printf("Wert von iVarD: %d", iVarD);

	//1.4
	printf("Enter iVarC: ");
	scanf_s("%d", &iVarC);

	switch (iVarC)
	{
	case 0:
		iVarD = -99;
	case 1:
		iVarD = -99;
		break;
	case 2:
		iVarD = 3;
		break;
	case 3:
		iVarD = 4;
	case 4:
		iVarD = 5;
	default:
		iVarD = 42;
		break;
	}
	printf("Wert von iVarD: %d", iVarD);

	//1.5
	int iCounter = 0;
	for (iCounter; iCounter < 10; iCounter++)
	{
		printf("iCounter in ForSchleife: %d\n", iCounter);
	}
	printf("iCounter nach ForSchleife: %d\n", iCounter);

	iCounter = 0;
	while (iCounter < 10)
	{
		printf("iCounter in WhileSchleife: %d\n", iCounter);
		iCounter++;
	}
	printf("iCounter nach WhileSchleife: %d\n", iCounter);


	//1.6
	iCounter = 0;
	do
	{
		printf("iCounter in DoWhileSchleife: %d\n", iCounter);
		iCounter++;
	} while (iCounter < 9);
	printf("iCounter nach DoWhileSchleife: %d\n", iCounter);
}