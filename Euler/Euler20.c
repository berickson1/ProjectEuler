#include "stdafx.h"
//Returns the sum of the digits in 100!
int Euler20(){
	//Looks like we have to implement array multiplication as the number is too big
	int arrSize = 50;
	int arrIndex = 0;
	int sum = 0;
	int carry = 0;
	int multiplicand;
	int * numArrHead, * numArr;
	numArrHead = (int *) calloc(arrSize, sizeof(int));
	if (numArrHead == NULL){
		printf("Memory allocation error occurred");
		exit(-1);
	}
	//preload 1 into the array
	*numArrHead = 1;
	arrIndex = 1;
	for (multiplicand = 1; multiplicand <=100; multiplicand++){
		numArr = numArrHead;
		//No carry yet
		carry = 0;
		//Multiply existing numbers in array by multiplicand
		while (numArr < numArrHead + arrIndex){
			*numArr *= multiplicand;
			//See if we need to add a carry
			if (carry != 0){
				*numArr += carry;
			}
			//Check if we need to carry
			if (*numArr >= 10){
				carry = *numArr / 10;
				*numArr %= 10;
			} else {
				carry = 0;
			}
			numArr++;
		}
		//Deal with leftover carry
		while (carry != 0){
			//Check if we need to allocate more memory
			if(arrIndex >= arrSize){
				arrSize += 10;
				numArrHead = (int *) realloc(numArrHead, arrSize * sizeof(int));
				if (numArrHead == NULL){
					printf("Memory reallocation error occurred");
					exit(-1);
				}
				//Point pointer at the correct memory space
				numArr = numArrHead + arrIndex;
			}
			*numArr = carry % 10;
			arrIndex++;
			numArr++;
			carry /= 10;
		}
	}
	//Calculate Sum
	numArr = numArrHead;
	while (numArr != numArrHead + arrIndex){
		sum += *numArr;
		numArr++;
	}
	free(numArrHead);
	return sum;
}