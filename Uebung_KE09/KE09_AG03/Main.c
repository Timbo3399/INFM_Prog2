#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DOSHOWOUTPUT 0
// Multiple lines in a function macro: / is must be used at the end of the line
#define SMALLER10(Value1,Value2) (int)((((int)(Value1) + 10) < (int)(Value2)) ? \
 (1) : (0))

#define POWER3(a) ((a) * (a) * (a))

//Welcher Dateityp entsteht jetzt beim Übersetzen des Programms? (Hinweis: Schauen Sie in dem
//Verzeichnis nach, wo vormals die exe - Datei hinterlegt wurde : Debug oder Release).
//Eine .i Datei entsteht, die den Präprozessoroutput enthält.

//Erklären Sie, warum beim Übersetzen ein Linker-Fehler entsteht?
//Öffnen Sie die erstellte Datei.Erklären Sie, was aus der ursprünglichen Zeile #include
//<conio.h> umgewandelt wurde.
//Die Zeile #include <conio.h> wurde durch den Präprozessor durch den Inhalt der conio.h Datei ersetzt.

//Was ist mit den Kommentaren passiert und warum? 
//Die Kommentare wurden vom Präprozessor entfernt, da sie für die weitere Verarbeitung des Codes nicht mehr benötigt werden.

//Ändern Sie den Wert des defines DOSHOWOUTPUT auf 0. Was hat sich jetzt bei einem einem
//erneuten Präprozessordurchlauf geändert ?
//Der Code innerhalb der #if DOSHOWOUTPUT Anweisung wird jetzt nicht mehr in die Ausgabe übernommen, da DOSHOWOUTPUT auf 0 gesetzt wurde. Das bedeutet, dass die Zeile printf("Hello user!\n"); nicht mehr im Präprozessoroutput enthalten ist.

//Wie wird die Codegenerierung abhängig von #defines genannt? 
//Die Codegenerierung abhängig von #defines wird als bedingte Kompilierung bezeichnet.

int main(void)
{
	int iX = 0;
	int iY = 10;
	printf("Hello World!\n");
#if DOSHOWOUTPUT
	printf("Hello user!\n");
#endif
	if (SMALLER10(iX, iY))
	{
		printf("First Value + 10 is smaller than second Value!\n");
	}
	iY = POWER3(iX);
	// Wait for user interaction
	_getch();
	return EXIT_SUCCESS;

   return 0;
}
