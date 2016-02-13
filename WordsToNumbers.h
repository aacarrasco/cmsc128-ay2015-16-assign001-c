/*
Carrasco, Angelica Grace A.
2013-47726
Cmsc128 AB-2L
Assign 001: Number Library
cmsc128-ay2015-16-assign001-c
WordsToNumbers Library
*/

typedef struct wordNode{
	// Structure for a node, implemented using Doubly Linked List.
	char words[20];
	struct wordNode *next;
	struct wordNode *prev;
} wordList;

void insertWord(wordList **head, wordList **tail, char *x){
	// This function creates a newnode and inserts it at the tail of the list.
	wordList *newnode;

	newnode = (wordList *) malloc (sizeof(wordList));
	strcpy(newnode->words, x);
	newnode->next = NULL;
	newnode->prev = NULL;

	if(*head == NULL){
		*head = newnode;
		*tail = newnode;
	} else {
		(*tail)->next = newnode;
		newnode->prev = *tail;
		*tail = newnode;
	}
}

void wordsToNum(){
	// This function accepts a number in word form (from zero to 1 million) and returns it in numerical form. Input must be in lowercase.
	wordList *head = NULL;
	wordList *tail = NULL;
	char *input;
	char temp[80];	
	const char s[2] = " ";
	char *words;
	int i;

	printf("\nWORDS TO NUMBERS");

	printf("\nEnter a number in words: ");
	getchar();
	fgets(temp, 80, stdin);
	input = strtok(temp, "\n");	// Remove newline from fgets().

	words = strtok(input, s);	// Split string into different tokens and create nodes for each.
	while(words != NULL){
		insertWord(&head, &tail, words);
		words = strtok(NULL, s);
	}

	printf("\nConverting %s to Words...\n\n", input);
	i = compute(head);
	if(i >= 0 && i <= 1000000){	// Checks if user input is within the range of zero to 1 million.
		printf("\nWORDS TO NUMBERS: %d\n", i);		
	} else {
		printf("\nPlease enter a number from 0 to 1000000");
	}

}

int specialCases(wordList *p){
	// This function returns the equivalent of each ones, tens, and divisible by 10's numbers.
	if(strcmp(p->words, "zero") == 0){
		return 0;
	} else if(strcmp(p->words, "one") == 0){
		return 1;
	} else if(strcmp(p->words, "two") == 0){
		return 2;
	} else if(strcmp(p->words, "three") == 0){
		return 3;
	} else if(strcmp(p->words, "four") == 0){
		return 4;
	} else if(strcmp(p->words, "five") == 0){
		return 5;
	} else if(strcmp(p->words, "six") == 0){
		return 6;
	} else if(strcmp(p->words, "seven") == 0){
		return 7;
	} else if(strcmp(p->words, "eight") == 0){
		return 8;
	} else if(strcmp(p->words, "nine") == 0){
		return 9;
	} else if(strcmp(p->words, "ten") == 0){
		return 10;
	} else if(strcmp(p->words, "eleven") == 0){
		return 11;
	} else if(strcmp(p->words, "twelve") == 0){
		return 12;
	} else if(strcmp(p->words, "thirteen") == 0){
		return 13;
	} else if(strcmp(p->words, "fourteen") == 0){
		return 14;
	} else if(strcmp(p->words, "fifteen") == 0){
		return 15;
	} else if(strcmp(p->words, "sixteen") == 0){
		return 16;
	} else if(strcmp(p->words, "seventeen") == 0){
		return 17;
	} else if(strcmp(p->words, "eighteen") == 0){
		return 18;
	} else if(strcmp(p->words, "nineteen") == 0){
		return 19;
	} else if(strcmp(p->words, "twenty") == 0){
		return 20;
	} else if(strcmp(p->words, "thirty") == 0){
		return 30;
	} else if(strcmp(p->words, "forty") == 0){
		return 40;
	} else if(strcmp(p->words, "fifty") == 0){
		return 50;
	} else if(strcmp(p->words, "sixty") == 0){
		return 60;
	} else if(strcmp(p->words, "seventy") == 0){
		return 70;
	} else if(strcmp(p->words, "eitghty") == 0){
		return 80;
	} else if(strcmp(p->words, "ninety") == 0){
		return 90;
	} else {	// Returns -1 otherwise.
		return -1;
	}
}

int place(wordList *p){
	// This function returns the specified number of places.
	if(strcmp(p->words, "hundred") == 0){
		return 100;
	} else if(strcmp(p->words, "thousand") == 0){
		return 1000;
	} else if(strcmp(p->words, "million") == 0){
		return 1000000;
	} else {	// Returns -1 otherwise.
		return -1;
	}
}

int compute(wordList *head){
	// This function computes the equivalent number form of the given input, by summing up the equivalent number of number words given and multiplying corresponding places.
	wordList *p;
	int total = 0;
	int temp = 0;
	int num = 0;

	p = head;
	while(p != NULL){	
		if(specialCases(p) != -1){ 	// Assign equivalent digit to num
			num = specialCases(p);
		} else if(place(p) != -1){ 
			if(place(p) == 100){	// Special case for hundreds place
				temp = total - (total % 10); // Make temp a divisible of 10.
				num = ((total % 10) * 100) + temp;	// Assign to temp the product of the remainder of total from 10 to 100 and add temp.
			} else if(place(p) == 1000){	//Special case for thousands place.
				num = total * 1000;	// Assign to num the product of total and 1000.
			} else if(place(p) == 1000000){	// Special case for millionth place.
				num = total * 1000000;	// Assign to num the product of total and 1000000.
			}
			total = 0; // Reset total.

		}
		total += num;	// Add num to total.
		p = p->next;	// Update p.
	}

	return total;	// Return total.
}