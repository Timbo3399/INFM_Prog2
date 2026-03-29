#include <stdio.h>

int main (void)
{
	int iValh;
	int iValb;

	printf("Hoehe: ");
	scanf_s("%i", &iValh);

	printf("\nBreite: ");
	scanf_s("%i", &iValb);

	if (iValh % 2 == 0 || iValb %2 == 0)
	{
		printf("Fehlerhafte Eingabe Hoehe: %i oder Breite: %i ist gerade", iValh, iValb);
		return 0;
	}


	printf("Figur 1\n");
	/*	Figur 1
		ABBBB
		AABBB
		AAABB
		AAAAB
		AAAAA 
	 */
	for (int i = 0; i < iValh; i++)
	{
		for (int j = 0; j <iValb; j++ )
		{
			printf("%c", (j <= i) ? 'A' : 'B');
		}
		printf("\n");
	}

	/*	Figur 2
		ABBBB
		AABBB
		AAABB
		AABBB
		ABBBB 
	 */

	printf("Figur 2\n");

	for (int i = 0; i < iValh; i++)
	{
		for (int j = 0; j < iValb; j++)
		{
			printf("%c", (j <= (i <= iValh / 2 ? i : iValh - 1 - i)) ? 'A' : 'B');
		}
		printf("\n");

	}
	return 0;
}