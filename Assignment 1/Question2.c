#include <stdio.h>

int main(){
	float x,y;
	printf("Please enter X-Coordinate: ");
	scanf("%f", &x);
	printf("Please enter Y-Coordinate: ");
	scanf("%f", &y);
	if (x == 0) {
    	if ( y == 0) {
        	printf("The point (%.0f, %.0f) lies on the origin", x, y);
    	}
    	else {
        	printf("The point (%.0f, %.0f) lies on the y-Axis", x, y);
    	}
	}
	else if (y == 0) {
    	printf("The point (%.0f, %.0f) lies on the x-Axis", x, y);
    }
	else if ((x > 0) && (y > 0)) {
		printf("The point (%.0f, %.0f) lies in quadrant I", x, y);
	}
	else if ((x < 0) && (y > 0)) {
		printf("The point (%.0f, %.0f) lies in quadrant II", x, y);
	}
	else if ((x < 0) && (y < 0)) {
		printf("The point (%.0f, %.0f) lies in quadrant III", x, y);
	}
	else if ((x > 0) && (y < 0)) {
		printf("The point (%.0f, %.0f) lies in quadrant IV", x, y);
	}
	return 0;
}
