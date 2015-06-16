/*
	prime number
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int N;
	int i;
	short confirm = 1;

	printf("Enter a number to check whether it is a prime: ");
	scanf("%d", &N);

	for(i = 2; i <= sqrt(N); i++)
	{
		if(N%i == 0)
		{
			confirm = 0;
			break;
		}
	}

	if(confirm == 1) printf("%d is a prime\n", N);
	else printf("%d is not a prime\n", N);

	return 0;
}