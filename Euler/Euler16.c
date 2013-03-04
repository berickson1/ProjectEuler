#include "stdafx.h"
#define POWER 1000

//Returns the sum of all the digits in the number 2^1000
int Euler16(){
	//Track the current power we are at & the cell we are using
	int iter, cell;
	//Assume arrSize is large enough
	int arrSize = 400;
	int arrCount = 1;
	int carry = 0;
	int * arrNums = (int *) calloc(arrSize, sizeof(int));
	//Start at 1
	arrNums[0] = 1;
	//Multiplies each digit in the arrNums array by 2, POWER times
	for(iter = 0; iter < POWER; iter++){
		for(cell = 0; cell < arrCount; cell++){
			arrNums[cell] *= 2;
			//Handle carry from previous cell
			if (carry == 1){
				arrNums[cell]++;
				carry = 0;
			}
			//If the cell value >= 10, we must carry the ten forward
			//When multiplying by 2, we will never have a carry > 1
			if (arrNums[cell] > 9){
				arrNums[cell] %= 10;
				carry = 1;
			}
		}
		//We have a new digit
		if (carry == 1){
			arrNums[arrCount] = 1;
			arrCount++;
			carry = 0;
		}
	}
	//Track the digit summation in cell
	cell = 0;
	//Loop through all values stored in the array and sum the digits
	for (iter = 0; iter < arrCount; iter++){
		cell += arrNums[iter];
	}
	return cell;
}