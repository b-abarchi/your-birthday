//-------------------------------------
// Bello Abarchi
// date of 10/1/2017
//PURPOSE WORD BOARD GAME 
//-------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#define CLS system("cls")
#define PAUSE system("pause")
typedef struct {
	int month;
	int day;
	int year;
}DATE;

void getDate(DATE *);
void printDate(DATE);

main() {
	DATE birthday;
	DATE yourBirthday;
	DATE christmasDay;
	DATE exam1Due;


	getDate(&birthday);
	printf("My birthday is ");
	printDate(birthday);

	PAUSE;
} // end of main

void getDate(DATE *date) {
	char invalid = 'Y';

	while (invalid == 'Y') {
		invalid = 'N';
		CLS;
		printf("Enter the month: ");
		scanf("%i", &date->month);

		printf("Enter the day..: ");
		scanf("%i", &date->day);

		printf("Enter the year.: ");
		scanf("%i", &date->year);

		// Validate The date
		if (date->month > 12 || date->month < 1) {
			printf("Invalid month between 1 and 12 only!\n");
			PAUSE;
			invalid = 'Y';
		} // end if

		if (date->year < 1000 || date->year >  9999) {
			printf("Invalid YEAR between 1000 and 9999 only!\n");
			PAUSE;
			invalid = 'Y';
		}
		switch (date->month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (date->day < 1 || date->day > 31) {
				printf("Invalid Day between 1 and 31 only!\n");
				PAUSE;
				invalid = 'Y';
			}// end if
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date->day < 1 || date->day > 30) {
				printf("Invalid Day between 1 and 30 only!\n");
				PAUSE;
				invalid = 'Y';
			}// end if
			break;
		case 2:
			if (date->year % 4 == 0 &&
				(date->day < 1 || date->day > 29)) {
				printf("Invalid Day between 1 and 29 only!\n");
				PAUSE;
				invalid = 'Y';
			}
			else if (date->year % 4 != 0 &&
				(date->day < 1 || date->day > 28)) {
				printf("Invalid Day between 1 and 28 only!\n");
				PAUSE;
				invalid = 'Y';
			}
		} // end switch
	}// end while
} // end function getDate

void printDate(DATE date) {
	printf("%2i/%2i/%4i\n",
		date.month, date.day, date.year);
} // end printDate