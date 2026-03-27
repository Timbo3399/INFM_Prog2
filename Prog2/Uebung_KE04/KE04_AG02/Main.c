#include <stdio.h>

unsigned int uiIsCorrectDate(unsigned int uiDay, unsigned int uiMonth, unsigned int uiYear);
unsigned int uiIsLeapYear(unsigned int uiYear);
int iMaxDaysInMonth(unsigned int uiMonth, unsigned int uiYear);

void main(void)
{
	unsigned int uiTag;
	unsigned int uiMonat;
	unsigned int uiJahr;

	printf("Tag: ");
	scanf_s("%u", &uiTag);

	printf("\nMonat: ");
	scanf_s("%u", &uiMonat);

	printf("\nJahr: ");
	scanf_s("%u", &uiJahr);

	printf("\nDas Datum ist %s.\n", uiIsCorrectDate(uiTag, uiMonat, uiJahr) ? "korrekt" : "nicht korrekt");
}

unsigned int uiIsCorrectDate(unsigned int uiDay, unsigned int uiMonth, unsigned int uiYear)
{
	if (1 <= uiMonth <=12)
	{
		if (1900 <= uiYear)
		{
			if (1<= uiDay <= iMaxDaysInMonth(uiMonth, uiYear))
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
			return 0;
		}
	}
	else
	{
		return 0;
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

int iMaxDaysInMonth(unsigned int uiMonth, unsigned int uiYear)
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