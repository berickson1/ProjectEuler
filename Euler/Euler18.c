#include "stdafx.h"

//Returns the sum of the longest path in a triangular matrix of values 
int computeLongestPath(FILE * file, int length){
	char* token, * nextToken;
	char* line = (char*) calloc(3*length + length + 1, sizeof(char));
	int* resultArrHead, * currCell, * prevRow, * currRowHead;
	int leftVal = 0, rightVal = 0, i, maxVal = 0;
	resultArrHead =  (int *) calloc(length * (length + 1) / 2, sizeof(int));
	currCell = prevRow = currRowHead = resultArrHead;
	//Read all lines and load the values into the result array
	while (fgets(line,3*length + length, file) != NULL){
		//Read the first token
		token = strtok_s(line,  " ", &nextToken);
		//Store and read remaining tokens
		while (token != NULL) {
			//Store in currCeell then increment pointer
			*currCell++ = atoi(token);
			token = strtok_s(NULL, " ", &nextToken);
		}
	}
	//Run for all rows. We are starting in row 2 (index 1)
	currCell = resultArrHead;
	for(i = 1; i < length; i++){
		prevRow = currRowHead;
		currRowHead = ++currCell;
		//The far left edge of a row only has one path
		*currCell  += *prevRow;
		rightVal = *prevRow;
		while (prevRow + 1 != currRowHead){
			//Store the values above the cell to the left and right
			leftVal = rightVal;
			rightVal = *++prevRow;
			//Add the largest value to the cell
			if(rightVal > leftVal){
				*++currCell += rightVal;
			}
			else {
				*++currCell += leftVal;
			}
		}
		//The far right edge of the row only has one path
		*++currCell += rightVal;
	}
	//Find the largest value in the final row
	currCell = currRowHead;
	for(i = 0; i < length; i++, currCell++){
		if(*currCell > maxVal){
			maxVal = *currCell;
		}
	}
	free(resultArrHead);
	return maxVal;
}
//Returns the maximum path sum in a given text file (Euler18.txt)
int Euler18(){
	errno_t err;
	FILE* file;
	if( (err = fopen_s(&file, "Euler18.txt", "r")) != 0){
		printf("Error opening file");
		exit(-1);
	}
	return computeLongestPath(file, 15);
}