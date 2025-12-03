#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//Student Structure:
struct Student {
    char id[15];
    char name[100];
    char batch[20];
    char type[10];
    char regDate[15];
    char dob[15];
    char interest[10];
};



//Function Prototypes: 
void loadDatabase(const char *filename); //done
void saveDatabase(const char *filename);
void addStudent(const char *filename);
void updateStudent(const char *filename);
void deleteStudent(const char *filename);
void printAllStudents();
void generateReports();
void freeMemory();




struct Student *students;
int count = 0;
int capacity = 5;

int main() {
    int choice;
    char filename[] = "members.dat"; 


    //Initialization:
    students = (struct Student *)malloc(capacity * sizeof(struct Student));
    if (students == NULL) {
        printf("Error! Could not allocate any initial memory.\n");
        return 1;
    }

    //Loading the existing data from file during the start
    loadDatabase(filename);

    printf("\n--- IEEE / ACM Membership Registration Manager ---\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Register New Student\n");
        printf("2. Update Student Info\n");
        printf("3. Delete Student\n");
        printf("4. View All Registrations\n");
        printf("5. Generate Batch-wise Reports\n");
        printf("6. Exit\n");
        
        printf("Please Enter Your Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            continue;
        }
        getchar(); //buffer

        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                updateStudent(filename);
                break;
            case 3:
                deleteStudent(filename);
                break;
            case 4:
                printAllStudents();
                break;
            case 5:
                generateReports();
                break;
            case 6:
                
                saveDatabase(filename);
                freeMemory();
                printf("Exiting And Saving Data...!\n");
                return 0;
            default:
                printf("Invalid Choice! Please Try Again.\n");
        }
    }
    return 0;
}




void loadDatabase(const char *filename) {
    FILE *fp = fopen(filename, "rb"); // reading binary r for read and b for binary
    
    if (fp == NULL) {
        printf("No existing database found. Starting fresh.\n");
        return;
    }

    struct Student temp;

    while (fread(&temp, sizeof(struct Student), 1, fp)) {
        //check if the array size is enough or should be increased:
        if (count == capacity) {
            capacity *= 2;
            students = (struct Student *)realloc(students, capacity * sizeof(struct Student));
            if (students == NULL) {
                printf("Memory expansion failed during loading!\n");
                exit(1);
            }
        }
        //need to be copied from temp to array:
        students[count] = temp;
        count++;
    }

    fclose(fp);
    printf("Database loaded successfully. %d records found.\n", count);
}




//Save all student records from memory to the file:
void saveDatabase(const char *filename) {
    FILE *fp = fopen(filename, "wb"); //  write binary to overright previous data
    
    if (fp == NULL) {
        printf("Error: Could not open file for saving!\n");
        return;
    }


    if (count > 0) {
        fwrite(students, sizeof(struct Student), count, fp);
    }

    fclose(fp);
    
}




