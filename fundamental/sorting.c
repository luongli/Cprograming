/*
	Sorting numbers in an array
*/

#include<stdio.h>
#include<time.h>

#define LENGTH 100

int main()
{
	int A[LENGTH];
	int i, j, tmp;

	//generate random numbers
	srand(time(NULL));

	for(i = 0; i < LENGTH; i++){
		A[i] = rand()%100;
	}

	printf("\nThe value of array A\n");

	//printf raw array A
	for (i = 0; i < LENGTH; ++i)
	{
		printf("%d ", A[i]);
	}

	for(i = 0; i < LENGTH - 1; i++)
		for(j = i; j < LENGTH; j++){
			if(A[i] < A[j]){

				//interchange p[i] and p[j]
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;

			}//end if

		}//end nested for

	printf("\nArray A after sorted\n");

	for (i = 0; i < LENGTH; ++i)
	{
		printf("%d ", A[i]);
	}

	printf("\n");

}//end main

