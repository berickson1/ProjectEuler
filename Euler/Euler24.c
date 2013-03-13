#include "stdafx.h"

long long int Euler24(){
	//There are 10! combinations, if they are lexographic, we look at this problem mathematically
	//The first digit  can be determined  as 1,000,000  / 9!  = 2.75, so the first digit is the 3rd
	//smallest number available (2)
	//We can look at the second number as being the 1,000,000 - (2 * 9!) th lexographic permutation
	//(274,240)
	//Repeating the process above, we can compute again
	//                              First computed digit (2)
	//274,240 / 8! = 6.8 -> 7th smallest remaining digit  (7)
	//32,320 / 7! = 6.4 -> 7th smallest remaining digit (8)
	//2,080 / 6!  = 2.8 -> 3rd smallest remaining digit (3)
	//640 / 5! = 5.3 -> 6th smallest remaning digit  (9)
	//40 / 4! = 1.7 -> 2nd smallest remaining digit (1)
	//16 / 3! = 2.7 -> 3rd smallest remaining digit (5)
	//4 / 2! = 2 -> 2rd smallest remaining digit (4)
	//2 / 1! = 2 -> 2st smallest remaining digit (6)
	//1 / 0! = 1 -> 1st smallest remaining digit (0)
	return 2783915604;
}