#include "stdafx.h"
#define MAXNUM 28123
//Fills a given mmemory space with all abundant numbers less than or equal to size
//We assume that the array is of size  'size'
void computeAbundancyArr(int * abundancyArr, int size){
	int num;
	for(num = 1; num <= size; num++){
		if(calculateFactorSum(num)  > num){
			*abundancyArr++ = num;
		}
	}
}

//Returns the sum of all the numbers that cannot be calculated as a sum of two
//abundant numbers
int Euler23(){
	//Allocating too much space
	int * abundancyArrHead  = (int *) calloc(MAXNUM, sizeof(*abundancyArrHead));
	int * abundancyArr = abundancyArrHead;
	int * abundancyArr2 = abundancyArrHead;
	//Boolean array (should use different datatype) tto see if number is a sum
	//of two aabundant numbers
	int * sumArrHead  = (int *) calloc(MAXNUM, sizeof(*sumArrHead));
	int * sumArr = sumArrHead;
	int sum = 0;
	computeAbundancyArr(abundancyArrHead, MAXNUM);
	//Find the sum of all pairs of abundant numbers and set the sumArr value to 1
	while(*abundancyArr != 0 &&  abundancyArr <  abundancyArrHead + MAXNUM){
		abundancyArr2 = abundancyArr;
		while(*abundancyArr2 != 0 && abundancyArr2 < abundancyArrHead + MAXNUM){
			if(*abundancyArr + *abundancyArr2 <= MAXNUM){
				sumArr[*abundancyArr + *abundancyArr2 - 1] = TRUE;
			}
			abundancyArr2++;
		}
		abundancyArr++;
	}
	//Calculate the sum of nnumbers (as indicies) in sumArr where they are not a summ
	//of two aabundant numbers (value = 0)
	while(sumArr < sumArrHead + MAXNUM){
		if(*sumArr == 0){
			sum += sumArr - sumArrHead + 1;
		}
		sumArr++;
	}
	//Free memory
	free(sumArrHead);
	free(abundancyArrHead);
	return sum;
}