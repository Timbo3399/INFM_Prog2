#include <stdio.h>

unsigned int uiIsCorrectDate(unsigned int uiDay, unsigned int uiMonth, unsigned int uiYear);
unsigned int uiIsLeapYear(unsigned int uiYear);
unsigned int uiMaxDaysInMonth(unsigned int uiMonth, unsigned int uiYear);

int main(void)
{
	unsigned int uiTag;
	unsigned int uiMonat;
	unsigned int uiJahr;

	printf("Tag: ");
	scanf_s(" %u", &uiTag);

	printf("\nMonat: ");
	scanf_s("%u", &uiMonat);

	printf("\nJahr: ");
	scanf_s("%u", &uiJahr);

	switch (uiIsCorrectDate(uiTag, uiMonat, uiJahr))
	{
		case 1:
			printf("\nDas Datum ist korrekt.");
			break;
		case 2:
			printf("\nDer Monat ist nicht korrekt.");
			break;
		case 3:
			printf("\nDas Jahr ist nicht korrekt.");
			break;
		case 4:
			printf("\nDer Tag ist nicht korrekt.");
			break;
		default:
			printf("\nUnbekannter Fehler.");
			break;
	}
	return 0;
}

unsigned int uiIsCorrectDate(unsigned int uiDay, unsigned int uiMonth, unsigned int uiYear)
{
    if (uiMonth >= 1 && uiMonth <= 12)
	{
		if (uiYear >= 1900)
		{
			if (uiDay >= 1 && uiDay <= uiMaxDaysInMonth(uiMonth, uiYear))
			{
				return 1;
			}
			else
			{
				return 4;
			}
		}
		else
		{
			return 3;
		}
	}
	else
	{
		return 2;
	}

}

unsigned int uiIsLeapYear(unsigned int uiYear)
{
	if (uiYear % 4 == 0)
	{
		if (uiYear % 100 == 0)
		{
			if (uiYear % 400 == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

unsigned int uiMaxDaysInMonth(unsigned int uiMonth, unsigned int uiYear)
{
	switch (uiMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (uiIsLeapYear(uiYear))
		{
			return 29;
		}
		else
		{
			return 28;
		}
	default:
		return 0;
		break;
	}
}


/*
 * Bestimmen Sie mit Testwell CMT v(G), LOCpro und mittels eigener Rechnung c% Ihrer Funktionen
 * 
 *	| Funktion         | v(G) | LOCpro | Kommentare | c % |
 *	| ---------------- | ---- | ------ | ---------- | --- |
 *	| main             | 5    | 23     | 0          | 0%  |
 *	| uiIsCorrectDate  | 6    | 9      | 0          | 0%  |
 *	| uiIsLeapYear     | 4    | 10     | 0          | 0%  |
 *	| uiMaxDaysInMonth | 5    | 20     | 0          | 0%  |
 * 
 */