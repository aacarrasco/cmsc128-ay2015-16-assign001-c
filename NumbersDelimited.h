/*
Carrasco, Angelica Grace A.
2013-47726
Cmsc128 AB-2L
Assign 001: Number Library
cmsc128-ay2015-16-assign001-c
NumbersDelimited Library
*/

typedef struct node{
	// Structure for a node, implemented using Doubly Linked List.
	char num;
	int index;
	struct node *next;
	struct node *prev;
} list;

void insert(list **head, list **tail, char x, int index){
	// This function creates a newnode and inserts it at the tail of the list.
	list *newnode;

	newnode = (list *) malloc (sizeof(list));
	newnode->num = x;
	newnode->index = index;
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

void viewList(list *head, char delimiter, int place){
	// This function prints the delimited list according to the number of jumps given and the delimiter.
	list *p;
	int i;

	printf("Numbers Delimited:\t");
	p = head;
	while(p != NULL){
		printf("%c", p->num);
		if(p->index == place && p->index != 0){
			printf("%c", delimiter);
		}
		p = p->next;
	}

	printf("\n");
}


void numberDelimited(){
	// This function accepts three arguments, the first is the number from zero to 1 million, the second is the delimiter to be used (single character only) and third, the number of jumps when the delimiter will appear (from right most going to left most digit).
	char num[8];
	char delimiter[2];
	char *ptr;
	long check;
	int place;
	int i;
	int index;
	list *head = NULL;
	list *tail = NULL;

	printf("\nNUMBERS DELIMITED");
	do {
		printf("\nEnter number to be delimited: ");
		scanf("%s", num);
		check = strtol(num, &ptr, 10);	// Convert string to long integer to check if it's in between 0 to 1000000.
		if(check >= 0 && check <=1000000){	// Proceed to asking the delimiter and number of jumps.
			printf("\nEnter one-character delimiter: ");
			scanf("%s", delimiter);
			printf("\nEnter number of places: ");
			scanf("%d", &place);
	
			index = strlen(num) - 1;	// Add the index starting from 0 to strlen(num)-1 from right to left.
			for(i=0; i<strlen(num); i++){
				insert(&head, &tail, num[i], index);	// Create a newnode and insert at tail with corresponding number and index.
				index--;
			}

			viewList(head, delimiter[0], place);	// Print delimited list.
			break;
		} else {	// Continue to ask if given number is not in range.
			printf("\nPlease enter a number from 0 to 1000000");
		}
	} while (1);
}
