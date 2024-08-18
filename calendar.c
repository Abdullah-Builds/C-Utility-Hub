#include <stdio.h>

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] =
	{
		" ",
		"\n\n\nJanuary",
		"\n\n\nFebruary",
		"\n\n\nMarch",
		"\n\n\nApril",
		"\n\n\nMay",
		"\n\n\nJune",
		"\n\n\nJuly",
		"\n\n\nAugust",
		"\n\n\nSeptember",
		"\n\n\nOctober",
		"\n\n\nNovember",
		"\n\n\nDecember"};

int inputYear(void)
{
	int year;

	printf("Please enter a year (example: 1999) : ");
	scanf("%d", &year);
	return year;
}

int inputMonth(void)
{
	int month;

	printf("Please enter a month (example: 12) : ");
	scanf("%d", &month);
	return month;
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1.) / 4.0;
	d2 = (year - 1.) / 100.;
	d3 = (year - 1.) / 400.;
	daycode = (year + d1 - d2 + d3) % 7;
	return daycode;
}

int determinedaycodeMonth(int year, int month)
{
	int daycode;
	int d1, d2, d3;

	if (month < 3)
	{
		month += 12;
		year--;
	}

	d1 = (year - 1) / 4;
	d2 = (year - 1) / 100;
	d3 = (year - 1) / 400;
	daycode = (2 + 2 * month + 3 * (month + 1) / 5 + year + d1 - d2 + d3) % 7;

	return daycode;
}

int determineleapyear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		days_in_month[2] = 29;
		return 1;
	}
	else
	{
		days_in_month[2] = 28;
		return 0;
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for (month = 1; month <= 12; month++)
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Correct the position for the first date
		for (day = 1; day <= 1 + daycode * 5; day++)
		{
			printf(" ");
		}

		// Print all the dates for one month
		for (day = 1; day <= days_in_month[month]; day++)
		{
			printf("%2d", day);

			// Is day before Sat? Else start next line Sun.
			if ((day + daycode) % 7 > 0)
				printf("   ");
			else
				printf("\n ");
		}
		// Set position for next month
		daycode = (daycode + days_in_month[month]) % 7;
	}
}

void calendarMonth(int year, int month, int daycode)
{
	int day;

	printf("%s", months[month]);
	printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Correct the position for the first date
	for (day = 1; day <= 1 + daycode * 5; day++)
	{
		printf(" ");
	}

	// Print all the dates for one month
	for (day = 1; day <= days_in_month[month]; day++)
	{
		printf("%2d", day);

		// Is day before Sat? Else start next line Sun.
		if ((day + daycode) % 7 > 0)
			printf("   ");
		else
			printf("\n ");
	}
	// Set position for next month
	daycode = (daycode + days_in_month[month]) % 7;
}

int main(void)
{
	int year, month, daycode, leapyear, choice;

	printf("\nPrint a whole year calendar or only a month : \n");
	printf("For whole year, Press 1.\n");
	printf("For just a month of a year, Press 2.\n");
	scanf("%d", &choice);

	do
	{
		switch (choice)
		{
		case 1:
			year = inputYear();
			daycode = determinedaycode(year);
			determineleapyear(year);
			calendar(year, daycode);
			printf("\n");
			break;

		case 2:
			year = inputYear();
			month = inputMonth();
			daycode = determinedaycodeMonth(year, month);
			determineleapyear(year);
			calendarMonth(year, month, daycode);
			printf("\n");
			break;

		default:
			printf("\n\nInvalid choice! Try Again.\n");	
		}
	} while (choice < 1 || choice > 2);
}