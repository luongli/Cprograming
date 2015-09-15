/**
* union example
*/
#include<stdio.h>

typedef union{
	int x;
	double y;
} number;

int main()
{
	number value = { 10 };

	printf("Value of  x is %d\nValue of y is %lf\n", value.x, value.y);

	value.y = 89837;

	printf("Value of  x is %d\nValue of y is %lf\n", value.x, value.y);

	return 0;
}//end main