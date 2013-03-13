#include "stdafx.h"

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