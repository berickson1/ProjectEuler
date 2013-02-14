#include "stdafx.h"

//Returns the 1001st Prime number
int Euler7(){
	int * primes, i = 0, j, currNum = 1;
	unsigned char prime;
	//Allocate a block of memory for primes to be stored
	primes = (int *) malloc(sizeof(int) * 10001);
	//Check if allocated
	if (primes == NULL){
		printf("Memory Allocation Error");
		exit(-1);
	}
	while (i < 10001){
		currNum++;
		prime = 1;
		//Check if divisible by existing primes
		for(j = 0; j < i; j++){
			if(currNum % primes[j] == 0){
				prime = 0;
				break;
			}
		}
		if (prime == 1){
			primes[i] = currNum;
			i++;
		}
	}
	return currNum;
}