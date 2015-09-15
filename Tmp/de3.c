#include<stdio.h>

int main()
{
	float A[100];
	float max;
	int n,i;
    int dem=0;


	do{
		printf(" nhap n:");
		scanf("%d",&n);
		if(n<=0 || n>=10) printf("nhap sai vui long nhap lai\n");
	}while(n<=0 || n>=10);
	
	printf(" nhap phan tu cua mang\n");
	

	for( i=0;i<n;i++)
	{
		printf("nhap A[%d]: ",i);
		scanf("%f",&A[i]);
	}


	for( i=0;i<n;i++)
	{
		printf("%.2f ",A[i]);

	} 
	printf("\n");

	max = A[0];
	for(i=1;i<n;i++)
	{
		if( max<A[i]) max=A[i];
	}
	for(i=0;i<n;i++)
	{
		if(max==A[i])
			dem++;
	}
	printf("gia tri lon nhat cua day so la %f\n",max);
	printf("so luong phan tu bang gia tri lon nhat la:%d \n",dem);

}