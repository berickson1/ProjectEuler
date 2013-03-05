#include "stdafx.h"

//Returns the number of characters in the numbers 1 - 1000 written out
int Euler17(){
	int sum = 0;
	//We can group numbers together since they will repeat the same number of times
	//
	//one - one, twenty-one, thirty-one, ..., ninety-one, one hundred
	//two - two, twenty-two, thirty-two, ..., ninety-two, two hundred
	//See a pattern? all single digit numbers have the same number of occurrences 
	//100 times in the hundreds place and nine times per hundred
	int ones = 100 + 9*10;
	
	//Ten, eleven, twelve... - once per hundred
	int teens = 10;

	//Hundred occurs in all but the first 99 and last number
	int hundred = 900;

	//Ands only occur after a hundreds when there is something in the tens or ones place
	int and = hundred - 9;

	//tens - twenty, thirty,... - ten times per hundred
	int ten = 10 * 10;

	//Ones place - 36 chars
	sum += 36 * ones;

	//Teens - 70 chars
	sum += 70 * teens;

	//Hundred - 7 chars
	sum += 7 * hundred;

	//And - 3 chars
	sum += 3 * and;

	//tens - 46 chars
	sum += 46 * ten;
	
	//one thousand - 11 chars
	sum += 11;

	return sum;

}