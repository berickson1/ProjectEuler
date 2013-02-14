#include "stdafx.h"

//Returns the difference between the sum of the squares of the first one hundred natural
//numbers and the square of the sum
int Euler6(){
	int i, sum1 = 0, sum2 = 0;
	for(i = 1; i <= 100; i++){
		sum1 += (i * i);
		sum2 += i;
	}
	sum2 *= sum2;
	return sum2 - sum1;
}