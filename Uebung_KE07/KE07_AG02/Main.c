#include <stdio.h>
#define ARRAY_LEN 5

int aiTestArray[ARRAY_LEN] = { 1, 2, 3, 4, 5 };

int* piValInArray = &aiTestArray[2];

//Was wird jetzt ausgegeben? 
//nichts sinnvolles, da das Array nur zwei weitere sinnvolle inhalte hat und der "6." Wert ein random wert aus dem arbeitsspeicher ist der als int interpretiert wird

int main(void)
{
	printf("%i\n", *piValInArray);
	piValInArray++;
	piValInArray++;
	piValInArray++;
	printf("%i", *piValInArray);
	return 0;
}