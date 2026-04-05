#include <stdio.h>
#define ARRAY_LEN (3)


struct Address
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
	struct Address address[1];
};


int main(void)
{
	struct Employee s_employee[ARRAY_LEN] = { 0 };

	for (int i = 0; i < ARRAY_LEN;i++)
	{
		printf("%i: FirstName: ", i);
		scanf_s("%14s", s_employee[i].cFirstName, sizeof(s_employee[i].cFirstName));
		printf("\n%i: LastName: ", i);
		scanf_s("%14s", s_employee[i].cLastName, sizeof(s_employee[i].cLastName));
		printf("\n%i: Age: ", i);
		scanf_s("%u", &s_employee[i].uiAge);
		printf("\n%i: City: ", i);
		scanf_s("%s", s_employee[i].address->cCity, sizeof(s_employee[i].address->cCity));
		printf("\n%i: PLZ: ", i);
		scanf_s("%u", &s_employee[i].address->uiPLZ);
		printf("\n%i: Street: ", i);
		scanf_s("%s", s_employee[i].address->cStreetName, sizeof(s_employee[i].address->cStreetName));
	}

	for (int i = 0; i < ARRAY_LEN; i++)
	{
		printf("\nFirstName: %s LastName: %s Age: %u\nCity: %s PLZ: %i Street: %s\n", s_employee[i].cFirstName, s_employee[i].cLastName, s_employee[i].uiAge, s_employee[i].address->cCity, s_employee[i].address->uiPLZ, s_employee[i].address->cStreetName);
	}

	printf("\nSize of Employee: %i\n",sizeof(s_employee));
	printf("\nSize of Address: %i\n", sizeof(s_employee->address));

	return 0;
}