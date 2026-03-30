#include <stdio.h>
#define ARRAY_LEN (3)


struct Adress
{
	char cCity[10];
	unsigned int uiPLZ;
	char cStreetName[20];
};

struct Employee
{
	char cFirstName[15];
	char cLastName[15];
	unsigned int uiAge;
	struct Adress adress[1];
};


int main(void)
{
	struct Employee s_employee[ARRAY_LEN] = { 0 };

	for (int i = 0; i < ARRAY_LEN;i++)
	{
		printf("%i: FirstName: ", i);
		scanf_s("%14s", s_employee[i].cFirstName, sizeof(s_employee[i].cFirstName));
		printf("%i: LastName: ", i);
		scanf_s("%14s", s_employee[i].cLastName, sizeof(s_employee[i].cLastName));
		printf("%i: Age: ", i);
		scanf_s("%u", &s_employee[i].uiAge);
		printf("City: ");
		scanf_s("%s", s_employee[i].adress->cCity, sizeof(s_employee[i].adress->cCity));
		printf("PLZ: ");
		scanf_s("%u", &s_employee[i].adress->uiPLZ);
		printf("Street: ");
		scanf_s("%s", s_employee[i].adress->cStreetName, sizeof(s_employee[i].adress->cStreetName));
	}

	for (int i = 0; i < ARRAY_LEN; i++)
	{
		printf("FirstName: %s LastName: %s Age: %u\n City: %s PLZ: %i Street: %s", s_employee[i].cFirstName, s_employee[i].cLastName, s_employee[i].uiAge, s_employee[i].adress->cCity, s_employee[i].adress->uiPLZ, s_employee[i].adress->cStreetName);
	}
	return 0;
}