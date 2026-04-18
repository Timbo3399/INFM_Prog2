#include <stdio.h>
#define ARRAY_LEN (3)

struct Employee
{
	char cFirstName[15];
	char cLastName[15];
	unsigned int uiAge;
};

int main(void)
{
	struct Employee s_employee[ARRAY_LEN] = {0}; 

	for (int i = 0; i<ARRAY_LEN;i++)
	{
		printf("%i: FirstName",i);
		scanf_s("%14s", s_employee[i].cFirstName, sizeof(s_employee[i].cFirstName));
		printf("%i: LastName", i);
		scanf_s("%14s", s_employee[i].cLastName, sizeof(s_employee[i].cLastName));
		printf("%i: Age", i);
		scanf_s("%u", &s_employee[i].uiAge);
	}

	for (int i = 0; i<ARRAY_LEN; i++)
	{
		printf("FirstName: %s LastName: %s Age: %u\n", s_employee[i].cFirstName, s_employee[i].cLastName, s_employee[i].uiAge);
	}
	return 0;
}