/*
Question 4: You are tasked with designing a Library Shelf System that can store a limited 
number of books. Each book has a unique ID and a popularity score. The shelf can only hold a 
fixed number of books (capacity), and the system must ensure that the least recently accessed 
book is removed when the shelf is full and a new book is added. 
The system supports two operations: 
1. ADD x y – Add a book with ID x and popularity score y. 
	If the book already exists on the shelf, update its popularity score. 
	If the shelf is full, remove the least recently accessed book before adding the new 
one. 
2. ACCESS x – Access a book with ID x. 
	If the book exists on the shelf, return its popularity score. 
	If the book is not on the shelf, return -1. 
Implement the shelf system in C using structures and pointers (arrays can be used, no advanced data 
structures like hash maps or linked lists required). 
*/

#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    int popularity;
    int lastAccess; 
};

int findBook(struct Book shelf[], int size, int id) {
    int i;
    for(i = 0; i < size; i++) {
        if(shelf[i].id == id){
            return i;
    	}
    }
    return -1;
}

int findLeastRecent(struct Book shelf[], int size) {
    int i, idx = 0;
    for(i = 1; i < size; i++) {
        if(shelf[i].lastAccess < shelf[idx].lastAccess){
            idx = i;
    	}
    }
    return idx;
}

void addBook(struct Book shelf[], int *currentSize, int capacity, int id, int popularity, int time) {
    int pos = findBook(shelf, *currentSize, id);

    if(pos != -1){
        shelf[pos].popularity = popularity;
        shelf[pos].lastAccess = time;
        return;
    }

    if(*currentSize < capacity){
        shelf[*currentSize].id = id;
        shelf[*currentSize].popularity = popularity;
        shelf[*currentSize].lastAccess = time;
        (*currentSize)++;
    } 
	else{
        int idx = findLeastRecent(shelf, capacity);
        shelf[idx].id = id;
        shelf[idx].popularity = popularity;
        shelf[idx].lastAccess = time;
    }
}

int accessBook(struct Book shelf[], int size, int id, int time) {
    int pos = findBook(shelf, size, id);
    if(pos == -1){
        return -1;
	}
    shelf[pos].lastAccess = time;
    return shelf[pos].popularity;
}

int main() {
    int capacity, Q;
    scanf("%d %d", &capacity, &Q);

    struct Book shelf[capacity];
    int currentSize = 0;
    int time = 1;

    int i;
    for(i = 0; i < Q; i++) {
        char op[10];
        scanf("%s", op);

        if(strcmp(op, "ADD") == 0) {
            int id, pop;
            scanf("%d %d", &id, &pop);
            addBook(shelf, &currentSize, capacity, id, pop, time);
        } 
        else if(strcmp(op, "ACCESS") == 0) {
            int id;
            scanf("%d", &id);
            int result = accessBook(shelf, currentSize, id, time);
            printf("%d\n", result);
        }

        time++;
    }

    return 0;
}




