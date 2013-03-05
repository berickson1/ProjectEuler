#include "stdafx.h"
#include "Euler18.h"
//Returns the maximum path summation in the given text file (Euler67.txt)
//Utilizes  the same function used to compute the longest path in Euler18
int Euler67(){
	errno_t err;
	FILE* file;
	if( (err = fopen_s(&file, "Euler67.txt", "r")) != 0){
		printf("Error opening file");
		exit(-1);
	}
	return computeLongestPath(file, 100);
}