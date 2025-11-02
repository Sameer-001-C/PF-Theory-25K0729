#include <stdio.h>
#include <string.h>


void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *bookCount); //add new book
void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount); //process a sale
void generateLowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount); //generate a low stock report

void pushTitle(char titles[][50], int *top, char newTitle[]); //additional function, needed to add string (book title) into the array

int main(){
	int isbns[100];
	char titles[100][50];
	float prices[100];
	int quantities[100];
	int bookCount = 0; //total number of books, including all the same types of books
	int choice;
	
	int titleTop = -1;

	
	do{
		printf("\nMenu:\nKey:\n1. Add New Book\n2. Process a Sale\n3. Generate Low-Stock Report\n4. Exit\n");

		printf("Please enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: //add new book
				addNewBook(isbns, titles, prices, quantities, &bookCount);
				titleTop = bookCount - 1;
				break;
			case 2: //process a sale
				processSale(isbns, titles, prices, quantities, bookCount);
				break;
			case 3: //generate that report thing
				generateLowStockReport(isbns, titles, prices, quantities, bookCount);
				break;
			case 4: //exit
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice! Please try again.\n");
		}
		
	}while(choice != 4); //exit
	
	return 0;
}




//add new book: prevent duplicate isbns
void addNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *bookCount){ //first check for storage in inventory, then verify duplicate isbn, only then enter the book
	int isbn;
	char title[50];
	float price;
	int quantity;
	int i;
	
	if(*bookCount >= 100){ //check if the inventory is occupied or empty
		printf("Inventory full! Cannot add more books.\n");
		return;
	}
	
	printf("ISBN: ");
	scanf("%d", &isbn);
	
	for(i = 0; i < *bookCount; i++){ //duplicate
		if(isbns[i] == isbn){
			printf("Cannot enter this as new book. ISBN already exists in inventory.\n");
			return;
		}
	}
	
	printf("Book Title: "); //if no duplicates
	scanf(" %[^\n]", title);  //validation to read until the string ends to a new line character (\n)
	
	printf("Book Price: ");
	scanf("%f", &price);
	printf("Book Quantity: ");
	scanf("%d", &quantity);
	
	isbns[*bookCount] = isbn;
	
	pushTitle(titles, bookCount, title);
	prices[*bookCount] = price;
	quantities[*bookCount] = quantity;
	
	(*bookCount)++; //go to the address of "bookCount", extract whatever is stored at this location, then plus 1
	printf("Book added successfully!\n");
}


//process a sale: Ask for an ISBN and the number of copies sold. 
//Find the book and update its quantity. Handle out of stock errors.
void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount){ //input would be isbn and number of copies sold
	int isbn, copies, i, found = 0;
	
	if(bookCount == 0){ //out of stock errors
		printf("Inventory is Empty\n");
		return;
	}
	
	printf("Enter ISBN to process sale: ");
	scanf("%d", &isbn);
	
	for(i = 0; i < bookCount; i++){ //will search for the book inside the entire array. extracting an "i" which will match to all other arrays
		
		if(isbns[i] == isbn){ //match if found
			found = 1;
			printf("Please enter the total number of copies sold: ");
			scanf("%d", &copies);
			
			if(copies <= 0){
				printf("Invalid input!\n");
				return;
			}
			
			if(quantities[i] == 0){
				printf("No books with this ISBN is left in inventory.\n");
			}
			else if(copies > quantities[i]){
				printf("Not enough such books in inventory. Quantity available: %d\n", quantities[i]);
			}
			else{ //if everything works just fine:
				quantities[i] -= copies;
				printf("Sale processed successfully. Book name: \"%s\".\nRemaining books: %d\n", titles[i], quantities[i]);
			}
			break;
		}
	}
	
	if(!found){ //if found, then 1, which becomes 0, which is false. if not found, then 0, which becomes 1, so the below statement should then only run
		printf("Book not found!\n");
	}
}


//generate a low stock report: display the details of all the books whose quantity has fallen below 5
void generateLowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int bookCount){
	
	int i, lowStockFound = 0;
	
	if(bookCount == 0){
		printf("No books in inventory yet.\n");
		return;
	}
	
	printf("\nBooks with qantity less than 5:\n");
	
	for(i = 0; i < bookCount; i++){
		
		if(quantities[i] < 5){
			printf("ISBN: %d\n", isbns[i]);
			printf("Title: %s\n", titles[i]);
			printf("Price: %.2f\n", prices[i]);
			printf("Quantity: %d\n", quantities[i]);
			
			lowStockFound = 1; //flag just like before so like same logic and stuff
		}
	}
	
	if(!lowStockFound){
		printf("No books with less than 5 quantity.\n");
	}
}

void pushTitle(char titles[][50], int *top, char newTitle[]){
	if(*top >= 100 - 1){
		printf("Cannot push title, stack is full.\n");
		return;
	}

	int i = 0;
	while (newTitle[i] != '\0' && i < 49) {  // manually copying each char to the array
		titles[*top][i] = newTitle[i];
		i++;
	}
	titles[*top][i] = '\0'; // adding \0 as the last character to indicate the end of the string
}
