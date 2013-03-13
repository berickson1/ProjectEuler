#include "stdafx.h"
#include "MathUtil.h"

//Returns all sum of all the propor divisors of a given number
int calculateFactorSum(int num){
	int divisor;
	//1 is always a factor, the number isn't
	int sum = 1;
	for(divisor = 2; divisor <=  sqrt((float)num); divisor++){
		if(num % divisor == 0){
			//When # is a square (ie, 4, 9, 16), we dont want to double cound the factor
			if(num / divisor == divisor){
				sum += divisor;
			} else {
				sum += (num / divisor) + divisor;
			}
		}
	}
	return sum;
}