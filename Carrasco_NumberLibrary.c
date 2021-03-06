/*
Carrasco, Angelica Grace A.
2013-47726
Cmsc128 AB-2L
Assign 001: Number Library
cmsc128-ay2015-16-assign001-c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NumbersToWords.h"
#include "WordsToNumbers.h"
#include "NumbersDelimited.h"

int displayMenu();

int main(){
	int choice;
	int num;
	char delimiter;
	
	do{
		choice = displayMenu();
		
		switch(choice){
			case 1:	numToWords();	// Calls numToWords(), converts integers to its equivalent word form.
					break;
			case 2: wordsToNum();	// Calls wordsToNum(), converts words to its equivalent integer form.
					break;
			case 3:	wordsToCurrency(); // Calls wordsToCurrency(), converts words to its equivalent integer form and adds currency.
					break;
			case 4: numberDelimited();	// Calls numberDelimited(), delimits a number given a delimiter and number of places to jump.
					break;
			case 0:
				return 0;
			default:
				printf("\nInvalid input. Please try again!\n");
		}
		
	}while (choice!=0);
}

// This function prints the menu for the Number Library
int displayMenu(){
	int choice;
	
	printf("\n\n\t-------------------------");
	printf("\n\tMENU");
	printf("\n\t[1] Numbers to Words");
	printf("\n\t[2] Words to Numbers");
	printf("\n\t[3] Words to Currency");
	printf("\n\t[4] Numbers Delimited");
	printf("\n\t[0] Exit");
	printf("\n\n\t-------------------------");
	printf("\n\tChoice: ");
	scanf("%d", &choice);
	
	return choice;
}

