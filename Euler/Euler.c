// Euler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EulerProblems.h"


int _tmain(int argc, _TCHAR* argv[]){
	
	char userinput;
	printf("Euler Prolem 1: %d\n",Euler1());
	printf("Euler Prolem 2: %d\n",Euler2());
	printf("Euler Prolem 3: %d\n",Euler3());
	printf("Euler Prolem 4: %d\n",Euler4());
	printf("Euler Prolem 5: %d\n",Euler5());
	printf("Euler Prolem 6: %d\n",Euler6());
	printf("Euler Prolem 7: %d\n",Euler7());
	printf("Press enter to end program");
	fflush(stdout);
	userinput = fgetc(stdin);
	return 0;
}