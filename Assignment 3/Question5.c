/*

*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>




//Structure used:
struct TextEditor {
    char **lines;   //array of a pointer to a pointer?
    int count;      // total number of lines currently stored
    int capacity;   // this is the current or present like max capacity of the array
};




//All Function Prototypes:
void insertLine(struct TextEditor *editor, int index, const char *text);
void deleteLine(struct TextEditor *editor, int index);
void printAllLines(struct TextEditor *editor);
void shrinkToFit(struct TextEditor *editor);
void saveToFile(struct TextEditor *editor, const char *filename);
void loadFromFile(struct TextEditor *editor, const char *filename);
void freeAll(struct TextEditor *editor);




int main() {
    struct TextEditor editor;
    
    //initial capacity allocation:
    editor.count = 0;
    editor.capacity = 2;
    editor.lines = (char **)malloc(editor.capacity * sizeof(char *));
    
    if (editor.lines == NULL) {
        error(1, 0, "Initial memory allocation failed!"); 
    }

    int choice;
    int index;
    
    char buffer[1024]; //keeping this to be 1024, could be more or less too
    char filename[100];

    printf("\n--- Minimal Line-Based Text Editor ---\n\n");

    while (1) { //repeat infinitely until returning in main
        printf("\nKey:\n1. Insert Line\n2. Delete Line\n3. Print All\n4. Shrink Memory\n5. Save to File\n6. Load from File\n7. Exit\n");
        
        
        printf("Enter Your Choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); //Clear input taken
            continue;
        }
        
        getchar(); // used here to clear the buffer that would consume the new line characeter stored or stuck in the buffer that might interfare with other inputs

        switch (choice) {
            case 1:
                printf("Please Enter Your Text: ");
                
                if (fgets(buffer, 1024, stdin) != NULL) {
                    buffer[strcspn(buffer, "\n")] = 0; // Removing the new line character by 0 to just represent null
                    printf("Please Enter Index (0 to %d): ", editor.count);
                    scanf("%d", &index);
                    insertLine(&editor, index, buffer);
                }
                
                break;
            case 2:
                printf("Please Enter Index To Delete: ");
                
                scanf("%d", &index);
                deleteLine(&editor, index);
                
                break;
            case 3:
                printAllLines(&editor);
                break;
            case 4:
                shrinkToFit(&editor);
                break;
            case 5:
                printf("Please Enter Your Filename: ");
                
                
                if (fgets(filename, sizeof(filename), stdin)) {
                    filename[strcspn(filename, "\n")] = 0;
                    saveToFile(&editor, filename);
                }
                break;
            case 6:
                printf("Please Enter filename: ");
                
                if (fgets(filename, sizeof(filename), stdin)) {
                    filename[strcspn(filename, "\n")] = 0;
                    loadFromFile(&editor, filename);
                }
                break;
            case 7:
                freeAll(&editor);
                printf("Exiting Program...\n");
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}



//Inserting one line at a particular index
void insertLine(struct TextEditor *editor, int index, const char *text) {
    if (index < 0 || index > (*editor).count) {
        // status 0 means do not exit program, just print error
        error(0, 0, "Index is out of bounds");
        return;
    }

	//realloc: 
	
    //Expand the array if it is already full by using realloc:
    if ((*editor).count == (*editor).capacity) {
        int newCapacity = (*editor).capacity * 2; 
        char **temp = (char **)realloc((*editor).lines, newCapacity * sizeof(char *));
        
        if (temp == NULL) {
            error(1, 0, "Memory expansion (realloc) failed");
        }
        
        (*editor).lines = temp;
        (*editor).capacity = newCapacity;
    }

    //Shift the pointers here inorder to make a room to add more of something, using the memmove function
    if (index < (*editor).count) {
        memmove(&(*editor).lines[index + 1], 
                &(*editor).lines[index], 
                ((*editor).count - index) * sizeof(char *));
    }

    //allocating the memory needed
    (*editor).lines[index] = (char *)malloc(strlen(text) + 1);
    if ((*editor).lines[index] == NULL) {
        error(1, 0, "Memory allocation for string failed");
    }

    strcpy((*editor).lines[index], text);
    (*editor).count++;
    printf("Line inserted.\n");
}




//Inorder to deleate a line at a particlar index:
void deleteLine(struct TextEditor *editor, int index) {
    if (index < 0 || index >= (*editor).count) {
        error(0, 0, "Index out of bounds");
        return;
    }

    free((*editor).lines[index]);

    //Moving our pointer to fill the hole:
    if (index < (*editor).count - 1) {
        memmove(&(*editor).lines[index], 
                &(*editor).lines[index + 1], 
                ((*editor).count - index - 1) * sizeof(char *));
    }

    (*editor).count--;
    printf("Line deleted.\n");
}




void printAllLines(struct TextEditor *editor) {
	int i;
    printf("\n--- Content (%d lines) ---\n", (*editor).count);
    for (i = 0; i < (*editor).count; i++) {
        printf("%d: %s\n", i, (*editor).lines[i]);
    }
}




//Reducion fo the capacity:
void shrinkToFit(struct TextEditor *editor) {
    if ((*editor).count == 0) return;

    if ((*editor).count < (*editor).capacity) {
        char **temp = (char **)realloc((*editor).lines, (*editor).count * sizeof(char *));
        if (temp == NULL) { //this should not end the program so there should be 0,0 to print only
            error(0, 0, "Shrink operation failed"); 
            return;
        }
        (*editor).lines = temp;
        (*editor).capacity = (*editor).count;
        printf("Memory shrunk to %d.\n", (*editor).capacity);
    }
}



//now we can save:
void saveToFile(struct TextEditor *editor, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        error(0, 0, "Error opening file for writing");
        return;
    }
	int i;
    for (i = 0; i < (*editor).count; i++) {
        fprintf(fp, "%s\n", (*editor).lines[i]);
    }

    fclose(fp);
    printf("Saved to %s.\n", filename);
}



void loadFromFile(struct TextEditor *editor, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        error(0, 0, "Error opening file for reading");
        return;
    }
    freeAll(editor);
   
    //reinitialization:
    (*editor).count = 0;
    (*editor).capacity = 2;
    (*editor).lines = (char **)malloc((*editor).capacity * sizeof(char *));
    if ((*editor).lines == NULL) {
        error(1, 0, "Memory allocation during load failed");
    }

    char buffer[1024];
    while (fgets(buffer, 1024, fp)) {
        buffer[strcspn(buffer, "\n")] = 0;
        insertLine(editor, (*editor).count, buffer);
    }

    fclose(fp);
    printf("Loaded from %s.\n", filename);
}



void freeAll(struct TextEditor *editor) {
	int i;
    for (i = 0; i < (*editor).count; i++) {
        free((*editor).lines[i]);
    }
    free((*editor).lines);
    (*editor).lines = NULL;
    (*editor).count = 0;
    (*editor).capacity = 0;
}








