#include "stdafx.h"

//Returns the product of abc in the pythegorian triplet where
//a+b+c=1000
int Euler9(){
	//(1) a^2 + b^2 = c^2
	//(2) a + b + c = 1000 => a = 1000 - b - c
	//(1 + 2) (1000 - b - c)^2 + b^2 = c^2
	//1000000 - 2000b - 2000c + 2bc + 2b^2 + c^2 = c^2
	//c = (1000000 - 2000b + 2b^2) / (2000 - 2b)
	int a = 0, b, c = 0, numerator, denominator;
	for(b = 0; b < 1000; b++){
		//Check if we will get a decimal number upon division
		numerator = (1000000 - 2000*b + 2*b*b);
		denominator = (2000 - 2*b);
		if ((numerator % denominator) != 0){
			continue;
		}
		c = numerator / denominator;
		a = 1000 - b - c;
		//If we satisfy the given criteria a < b < c, we are done
		if (a > 0 && a < b && b < c){
			break;
		}
	}
	return a * b * c;
}