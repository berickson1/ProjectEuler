#include "stdafx.h"
//Returns all sum of all the propor divisors of a given number
int calculateFactorSum(int num){
	int divisor;
	//1 is always a factor, the number isn't
	int sum = 1;
	for(divisor = 2; divisor <=  sqrt((float)num); divisor++){
		if(num % divisor == 0){
			sum += (num / divisor) + divisor;
		}
	}
	return sum;
}

//Returns the sum of all amicable numbers under 10000
int Euler21(){
	int currNum, factorSum;
	int sum = 0;
	for(currNum = 1; currNum < 10000; currNum++){
		factorSum = calculateFactorSum(currNum);
		//Only count sums when the factor sum is less than current number to
		//prevent double counting, this also ensures that we do not count numbers
		//over 10,000
		if (factorSum < currNum && calculateFactorSum(factorSum) == currNum){
			sum += factorSum + currNum;
		}
	}
	return sum;
}