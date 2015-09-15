/*
	array
*/

#include<stdio.h>


int main()
{
	int A[200];
	int n;
	int count = 0;
	int sum = 0;
	int i;

	//Nhap mang
	printf("Nhap so phan tu: ");
	scanf("%d", &n);

	//nhap tung phan tu
	for(i = 0; i < n; i++)
	{
		printf("Nhap A[%d]: ", i);
		scanf("%d", &A[i]);
	}//end for

	//in mang A thanh 1 day so
	for(i=0; i < n; i++) printf("%d ", A[i]);

	printf("\n");

	printf("\nTinh trung binh cong cac so le.\n");

	for(i = 0; i < n; i++)
	{
		if((A[i]%2) == 1)
		{
			count++;
			sum += A[i];
		}
	}

	if(count == 0) printf("Khong co so le trong day\n");
	else printf("Trung binh cong cua cac so le co trong day la: %f\n", (float)sum/count);

}//end main