#include <stdio.h>

void main()
{
	double dR;
	scanf("%lf", &dR);
	printf("Das Volumen der Kugel mit Radius %f ist: %f\n", dR, calculateVolume(dR));
}

double calculateVolume(double dR)
{
	const double dPi = 3.14159;
	return (4.0 / 3.0) * dPi * pow(dR,3);
}