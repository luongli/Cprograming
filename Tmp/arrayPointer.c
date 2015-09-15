/*
	Array pointer
*/

#include<stdio.h>



int main()
{
	int i, j, n, min, tmp, k;

	int a[100];

	int* p = NULL;

	p = a;

	printf("Enter N: ");
	scanf("%d", &n);

	for(i = 0; i < n; i++){
		printf("Enter N %d :", i);
		scanf("%d", p++);
	}

	for(i = n; i >= 2; i--){
		for (j = 1; i < i - 1; ++i)
		{
			if(a[j] < a[j+1]){
				tmp = a[j];
				a[j] = a[j+ 1];
				a[j + 1] = tmp;
			}
		}
	}

	for(i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

}