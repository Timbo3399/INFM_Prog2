#include <stdio.h>

double CalcVolumeSphere(double dR);
double CalcAreaCircle(double dR);

const double dPi = 3.1415926535897932384626433832795;

void main(void)
{
	double dR;
	double dResultSphere;
	double dResultCircle;

	dR = -1;
	dResultSphere = CalcVolumeSphere(dR);
	dResultCircle = CalcAreaCircle(dR);
	printf("Volume Sphere with radius %f = %f\n",dR,dResultSphere);
	printf("Volume Circle with radius %f = %f\n", dR, dResultCircle);

	dR = 0;
	dResultSphere = CalcVolumeSphere(dR);
	dResultCircle = CalcAreaCircle(dR);
	printf("Volume Sphere with radius %f = %f\n", dR, dResultSphere);
	printf("Volume Circle with radius %f = %f\n", dR, dResultCircle);

	dR = 1;
	dResultSphere = CalcVolumeSphere(dR);
	dResultCircle = CalcAreaCircle(dR);
	printf("Volume Sphere with radius %f = %f\n", dR, dResultSphere);
	printf("Volume Circle with radius %f = %f\n", dR, dResultCircle);

	dR = 100;
	dResultSphere = CalcVolumeSphere(dR);
	dResultCircle = CalcAreaCircle(dR);
	printf("Volume Sphere with radius %f = %f\n", dR, dResultSphere);
	printf("Volume Circle with radius %f = %f\n", dR, dResultCircle);
}

double CalcVolumeSphere(double dR)
{
	double dResult;
	dResult = (4.0 / 3.0) * dPi * dR * dR * dR;
	return dResult;
}

double CalcAreaCircle(double dR)
{
	double dResult;
	dResult = dPi * dR * dR;
	return dResult;
}

// * Stimmen Ihre implementierten Gleichungen?
// * Ja, bis auf die -1, da eine fläche nicht negativ sein kann.
// * 
// * Ein Radius von -1 soll nach Definition nicht möglich sein.
// * Warum fällt dies bei der Berechnung von A nicht sofort auf?
// * Es fällt nicht auf, da Minus mal Minus Plus ergebt und somit das Ergebnis positiv ist.


