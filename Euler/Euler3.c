#include "stdafx.h"

//Returns the largest prime factor of 600851475143
int Euler3(){
	int i;
	long long int num = 600851475143;
	for(i = 2; i <=num; i++){
		//If num divisible by i, do it
		if (num  % i == 0){
			num /= i;
			//We need to recheck the factor, so decrement
			i--;
		}
	}
	return i;
}