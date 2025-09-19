#include <stdio.h>

int main() {
	int num = 1;
	int num0 = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0;
	do {
		printf("Please enter a number: ");
		scanf(" %d", &num);
		switch (num) {
			case 0:
				num0++;
				break;
			case 1:
				num1++;
				break;
			case 2:
				num2++;
				break;
			case 3:
				num3++;
				break;
			case 4:
				num4++;
				break;
			case 5:
				num5++;
				break;
			case 6:
				num6++;
				break;
			case 7:
				num7++;
				break;
			case 8:
				num8++;
				break;
			case 9:
				num9++;
				break;
			default:
				printf("\nInvalid Input!\n\n");
		}
	} while ((num >= 0) && (num <= 9));
	printf("Number\tNumber of Occurrences\n");
	printf("0\t%d\n1\t%d\n2\t%d\n3\t%d\n4\t%d\n5\t%d\n6\t%d\n7\t%d\n8\t%d\n9\t%d\n", num0, num1, num2, num3, num4, num5, num6, num7, num8, num9);
	return 0;
}
