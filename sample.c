#include<stdio.h>
#include<stdlib.h>

typedef struct lst_int {
	int number; // Actual data contained in the list 
	struct lst_int *ptr_next; // pointer to next node
}lst_int;

lst_int *ptr_global = NULL;


//Function to create the list
int create_lst(int number) {
	int successCode = 1; // 1 is success and 0 is failure

	lst_int *ptr_temp = (lst_int*)(malloc(sizeof(lst_int))); // Assuming successful memory allocation
	ptr_temp->number = number;
	ptr_temp->ptr_next = NULL;

	if (!ptr_global) {
		printf("\nThis is the first element of the list");
		ptr_global = ptr_temp;
	}
	else {
		// Add the new node to the last of the list
		lst_int* ptr = NULL;
		//Go to the end of the list
		for (ptr = ptr_global; ptr->ptr_next; ptr = ptr->ptr_next);
		ptr->ptr_next = ptr_temp;
				
	}
	return successCode;
}


//Function to display the list
void display_List() {
	// Refer to the global pointer which is at the start of the list
	if (!ptr_global) {
		printf("\nThere is no element yet in the list");
	}
	else {
		
		//Loop through the list till ptr_next is NULL.
		for (lst_int* ptr = ptr_global; ptr; ptr = ptr->ptr_next) {
			printf("\nThe element is : %d", ptr->number);
		}

	}

}


//This is the program for singly list operations.
void main() {
	//display_List();
	// Create the list of integers
	int result = create_lst(10);
	result = create_lst(20);
	result = create_lst(90);
	result = create_lst(40);
	display_List();
}
