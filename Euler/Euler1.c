#include "stdafx.h"

//Returns the sum of all multiples of 3 or 5 below 1000
int Euler1(){
	int sum = 0;
	int i;
	for(i = 1; i*3 < 1000; i++){
		sum += 3 * i;
	}
	for(i = 1; i*5 < 1000; i++){
		if ((i * 5) % 3 != 0){
		sum += 5 * i;
		}
	}
	return sum;
}