#include "stdafx.h"


//Returns the first triangle number with over 500 divisors
int Euler12(){
	int iteration, divisors = 0, testDivisor;
	int num = 0;
	for (iteration = 1; divisors < 500; iteration++){
		divisors = 0;
		num += iteration;
		for (testDivisor = 1; testDivisor < sqrt((double) num); testDivisor++){
			if (num % testDivisor == 0){
				divisors += 2;
			}
		}
	}
	return num;
}