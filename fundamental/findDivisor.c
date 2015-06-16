/*
	Find all divisors of a number
*/

#include<stdio.h>
#include<math.h>

int * getDivisors(int n);	//get an array of divisors

int main()
{
	int N;
	int i = 0;
	int *p = NULL;

	printf("Enter a number to find divisors: ");
	scanf("%d", &N);

	p = getDivisors(N);

	while(p[i] != -1){
		printf("%d ", p[i]);
		p++;
	}

	printf("\n");

	return 0;
}//end main 


/************************************************************
*
* getDivisors
*
*************************************************************/
int * getDivisors(int n)
{

	int i;
	int count = 0;
	int Divisors[100]; 	//used to store divisors

	for(i = 1; i <= n/2.0; i++){
		if(n%i == 0) {
			Divisors[count] = i;
			count++;
		}//end if
	}//end for

	Divisors[count] = -1;

	return Divisors;

}//end getDivisors