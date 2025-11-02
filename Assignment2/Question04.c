#include <stdio.h>

void push(int stack[], int *top, int maxSize, int element); //insert an element into the stack
void pop(int stack[], int *top); //remove the top element from the stack
void peek(int stack[], int top); //display the top element 
void display(int stack[], int top); //show all the elements that are inside the stack

int main(){
	int choice;
	int top = -1; //top points to the index of top element
	int maxSize;
	int element;
	printf("Please enter the size of your stack: ");
	scanf("%d", &maxSize);
	printf("\nKey:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
	printf("\nPlease enter your choice: ");
	scanf("%d", &choice);
	int stack[maxSize]; //declaring a stack array
	
	while(choice != 5){ //exit if choice = 5
		switch(choice){
			case 1: //Push
				printf("Please enter an element to add: ");
				scanf("%d", &element);
				push(stack, &top, maxSize, element);
				break;
			case 2: //Pop
				pop(stack, &top);
				break;
			case 3: //Peek
				peek(stack, top);
				break;
			case 4: //Display
				display(stack, top);
				break;
			default:
				printf("Invalid Input! Please enter again.");
		}
		printf("\nKey:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
		printf("\nPlease enter your choice: ");
		scanf("%d", &choice);
	}
	
	return 0;
}

void peek(int stack[], int top){
	if(top == -1){
		printf("Stack is empty.\n");
	}
	else{
		printf("Element on top: %d\n", stack[top]);
	}
}

void pop(int stack[], int *top){
	if(*top == -1){
		printf("Cannot remove an element. Stack is empty.\n");
	}
	else{
		printf("%d removed.\n", stack[*top]);
		stack[*top] = 0;
		(*top)--;
	}
}

void push(int stack[], int *top, int maxSize, int element){ //top intial value is -1.
	if(*top == maxSize -1){
		printf("Stack Full! Element not added.\n");
	}
	else{
		(*top)++; //top first becomes 0.
		stack[*top] = element; //then, at the index of top, 0, element is stored in the array
		printf("%d added to the stack.\n", element);
	}
}

void display(int stack[], int top){
	int i;
	if(top == -1){
		printf("Stack is empty.\n");
	}
	else{
		printf("Your stack:\n");
		for(i = 0; i <= top; i++){
			printf("%d. %d\n", i, stack[i]);
		}
	}
}
