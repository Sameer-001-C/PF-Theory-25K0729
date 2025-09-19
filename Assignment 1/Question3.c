#include <stdio.h>

int main(){
	int Age;
	char choice1;
	char choice2;
	char choice3;
	char choice4;
	printf("Please enter your age: ");
	scanf("%d", &Age);
	if (Age >= 18) {
		printf("Have you Passed (P) or Failed (F) your eyesight exam?: ");
		scanf(" %c", &choice1);
		if (choice1 == 'P') {
			printf("Have you Passed (P) or Failed (F) your written exam?: ");
			scanf(" %c", &choice2);
			if (choice2 == 'P') {
				printf("Have you Passed (P) or Failed (F) your driving test?: ");
				scanf(" %c", &choice3);
				if (choice3 == 'P' && Age <= 60) {
					printf("You are eligible for the license.");
				}
				else if (choice3 == 'P' && Age > 60) {
					printf("Do you have a medical fitness certificate? (Y/N): ");
					scanf(" %c", &choice4);
					if (choice4 == 'Y') {
						printf("You are eligible for the license.");
					}
					else {
						printf("Sorry, you are not eligible.");
					}
				}
				else {
					printf("Sorry, you are not eligible.");
				}
			}
			else {
				printf("You need to retake the written exam.");
			}
		}
		else {
			printf("Sorry, you might need a prescription for glasses.");
		}
	}
	else {
		printf("You are ineligible.");
	}
	return 0;
}
