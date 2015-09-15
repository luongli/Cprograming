#include<stdio.h>
#include<time.h>
#include"/home/li/Cprograming/Library/luong.h"

//prototype
void maxHeapify(int *A, int i, int n);
void buildMaxHeap(int *A, int n);
void heapSort(int *A, int n);

int main()
{

  char name[] = "data1000.txt";
  int len = 1000;
  int A[len];
  int i;

  srand(time(NULL));

  generateData(A, name, 0, 1000, len);

  printf("Array A before being sorted:\n");
  for(i = 0; i < len; i++) printf("%d ", A[i]);
  printf("\n");

  heapSort(A, len-1);

  printf("Array A after being sorted:\n");
  for(i = 0; i < len; i++) printf("%d ", A[i]);
  printf("\n");

}

void maxHeapify(int *A, int i, int n)
{

  int l = 2*i;
  int r = 2*i+1;
  int max;

  if((l <= n) && (A[l] > A[i])){
    max = l;
  }else max = i;

  if((r <= n) && (A[r]) > A[max]){
    max = r;
  }

  if(max != i){
    swap(&A[i], &A[max]);
    maxHeapify(A, max, n);
  }

}//end maxHeapify

void buildMaxHeap(int *A, int n)
{

  int i;
  for(i = n/2; i >= 0; i--){
    maxHeapify(A, i, n);
  }

}//end buildMaxHeap

void heapSort(int *A, int n)
{
  int i;

  buildMaxHeap(A, n);

  for(i = n; i > 0; i--){
    swap(&A[i], &A[0]);
    maxHeapify(A, 0, i-1);
  }

}//end heapSort
