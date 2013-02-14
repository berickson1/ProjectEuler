#include "stdafx.h"

//Returns the smallest number evenly divisible by all numbers 1 - 20
int Euler5(){
	//Determined by ensuring all numers (1 - 20) could be formed as a product
	//of the following numbers using only prime numbers
	return 2 * 3 * 2 * 5 * 7 * 2 * 3 * 11 * 13 * 2 * 17 * 19;
}