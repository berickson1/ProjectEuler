#include "stdafx.h"
#define SUNDAY 6
#define MONDAY 0
#define TUESDAY 1
#define WEDNESDAY 2
#define THURSDAY  3
#define FRIDAY 4
#define SATURDAY 5
//Add the specified number of days to the current day. Return 1 if the day is a monday
int isMonday(int * currDay, int addDays){
	if((*currDay = (*currDay + addDays) % 7) == MONDAY){
		return 1;
	}
	return 0;
}
//Returns the number of Sundays  that fell
//on the first day of the month in the 20th century
int Euler19(){
	int year = 1901;
	int currDay = MONDAY;
	int mondayCount = 1;
	for(year = 1901; year <= 2000; year++){
		//Jan
		mondayCount += isMonday(&currDay, 31);
		//Feb - 29 year divisble by 4 and (not a century year unless year is divible by 400)
		mondayCount += isMonday(&currDay, (year % 4 == 0  && (year % 1000 != 0  || year % 400 == 0)?29:28));
		//Mar
		mondayCount += isMonday(&currDay, 31);
		//Apr
		mondayCount += isMonday(&currDay, 30);
		//May
		mondayCount += isMonday(&currDay, 31);
		//Jun
		mondayCount += isMonday(&currDay, 30);
		//Jul
		mondayCount += isMonday(&currDay, 31);
		//Aug
		mondayCount += isMonday(&currDay, 31);
		//Sep
		mondayCount += isMonday(&currDay, 30);
		//Oct
		mondayCount += isMonday(&currDay, 31);
		//Nov
		mondayCount += isMonday(&currDay, 30);
		//Dec
		mondayCount += isMonday(&currDay, 31);
	}
	return mondayCount;
}