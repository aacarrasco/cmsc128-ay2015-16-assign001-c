/*
Carrasco, Angelica Grace A.
2013-47726
Cmsc128 AB-2L
Assign 001: Number Library
cmsc128-ay2015-16-assign001-c
*/

#include <stdio.h>
#include "NumbersToWords.h"
#include "NumbersDelimited.h"

int displayMenu();

int main(){
	int choice;
	int num;
	char delimiter;
	
	do{
		choice = displayMenu();
		
		switch(choice){
			case 1:	printf("\nNUMBER TO WORDS");
					printf("\nEnter a number \nfrom 0 to 1000000 (No commas): ");
					scanf("%d", &num);
					numToWords(num);	// Calls numToWords(), converts integers to its equivalent word form.
					break;
			case 2:
				break;
			case 3:
				break;
			case 4: printf("\nNUMBERS DELIMITED");
					printf("\nEnter number to be delimited\n");
					scanf("%d", &num);
					printf("\nEnter one-character delimiter\n");
					scanf("%c", &delimiter);
					numberDelimited();
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

