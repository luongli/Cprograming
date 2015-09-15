#include<stdio.h>


int main()
{
	int A[100];
	int n = 0,tmp;
	int i=0,j;


	


	do{
		printf(" nhap vao phan tu A[%d]: ",n);
		scanf("%d",&tmp);
		if( tmp==0) break;
		A[n]=tmp;
		n++;
	} while(n<7);
    
    for(i=0;i<n;i++)
    	printf("%d ",A[i]);

    printf("\n");

    for(i = 0; i < n -1; i++)
    	for(j = 1; j < n; j++)
    	{
    		if(A[j-1] > A[j]){
    			tmp = A[j-1];
    			A[j-1] = A[j];
    			A[j] = tmp;
    		}
    	}//end for

    printf("Mang sau khi duoc sap xep:\n");
    for(i=0;i<n;i++)
    	printf("%d ",A[i]);

    printf("\n");
}