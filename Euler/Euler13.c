#include "stdafx.h"
#include "Euler13.h"
//Reeturns the first 10 digits of the sum of 100 50-digit numbers
long long int Euler13(){
	struct listItem sums[10], *currListItem, *listTempHead;
	long long  tempSum = 0;
	int i, j;
	//Store the numbers as char arrays
	//Generate a circular linked list
	for (i = 9; i >= 0;  i--){
		sums[i].next = &sums[(i+1)%10];
		sums[i].value = 0;
	}
	currListItem = &sums[0];
	for(i = numLength - 1; i >= 0; i--){
		//We need to add the carry to the new sum
		for(j = 0; j < numberCount; j++){
			//Convert stored number back to an int and add it to the temp sum
			tempSum += (int)(numbers[j][i] - '0');
		}
		//Store the ones place value
		currListItem -> value = tempSum % 10;
		//Move to the next list item
		currListItem = currListItem -> next;
		//The We need to keep the carry to be used in the next addition
		tempSum /= 10;
	}
	//We have finished the addition, we must deal with the carry
	while(tempSum > 0){
		//Store the ones place value
		currListItem -> value = tempSum % 10;
		//Move to the next list item
		currListItem = currListItem -> next;
		//The We need to keep the carry to be used in the next addition
		tempSum /= 10;
	}
	//Loop through our list and put the digits in the correct order
	//since they are stored in reverse
	listTempHead = currListItem;
	i=0;
	do{
		tempSum += currListItem -> value * pow(10.0, i);
		//Move to the next list item
		currListItem = currListItem -> next;
		i++;
	} while (listTempHead != currListItem);
	return tempSum;
}