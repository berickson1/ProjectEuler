#include "stdafx.h"
#define MAXNUM 999999
//Returns the length of the Collaz sequence starting at a given nuber
//Cache implemented for faster lookups
int computeCollaz(long long int num, int * collCache){
	//Check if we will be beond the bounds of the cache
	if (num  <= MAXNUM){
		//Check if cache value not filled
		if(collCache[num - 1] == 0){
			if (num % 2 == 0){
				collCache[num - 1] = 1 + computeCollaz(num / 2, collCache);
			} else {
				collCache[num - 1] = 1 + computeCollaz(3*num + 1, collCache);
			}
		}
		return collCache[num - 1];
	} else {
		if (num % 2 == 0){
			return 1 + computeCollaz(num / 2, collCache);
		} else {
			return 1 + computeCollaz(3*num + 1, collCache);
		}
	}
}

//Reeturns a starting number under one million that produces the 
//longest Collatz Sequence
int Euler14(){
	long long int i;
	int maxLen = 0, maxVal  = 1, temp;
	//Initialize a cache for computed collaz sequence lengths
	int *collCache = (int *) calloc(MAXNUM, sizeof(int));
	collCache[0] = 1;
	for (i = 1; i <= MAXNUM; i++){
		temp = computeCollaz(i, collCache);
		if (temp >= maxLen){
			maxLen = temp;
			maxVal = i;
		}
	}
	return maxVal;
}