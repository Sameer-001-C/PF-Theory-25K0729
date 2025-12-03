/*Question 3: ABC Technologies is a mid-sized software company that wants to build a simple
system to manage its employees’ records. The HR department wants to store and analyze employee
data such as Employee ID, Name, Designation, and Salary. The company plans to use this system
to make quick HR decisions like salary review, promotions, and employee lookup.
ABC Technologies needs a structure that can hold an employee’s information. The HR team wants
to enter data for multiple employees at once. Write a C Code to input records for n employees using
a loop.
The HR manager wants to view all employee records in a readable format.
Design a function displayEmployees() that takes an array of employee structures and displays all
employee details neatly in a table-like format. The finance department needs to know who earns the
highest salary to evaluate seniority and bonuses. Write a function findHighestSalary() that finds and
displays the details of the employee with the highest salary. The HR wants to be able to search
employees either by ID or by name.
Design a function searchEmployee() that can:
? Search by ID (exact match), or
? Search by Name (case-sensitive string comparison).
If the company later wants to give a 10% salary bonus to employees whose salary is below a certain
threshold (say, 50,000), Explain how you could modify your existing program using a function with
structure arrays passed by reference to update salaries directly.
*/

//SALARY REVIEW
//PROMOTIONS
//EMPLOYEE LOOKUP

#include <stdio.h>
#include <string.h>

//our global structure:
struct Employee{
	char EmployeeID[20];
	char Name[50];
	char Designation[50];
	float Salary;	
};


//function prototypes:
void displayEmployees(struct Employee Employees[], int NumEmployees);
void inputEmployees(struct Employee Employees[], int NumEmployees);
void findHighestSalary(struct Employee Employees[], int NumEmployees);
void searchEmployee(struct Employee Employees[], int NumEmployees);
void giveBonus(struct Employee Employees[], int NumEmployees, float threshold);


int main(){
	int n; //total number of employees
	printf("Please enter total number of employees: ");
	scanf("%d", &n);
	struct Employee Employees[n];
	
	printf("\n--- EMPLOYEE DETAILS INPUT ---\n"); //input
	inputEmployees(Employees, n);
	
	printf("\n--- EMPLOYEE DETAILS ---\n"); //display
	displayEmployees(Employees, n);
	
	printf("\n--- HIGHEST SALARY EMPLOYEE DETAILS ---\n"); //find highest salary
	findHighestSalary(Employees, n);
	
	printf("\n--- SEARCH FOR AN EMPLOYEE ---\n"); //search for an employee
	searchEmployee(Employees, n);
	
	float threshold;
	printf("\n--- APPLY THRESHOLD ---\n\n"); //apply threshold to increase salary
	printf("Please enter threshold amount: ");
	scanf("%f", &threshold);
	giveBonus(Employees, n, threshold);
	
	printf("\n--- UPDATED EMPLOYEE DETAILS AFTER BONUS ---\n");
	displayEmployees(Employees, n);

	return 0;
}

void displayEmployees(struct Employee Employees[], int NumEmployees){
	int i;
	if(NumEmployees != 0){
		printf("ID\t\tName\t\tDesignation\t\tSalary\n");
		for(i = 0; i < NumEmployees; i++){
			printf("%s\t\t", Employees[i].EmployeeID);
			printf("%s\t\t", Employees[i].Name);
			printf("%s\t\t", Employees[i].Designation);
			printf("%.2f", Employees[i].Salary);
			printf("\n");
		}
	}
	else{
		printf("No Employee Records Available!\n");
	}
}

void inputEmployees(struct Employee Employees[], int NumEmployees){
	int i;
	for(i = 0; i < NumEmployees; i++){
		printf("Enter Employee ID for employee %d: ", i+1);
		scanf(" %[^\n]", Employees[i].EmployeeID);
		printf("Enter Employee Name for employee %d: ", i+1);
		scanf(" %[^\n]", Employees[i].Name);
		printf("Enter Employee Designation for employee %d: ", i+1);
		scanf(" %[^\n]", Employees[i].Designation);
		printf("Enter Employee Salary for employee %d: ", i+1);		
		scanf("%f", &Employees[i].Salary);
		printf("\n");
	}
}

void findHighestSalary(struct Employee Employees[], int NumEmployees){
	if(NumEmployees == 0){
		printf("No Employee Records Available!\n");
		return;
	}
	//finding employee first:
	int i, indexHighest = 0;
	float temp = Employees[0].Salary;
	for(i = 1; i < NumEmployees; i++){
		if(Employees[i].Salary > temp){
			temp = Employees[i].Salary;
			indexHighest = i;
		}
	}
	//once found, printing details of the employee with higest salary:
	printf("Employee with the higest salary: \n");
	printf("Employee ID: %s\n", Employees[indexHighest].EmployeeID);
	printf("Employee Name: %s\n", Employees[indexHighest].Name);
	printf("Employee Designation: %s\n", Employees[indexHighest].Designation);
	printf("Employee Salary %.2f\n", Employees[indexHighest].Salary);	
}

void searchEmployee(struct Employee Employees[], int NumEmployees){
	int choice;
	printf("KEY:\n1. Search By ID\n2.Search By Name\n");
	printf("Please Enter Your Choice: ");
	scanf("%d", &choice);
	
	int i;
	int searchIndex = -1;
	char searchID[20];
	char searchName[50];
	int found = 0;
	
	switch(choice){
		case 1: //Search By ID (will find exact match)			
			printf("Please enter Employee ID to be searched: ");
			scanf(" %[^\n]", searchID);
			for(i = 0; i < NumEmployees; i++){
				if(strcmp(searchID, Employees[i].EmployeeID) == 0){
					searchIndex = i;
					break;
				}
			}
			if(searchIndex >= 0){
				printf("Employee ID: %s\n", Employees[searchIndex].EmployeeID);
				printf("Employee Name: %s\n", Employees[searchIndex].Name);
				printf("Employee Designation: %s\n", Employees[searchIndex].Designation);
				printf("Employee Salary: %.2f\n", Employees[searchIndex].Salary);	
			}
			else{
				printf("No Employee Found!\n");
			}
			break;
		case 2: //Search By Name
			printf("Please enter Employee Name to be searched: ");
			scanf(" %[^\n]", searchName);
			for(i = 0; i < NumEmployees; i++){
				if(strcmp(searchName, Employees[i].Name) == 0){
					printf("\n");
					printf("Employee ID: %s\n", Employees[i].EmployeeID);
					printf("Employee Name: %s\n", Employees[i].Name);
					printf("Employee Designation: %s\n", Employees[i].Designation);
					printf("Employee Salary: %.2f\n", Employees[i].Salary);
					found = 1;
				}
			}
			if(found == 0){
				printf("No Employee Found!\n");
			}
			break;
		default:
			printf("Invalid Choice!\n");
	}
}



void giveBonus(struct Employee Employees[], int NumEmployees, float threshold){
    int i;
    for(i = 0; i < NumEmployees; i++){
        if(Employees[i].Salary < threshold){
            Employees[i].Salary = Employees[i].Salary * 1.10;
        }
    }
}









