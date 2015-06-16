//function merge
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "/home/li/Cprograming/luong.h"

#define END 1000000000

//prototype
void merge(int *A, int p, int q, int r);
void mergeSort(int *A, int p, int r);
void generateData(int *A, char *name, int n);
int binarySearch(int *A, int p, int r, int x);

int main(int argv, char **argc){
  int A[10000];
  int len;
  int result;
  int x;
  int i;

  srand(time(NULL));

  if(argv != 3){
    printf("Command is not correct\n");
    return 1;
  }//end if

  len = atoi(argc[2]);

  generateData(A, argc[1], len);
  mergeSort(A, 0, len-1);

  for(i = 0; i < len; i++){
    printf("%d ", A[i]);
  }

  printf("\n");

  do{

    printf("Enter the number you want to find (-1 to exit): ");
    scanf("%d", &x);
    myfflush();

    result = binarySearch(A, 0, len-1, x);

    if(result == -1) printf("Number %d does not appear in the array\n", x);
    else printf("Number %d is A[%d]\n", x, result);

  }while(x != -1);

  return 0;
  
}//end main

void generateData(int *A, char *name, int n)
{
  FILE *f;
  int i;

  f = fopen(name, "w");

  if(f == NULL){
    printf("Opening file error.\n");
    exit(1);
  }
  
  for(i = 0; i < n; i++){
    A[i] = rand()%(n*2);
    fprintf(f, "%d ", A[i]);
    printf("%d ", A[i]);
  }

  fclose(f);
}

void merge(int *A, int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int k;

  int L[n1+1];
  int R[n2+1];
  int i, j;
	
  for(i = 0; i < n1; i++)
    L[i] = A[p+i];

  for(i = 0; i < n2; i++)
    R[i] = A[q+i+1];

  L[n1] = END;
  R[n2] = END;

  i = 0;
  j = 0;

  for(k = p; k <= r; k++){
    
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }//end if else

  }//END FOR

}//end merge

void mergeSort(int *A, int p, int r){
  if(p < r){
    int q = (p+r)/2;
    mergeSort(A, p, q);
    mergeSort(A, q+1, r);
    merge(A, p, q, r);
  }//end if
}//end mergeSort
	

int binarySearch(int *A, int p, int r, int x)
{
  if(p == r){
    if(A[p] == x) return p;
    else return -1;
  }else{

    int q = (p + r)/2;
    if(A[q] == x) return q;
    else{
      if(x < A[q]) binarySearch(A, p, q, x);
      else binarySearch(A, q+1, r, x);
    }//end nested if else

  }//end if else

}//end binarySearch
