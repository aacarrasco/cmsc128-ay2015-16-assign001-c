/*
Carrasco, Angelica Grace A.
2013-47726
Cmsc128 AB-2L
Assign 001: Number Library
cmsc128-ay2015-16-assign001-c
*/

#include <stdio.h>
#include "Carrasco_NumberLibrary.h"


int main(){
	int choice;
	
	do{
		choice = displayMenu();
		
		switch(choice){
			case 1:
				numToWords();	// Calls numToWords(), converts integers to its equivalent word form.
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 0:
				return 0;
			default:
				printf("\nInvalid input. Please try again!\n");
		}
		
	}while (choice!=0);
}
