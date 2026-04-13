#include <stdio.h>
#define ARRAYL_LEN 7

typedef struct Address
{
	char acLastName[30];
	char acFirstName[30];
	char acStreet[40];
	unsigned int uiZipCode;
	char acTown[40];
}sAddress_t;
typedef sAddress_t* psAddress_t;



int main(void)
{
	sAddress_t asAllAddress[ARRAYL_LEN] = {0};
	psAddress_t psAdress = asAllAddress;

	for (int i = 0;i<ARRAYL_LEN;i++)
	{
		psAdress->uiZipCode += i;
		psAdress++;
	}

	for (int i = 0;i < ARRAYL_LEN;i++)
	{
		printf("%i\n",asAllAddress[i].uiZipCode);
	}
	return 0;
}