#include "stdafx.h"
//One larger than grid since we are looking at edges
#define GRIDSIZE 21
long long int Euler15(){
	long long int i;
	int j;
	long long int * gridHead = (long long int *) calloc(GRIDSIZE * GRIDSIZE, sizeof(long long int));
	long long int * currCell = gridHead;
	long long int * rowAbove = gridHead;
	long long int * gridEnd = gridHead + GRIDSIZE * GRIDSIZE;
	//Fill first row of grid
	for(i = 0; i < GRIDSIZE; i++, currCell++){
		*currCell = 1;
	}
	//Loop through remaining rows
	for(i = 1; i < GRIDSIZE; i++){
		//The first cell of every row ==  cell above
		*currCell = *rowAbove;
		currCell++;
		rowAbove++;
		//Loop through remining cells in row
		for(j = 1; j < GRIDSIZE; j++, currCell++, rowAbove++){
			*currCell = *rowAbove +  *(currCell - 1);
		}
	}
	currCell--;
	i = *currCell;
	free(gridHead);
	return i;
}