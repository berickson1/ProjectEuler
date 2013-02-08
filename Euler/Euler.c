// Euler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EulerProblems.h"


int _tmain(int argc, _TCHAR* argv[]){
	
	char userinput;
	printf("Euler Prolem 1: %d\n",Euler1());
	printf("Euler Prolem 1: %d\n",Euler2());
	printf("Press enters to end program");
	fflush(stdout);
	userinput = fgetc(stdin);
	return 0;
}