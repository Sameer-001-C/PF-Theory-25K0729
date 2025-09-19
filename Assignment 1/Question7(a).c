#include <stdio.h> 

int main() {
	int value; 
	printf("Please enter a value in the range 1...7: "); 
	scanf("%d", &value); 
	//Translate number into its English word 
	if (value == 1) 
	{
		printf("You entered a one and the day is Monday\n"); 
	}
	else if (value == 2)  
	{ 
		printf("You entered a two and the day is a Tuesday\n"); 
	} 
	else if (value == 3)  
	{ 
		printf("You entered a three and the day is a Wednesday\n"); 
	} 
	else if (value == 4)  
	{ 
		printf("You entered a four and the day is a Thursday\n"); 
	} 
	else if (value == 5) 
	{ 
		printf("You entered a five and the day is a Friday\n"); 
	}
	else if (value == 6)
	{
		printf("You entered a six and the day is a Saturday\n");
	}
	else if (value == 7)
	{
		printf("You entered a seven and the day is a Sunday");
	}
	else  
	{  
	printf("You entered a value out of range\n");
	}
	return 0; 
}
