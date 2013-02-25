#include "stdafx.h"


//Returns the first triangle number with over 500 divisors
int Euler12(){
	int iteration = 0, divisors = 0, testDivisor;
	int num = 0, minNum = (int) pow(2.0, 25);
	//The smallest nummber we could possibly find is 2^25
	//We can ignore all numbers  below that but we must
	//still find the iteration number inorder to compute
	//the triange number
	while ( num < minNum){
		iteration++;
		num += iteration;
	}

	while (divisors < 500){
		divisors = 0;
		iteration++;
		num += iteration;
		for (testDivisor = 1; testDivisor < sqrt((double) num); testDivisor++){
			if (num % testDivisor == 0){
				divisors += 2;
			}
		}
	}
	return num;
}