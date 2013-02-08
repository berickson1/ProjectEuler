#include "stdafx.h"


int *fibArr;
int fibArrCount = 0;
int fibArrSize = 0;
//Returns the sum of  all even fibonacci numbers < 4 million
int Euler2(){
	int i = 1;
	int currFib;
	int sum = 0;
	while ((currFib = computeFib(i))  < 4000000){
		//If even, add to sum
		if(currFib % 2 == 0){
			sum += currFib;
		}
		i++;
	}

	free(fibArr);
	return sum;
}

//Returns the Fibinacci number in position num
int computeFib(int num){
	//Allocate some space for fib  cache
	if (fibArr == NULL){
		fibArrSize = 2;
		fibArr = (int *) malloc(sizeof(int) * fibArrSize);
		fibArr[0] = 1;
		fibArr[1] = 1;
		fibArrCount = 2;
	}
	//If its already in the cache, return it
	if (num <= fibArrCount){
		return fibArr[num - 1];
	}
	//Compute and store the Fibinacci number
	
	//Do we need more space?
	if (fibArrSize <= num){
		//Double in size
		fibArrSize = num;
		fibArr = (int *) realloc(fibArr, sizeof(int) * fibArrSize);
	}
	
	fibArr[num  - 1] = computeFib(num - 1) + computeFib(num - 2);
	fibArrCount++;
	return fibArr[num - 1];
}