//Append a new student record
void addStudent(const char *filename) {
    struct Student newStudent;
    int i;

    printf("\n--- Register New Student ---\n");
    
    printf("Enter Student ID (Format: 25K-1234): ");
    scanf("%s", newStudent.id); 
    getchar(); // consume newline left by scanf

	
	//validation check:
    for (i = 0; i < count; i++) {
        if (strcmp(students[i].id, newStudent.id) == 0) {
            printf("Error: Student ID %s already exists! Registration failed.\n", newStudent.id);
            return;
        }
    }

    printf("Enter Full Name: ");
    fgets(newStudent.name, 100, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // remove newline char

    printf("Enter Batch (CS, SE, Cyber, AI): ");
    fgets(newStudent.batch, 20, stdin);
    newStudent.batch[strcspn(newStudent.batch, "\n")] = 0;

    printf("Enter Membership Type (IEEE / ACM): ");
    fgets(newStudent.type, 10, stdin);
    newStudent.type[strcspn(newStudent.type, "\n")] = 0;

    printf("Enter Registration Date (YYYY-MM-DD): ");
    fgets(newStudent.regDate, 15, stdin);
    newStudent.regDate[strcspn(newStudent.regDate, "\n")] = 0;

    printf("Enter Date of Birth (YYYY-MM-DD): ");
    fgets(newStudent.dob, 15, stdin);
    newStudent.dob[strcspn(newStudent.dob, "\n")] = 0;

    printf("Enter Interest (IEEE/ACM/Both): ");
    fgets(newStudent.interest, 10, stdin);
    newStudent.interest[strcspn(newStudent.interest, "\n")] = 0;

    //Add to memory
    //Resize if it's full
    if (count == capacity) {
        capacity *= 2;
        struct Student *temp = (struct Student *)realloc(students, capacity * sizeof(struct Student));
        if (temp == NULL) {
            printf("Error: Memory allocation failed!\n");
            return;
        }
        students = temp;
    }

    students[count] = newStudent;
    count++;

    
    FILE *fp = fopen(filename, "ab"); //a for append and then the b is for the binary file
    if (fp != NULL) {
        fwrite(&newStudent, sizeof(struct Student), 1, fp);
        fclose(fp);
        printf("Student registered and saved to file successfully.\n");
    } else {
        printf("Error: Could not save to file, but added to memory.\n");
    }
}




//Updating student info:
void updateStudent(const char *filename) {
    char targetID[15];
    int i, found = 0;
    
    printf("\nEnter Student ID To Update (Format: 25K-1234): ");
    scanf("%s", targetID);
    getchar();

    for (i = 0; i < count; i++) {
        
        if (strcmp(students[i].id, targetID) == 0) {
            found = 1;
            printf("Student Found: %s\n", students[i].name);
            
            
            printf("Enter New Batch (CS, SE, Cyber, AI): ");
            fgets(students[i].batch, 20, stdin);
            students[i].batch[strcspn(students[i].batch, "\n")] = 0;

            printf("Enter New Membership Type (IEEE / ACM): ");
            fgets(students[i].type, 10, stdin);
            students[i].type[strcspn(students[i].type, "\n")] = 0;

            printf("Record updated in memory.\n");
            
            break;
        }
        
    }

    if (!found) {
        printf("Error: Student ID not found.\n");
        return;
    }

    //update again:
    saveDatabase(filename);
    printf("Database file updated.\n");
}



//should decrease count
//should remove id and all details
void deleteStudent(const char *filename) {
    char targetID[15];
    int i, j, found = 0;

    printf("\nEnter Student ID to delete (format: 25K-0123): ");
    scanf(" %s", targetID);

    for (i = 0; i < count; i++) {
        
        if (strcmp(students[i].id, targetID) == 0) {
            found = 1;
            
            //shifting all of the remaining elements left inorder to fill the hole
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1]; //no need to shift by using the . as this does it all by itself
            }
            
            count--;
            printf("Student ID %s deleted from memory.\n", targetID); //update
            break;
        }
    }

    if (!found) {
        printf("Error! Student ID not found.\n");
        return;
    }

    saveDatabase(filename);
    printf("Database file updated.\n");
}




void printAllStudents() {
    int i;
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }


    printf("\n%-10s %-20s %-10s %-10s %-12s %-10s\n", "ID", "Name", "Batch", "Type", "Reg Date", "Interest");
    printf("-------------------------------------------------------------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("%-10s %-20s %-10s %-10s %-12s %-10s\n", students[i].id, students[i].name, students[i].batch, students[i].type, students[i].regDate, students[i].interest);
    }
}

//Report:
//printing formart should be used again
void generateReports() {
    char targetBatch[20];
    int i;
    int foundAny = 0;

    printf("\nEnter Batch to filter (CS, SE, Cyber, AI): ");
    fgets(targetBatch, 20, stdin);
    targetBatch[strcspn(targetBatch, "\n")] = 0;

    printf("\n--- Report for Batch: %s ---\n", targetBatch);
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Type", "Interest");

    for (i = 0; i < count; i++) {
        if (strcmp(students[i].batch, targetBatch) == 0) {
        	
            printf("%-10s %-20s %-10s %-10s\n", students[i].id, students[i].name, students[i].type, students[i].interest);
            foundAny = 1;
        }
        
    }

    if (!foundAny) {
        printf("(No students found for this batch)\n");
    }
}


void freeMemory() {
    if (students != NULL) {
        free(students);
        students = NULL;
    }
}


