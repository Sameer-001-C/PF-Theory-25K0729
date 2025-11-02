#include <stdio.h>

//Bit 0: Power Status (1 = ON, 0 = OFF) 
//Bit 1: Overload Warning (1 = Overloaded, 0 = Normal) 
//Bit 2: Maintenance Required (1 = Yes, 0 = No) A status of 3 (binary 0011) means Power is ON and there's an Overload Warning.



void updatePowerStatus(int grid[][100], int r, int c, int choice) {
	
    switch(choice){
    	
        case 1: //Set power on
            grid[r][c] = grid[r][c] | 1; //001, only last bit is made one
            printf("Power set to On for sector [%d][%d].\n", r, c);
            break;
            
        case 2: //Set Power off
            grid[r][c] = grid[r][c] & 6; //110, only last bit is made zero
            printf("Power set to Off for sector [%d][%d].\n", r, c);
            break;
            
        default:
            printf("Invalid Input! Please Try Again.\n");
    }
}

void updateOverloadStatus(int grid[][100], int r, int c, int choice) {
	
    switch(choice){
    	
        case 1: //Set overloading warning
            grid[r][c] = grid[r][c] | 2; //second last bit is made 1
            printf("Overload warning has been set for sector [%d][%d].\n", r, c);
            break;
            
        case 2: //Clear Overloading warning
            grid[r][c] = grid[r][c] & 5; //secondlast bit is made 0
            printf("Overload warning has been cleared for sector [%d][%d].\n", r, c);
            break;
            
        default:
            printf("Invalid Input! Please try again.\n");
    }
}

void updateMaintenanceStatus(int grid[][100], int r, int c, int choice) {
	
    switch(choice){
        case 1: //Maintenance is required, yes
            grid[r][c] = grid[r][c] | 4;
            printf("Maintenance has been set as required for sector [%d][%d].\n", r, c);
            break;
            
        case 2: //no, maintenance is not required, so clear it now
            grid[r][c] = grid[r][c] & 3; //100 becomes 000
            printf("Maintenance requirement has been cleared for sector [%d][%d].\n", r, c);
            break;
            
        default:
            printf("Invalid Input! Please enter again.\n");
    }
}

void querySectorStatus(int grid[][100], int r, int c) {
	
    int status = grid[r][c];
    
    printf("\nSector [%d][%d] Status Report:\n", r, c);
    printf("Power Status: %s\n", (status & 1) ? "ON" : "OFF");
    printf("Overload Warning: %s\n", (status & 2) ? "OVERLOADED" : "Normal");
    printf("Maintenance Required: %s\n", (status & 4) ? "YES" : "NO");
}

void runSystemDiagnostic(int grid[][100], int rows, int columns) {
	
    int i, j, overloadCount = 0, maintenanceCount = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (grid[i][j] & 2){
                overloadCount++;
            }
            if (grid[i][j] & 4){
                maintenanceCount++;
            }
        }
        
    }

    printf("\nSystem Diagnostic Report:\n");
  
    printf("Total sectors: %d\n", rows * columns);
    printf("Overloaded sectors: %d\n", overloadCount);
    printf("Maintenance required sectors: %d\n", maintenanceCount);
}



int main(){
	int rows, columns, status, choice, i, j, r, c;
	int overloadCount = 0, maintenanceCount = 0;
	
	printf("Please enter the total number of rows in your grid: ");
	scanf("%d", &rows);
	printf("Please enter the total number of columns in your grid: ");
	scanf("%d", &columns);
	
	int grid[rows][100]; //column size fixed to handle function parameters easily
	//need to take input of the status of all the rows??????????????
	
	//initialization of the grid
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            grid[i][j] = 0;
        }
    }
	
	printf("Key:\n\n1. Update Sector Status\n2. Query Sector Status\n3. Run System Diagnostic\n4. Exit\n");
	printf("Please enter your choice: ");
	scanf("%d", &choice);
	
	while(choice != 4){	
		switch(choice){
			case 1: //Update Sector Status
				printf("Please enter grid row: ");
				scanf("%d", &r);
				printf("Please enter grid column: ");
				scanf("%d", &c);
				
				//validation
				
                if (r >= rows || c >= columns || r < 0 || c < 0) {
                    printf("Invalid coordinates!\n");
                    break;
                }				
				
				printf("Key:\n\n1. Set Status Flag\n2. Clear Status Flag");
				printf("Please enter your choice: ");
				scanf("%d", &choice);
				
				switch(choice){
					
					case 1: //Set Status Flag
						printf("Key:\n1. Power Status\n2. Overload Warning\n3. Maintenance Required\n");
						printf("Please enter your choice: ");
						scanf("%d", &choice);
						
						switch(choice){
							
							case 1: //Power Status
								printf("Key:\n1. Set Power ON\n2. Set Power OFF\n");
								printf("Please enter your choice: ");
								scanf("%d", &choice);
								updatePowerStatus(grid, r, c, choice);
								break;
								
							case 2: //Overload Warning
								printf("Key:\n1. Set Overloading Warning\n2. Clear Overloading Warning");
								printf("Please enter your choice: ");
								scanf("%d", &choice);
								updateOverloadStatus(grid, r, c, choice);
								break;
								
							case 3: //Maintenance Required
	                            printf("Key:\n1. Set Maintenance Required\n2. Clear Maintenance Required\n");
                                printf("Please enter your choice: ");
                                scanf("%d", &choice);		
								updateMaintenanceStatus(grid, r, c, choice);
								break;
								
							default:
								printf("Invalid Input! Please Try Again.");
						}
						break;
					
					case 2: //Clear All Status Flags
						grid[r][c] = 0;
						printf("All status flags have been cleared for the sector [%d][%d].\n", r,c);
						break; 
					default:
						printf("Invalid Input! Please Try Again.");
				}
				
				break;
				
			case 2: //Query Sector Status
                printf("Please enter grid row: ");
                scanf("%d", &r);
                printf("Please enter grid column: ");
                scanf("%d", &c);
                
                //validation
                if (r >= rows || c >= columns || r < 0 || c < 0) {
                    printf("Invalid coordinates!\n");
                    break;
                }
				querySectorStatus(grid, r, c);
				break;
				
			case 3: //Run System Diagnostic
				runSystemDiagnostic(grid, rows, columns);
				break;
				
			case 4: //Exit
				printf("Exiting...");
				break;
				
			default:
				printf("Wrong Input! Please enter again.\n");
		}
        printf("Key:\n\n1. Update Sector Status\n2. Query Sector Status\n3. Run System Diagnostic\n4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
	}
	return 0;
}
