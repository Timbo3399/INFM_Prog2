#include <stdio.h>
#include <math.h>

double calculateVolume(double dR);

void main()
{
	double dR = 1.5;
	printf("Das Volumen der Kugel mit Radius %f ist: %f\n", dR, calculateVolume(dR));
}

double calculateVolume(double dR)
{
	const double dPi = 3.14159;
	double dVolume = (4.0 / 3.0) * dPi * pow(dR, 3.0);
	return dVolume;
}

//mit #include <math.h>
//-1 ergebt -4.188787
//0 ergebt 0
//1 ergebt 4.188787
//1.5 ergebt 14.137155

//ohne #include <math.h>
//-1 ergebt -64808.907307 
//0 ergebt 0 
//1 ergebt -64808.907307 
//1.5 ergebt 6500.996907
//Da die Funktion pow() ohne die Einbindung der math.h-Bibliothek nicht definiert ist und deshalb zu einem undefinierten Verhalten führt.