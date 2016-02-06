/*
Carrasco, Angelica Grace A.
2013-47726
Cmsc128 AB-2L
Assign 001: Number Library
cmsc128-ay2015-16-assign001-c
*/

// This function generates the word form of a single digit.
void onesNumber(int num){
	switch(num){
		case 1:
			printf(" one");
			break;
		case 2:
			printf(" two");
			break;
		case 3:
			printf(" three");
			break;
		case 4:
			printf(" four");
			break;
		case 5:
			printf(" five");
			break;
		case 6:
			printf(" six");
			break;
		case 7:
			printf(" seven");
			break;
		case 8:
			printf(" eight");
			break;
		case 9:
			printf(" nine");
			break;
	}
}

// This function generates the word form of a line of one, 2-digit number.
void lineOfOnes(int num){
	switch(num){
		case 10:
			printf(" ten");
			break;
		case 11:
			printf(" eleven");
			break;
		case 12:
			printf(" twelve");
			break;
		case 13:
			printf(" thirteen");
			break;
		case 14:
			printf(" fourteen");
			break;
		case 15:
			printf(" fifteen");
			break;
		case 16:
			printf(" sixteen");
			break;
		case 17:
			printf(" seventeen");
			break;
		case 18:
			printf(" eighteen");
			break;
		case 19:
			printf(" nineteen");
			break;
	}
}

// This function generates the word form of a 2-digit number.
void tensNumber(int num, int quo){
	int temp = num/10;
	switch(temp){
		case 1:
			return lineOfOnes(num);	// For line of one cases
			break;
		case 2:
			printf(" twenty");
			onesNumber(quo);
			break;
		case 3:
			printf(" thirty");
			onesNumber(quo);
			break;
		case 4:
			printf(" forty");
			onesNumber(quo);
			break;
		case 5:
			printf(" fifty");
			onesNumber(quo);
			break;
		case 6:
			printf(" sixty");
			onesNumber(quo);
			break;
		case 7:
			printf(" seventy");
			onesNumber(quo);
			break;
		case 8:
			printf(" eighty");
			onesNumber(quo);
			break;
		case 9:
			printf(" ninety");
			onesNumber(quo);
			break;
	}
	
}

// This function prints the place. Ignores printing tens and ones.
void displayPlace(int div){
	switch(div){
		case 1000000:
			printf(" million");
			break;
		case 100000:
			printf(" hundred");
			break;
		case 1000:
			printf(" thousand");
			break;
		case 100:
			printf(" hundred");
			break;
	}
}

// This function accepts a whole number from zero to 1 million (1000000; without commas, for example: 1000000) and prints on screen the number in word form.
void numToWords(){
	int num = 0;	// Number
	int div = 0;	// Divisor
	int quo = 0;	// Quotient
	int rem = 0;	// Remainder
	
	printf("\nNUMBER TO WORDS");
	printf("\nEnter a number \nfrom 0 to 1000000 (No commas): ");
	scanf("%d", &num);
	
	printf("\nConverting %d to Words...\n\n", num);
	
	if(num!=0){	// If num is not zero, convert to words, otherwise just print "zero".
		div = 1000000;	// Set divisor to 1000000 for millionth place.
		while(num!=0 && div!=0){	// Loop until num is zero and divisor is 1.
			quo = num / div;	// Divide number by divisor.
			rem = num % div;	// Also get the remainder for next division.
			
			if(quo!=0){	// Skip conversion if quotient is 0.
				if(div==10000){	// Special case for ten thousandth place
					tensNumber(num / 1000, (num % 10000)/1000);	// Different convention from normal	(eg. twenty, eleven, etc).
					displayPlace(1000);	// Prints the place of the number.
					
					num = num % 1000;	// Update number.
					div/=10;	// Update divisor.
					continue;
				} else if(div==10){	// Special case for tenth place.
					tensNumber(num, rem);	// Same concept with ten thousandth place.
					break;	// Break from loop since it already prints ones place.
				} else {	// Every other place with normal conventions.
					onesNumber(quo);
					displayPlace(div);
				}
			}
			num = rem;	// Update number.
			div/=10;	// Update divisor.
		}

	} else {
		printf(" zero ");
	}
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