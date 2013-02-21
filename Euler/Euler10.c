#include "stdafx.h"

//Returns the sum of all prime numbers below two million
long long int Euler10(){
	int * primes, currNum = 3, i = 2, j, size = 100;
	long long int sum = 5;
	unsigned char prime;
	//Allocate a block of memory for primes to be stored
	primes = (int *) malloc(sizeof(int) * 100);
	//Check if allocated
	if (primes == NULL){
		printf("Memory Allocation Error");
		exit(-1);
	}
	primes[0] = 2;
	primes[1] = 3;
	while (currNum < 2000000){
		//Increment current number by 2 since primes can only be odd
		currNum += 2;
		prime = 1;
		//Check if divisible by existing primes
		for(j = 0; j < i; j++){
			//Check if the prime we are checking is beyond the realm of possibility
			if(sqrt((double)currNum) < primes[j]){
				break;
			}
			if(currNum % primes[j] == 0){
				prime = 0;
				break;
			}
		}
		if (prime == 1){
			//Check if we need to allocate more space
			if (i >= size){
				size += 100;
				primes = (int *) realloc(primes, sizeof(int) * size);
				if (primes == NULL){
					printf("Memory Allocation Error");
					exit(-1);
				}
			}
			primes[i] = currNum;
			i++;
			sum += currNum;
		}
	}
	return sum;
}