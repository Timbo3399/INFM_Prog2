#include <stdio.h>
#define Array_LEN (7)

int main(void)
{
	const double cdR1 = 100;
	const double cdR2 = cdR1;
	const double cdU1 = 10;

	double adR3[Array_LEN]= { 0, 10, 100, 1000, 10000, 100000, 1000000 };
	double adU2[Array_LEN];
	double adR23[Array_LEN];

	for (int i = 0; i < Array_LEN;i++)
	{
		if (adR3[i]==0)
		{
			adR23[i] = 0;
			continue;
		}
		adR23[i] = (cdR2 * adR3[i]) / (cdR2 + adR3[i]);
	}

	for (int i = 0; i<Array_LEN;i++)
	{
		adU2[i] = cdU1 * (adR23[i] / (cdR1 + adR23[i]));
		printf("Ohm:%lf, Spannung:%lf\n", adR23[i], adU2[i]);
	}

	return 0;
}