#include <stdio.h>

int main(){
	int c1, c2, c3, c4, c5;
	printf("Key:\tAce: 1\n\tTwo: 2\n\tThree: 3\n\tFour: 4\n\tFive: 5\n\tSix: 6\n\tSeven: 7\n\tEight: 8\n\tNine: 9\n\tTen: 10\n\tJack: 11\n\tQueen: 12\n\tKing: 13\n\n");
	printf("ENTER 5 CARDS ONE BY ONE:\n");
	printf("\nEnter First Card: ");
	scanf("%d", &c1);
	printf("Enter Second Card: ");
	scanf("%d", &c2);
	printf("Enter Third Card: ");
	scanf("%d", &c3);
	printf("Enter Fourth Card: ");
	scanf("%d", &c4);
	printf("Enter Fifth Card: ");
	scanf("%d", &c5);
	if (c1 == c2 && c2 == c3 && c4 == c5){ //checking all possible combinations of arranging 5 numbers with 3 cards equal and the other 2 equal
		printf("\nFull House!");
	}
	else if (c1 == c2 && c3 == c4 && c1 == c5){
		printf("\nFull House!");
	}
	else if (c1 == c4 && c2 == c3 && c4 == c5){
		printf("\nFull House!");
	}
	else if (c1 == c2 && c3 == c4 && c4 == c5){
		printf("\nFull House!");
	}
	else if (c1 == c2 && c3 == c5 && c1 == c4){
		printf("\nFull House!");
	}
	else if (c1 == c3 && c2 == c4 && c1 == c5){
		printf("\nFull House!");
	}
	else if (c1 == c3 && c2 == c4 && c4 == c5){
		printf("\nFull House!");
	}
	else if (c1 == c3 && c2 == c5 && c4 == c3){
		printf("\nFull House!");
	}
	else if (c1 == c4 && c2 == c3 && c2 == c5){
		printf("\nFull House!");
	}
	else if (c1 == c5 && c2 == c3 && c3 == c4){
		printf("\nFull House!");
	}
	else{
		printf("\nNot a Full House!");
	}
	return 0;
}
