#include "stdafx.h"
#include <string.h>
//Returns 1 of number is a paledrone
int isPaledrone(int num){
	int i, j;
	//Largest number (999*999) is 6 digits
	char strNum[7];
	sprintf_s(strNum, 7, "%d", num);
	for(i = strlen(strNum) - 1, j = 0; i > j; i--, j++){
		if(strNum[i] != strNum[j]){
			return 0;
		}
	}
	return 1;
}

//Returns the largest numeric paledrone that is a product of 3-digit numbers
int Euler4(){
	int i, j, testNum;
	int largestPaledrone = 0;
	for(i = 999; i > 0; i--){
		//Check to see if the largest remaining number is smaller than largestPaledrone
		//Done if this is true
		if (i * i < largestPaledrone){
			break;
		}
		//Calculate products and test if paledrone
		for (j = i; j > 0; j--){
			testNum = i * j;
			//Check to see if the largest remaining unchecked product is smaller 
			//than largestPaledrone. Done this iteration if this is true
			if (testNum < largestPaledrone){
				break;
			}
			if (isPaledrone(testNum) == 1){
				largestPaledrone = testNum;
			}

		}
	}
	return largestPaledrone;
}