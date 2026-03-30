#include <stdio.h>

int main(void)
{
	char acFirstName[20];

	//Example
	acFirstName[0] = 'T';
	acFirstName[1] = 'i';
	acFirstName[2] = 'm';
	acFirstName[3] = '0';

	printf("%s", acFirstName);

	/*
	 * Was fällt Ihnen dabei auf?
	 * Die restlichen Felder des Arrays werden mit random werten gefüllt
	 * 
	 * Wann beendet die printf-Funktion die Ausgabe der Zeichen auf der Konsole?
	 * Nach dem End of String Zeichen 0x00
	 */


	return 0;
}