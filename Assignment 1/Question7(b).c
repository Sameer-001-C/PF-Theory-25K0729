#include <stdio.h>

int main() {
    int value;
    printf("Please enter a value in the range 1...7: ");
    scanf("%d", &value);
    switch (value)
    {
        case 1: printf("You entered a one and the day is a Monday\n");
		break;
        case 2: printf("You entered a two and the day is a Tuesday\n");
		break;
        case 3: printf("You entered a three and the day is a Wednesday\n");
		break;
        case 4: printf("You entered a four and the day is a Thursday\n");
		break;
        case 5: printf("You entered a five and the day is a Friday\n");
		break;
        case 6: printf("You entered a six and the day is a Saturday\n");
		break;
        case 7: printf("You entered a seven and the day is a Sunday\n");
		break;
        default: printf("You entered a value out of range\n");
    }
    return 0;
}
