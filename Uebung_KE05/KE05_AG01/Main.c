#include <stdio.h>
typedef	enum { CME, EIM, INFM, MTM, MRM } EMI;

int main(void)
{
	EMI a = CME; 

	switch (a)
	{
	case 0:
		printf("Communication and Media Engineering");
		break;
	case 1:
		printf("Elektrotechnik");
		break;
	case 2:
		printf("Informatik");
		break;
	case 3:
		printf("Medizintechnik");
		break;
	case 4:
		printf("Mechatronik und Robotik");
		break;
	default:
		break;

	}
	return 0;
}