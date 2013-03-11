#include "stdafx.h"
#define NAMES 10000
#define MAXNAMELEN 50
//qsort ccomparator wrapper  for strncmp function
int strCompare(const void * a, const void * b){
	return strncmp((char *) a, (char *) b, MAXNAMELEN);
}

//Returns the "name score" of a list of names sorted alphabetically
int Euler22(){
	int currNameIndex, currCharIndex, sum = 0;
	char currChar;
	char nameArr[NAMES][MAXNAMELEN];
	errno_t err;
	FILE* file;
	if( (err = fopen_s(&file, "Euler22.txt", "r")) != 0){
		printf("Error opening file");
		exit(-1);
	}
	//Set this to -1 so that we know we are waiting for the start of a new name
	currNameIndex =-1;
	currCharIndex = -1;
	while((currChar = fgetc(file)) != EOF){
		if (currChar == '"' || currChar == ','){
			//Found token
			//Add null termination to current name
			if(currCharIndex != -1){
				nameArr[currNameIndex][currCharIndex + 1] = '\0';
			}
			currCharIndex = -1;
			continue;
		}
		//Check if we have started a new name
		if(currCharIndex == -1){
			currNameIndex++;
		}
		currCharIndex++;
		//Save character
		nameArr[currNameIndex][currCharIndex] = currChar;
	}
	//Sort array
	qsort(nameArr, NAMES, MAXNAMELEN * sizeof(char),  strCompare);
	//Calculate  Weighted Name summation
	for(;currNameIndex >= 0; currNameIndex--){
		//Loop through every charachter in a name
		for(currCharIndex = 0; currCharIndex < strlen(nameArr[currNameIndex]); currCharIndex++){
			//name # *  character value
			sum += (currNameIndex + 1) *  ((int) (nameArr[currNameIndex][currCharIndex]  - 'A' + 1));
		}
	}
	return sum;
}