#include<stdio.h>
#include"/home/li/Cprograming/Library/luong.h"

//prototype
void quickSort(int *A, int p, int r);
int binarySearch(int *A, int l, int r, int key);
int binarySearchv2(int *A, int l, int r, int key);

int main()
{

  int len = 10;
  int i;
  int A[] = { 1, 5, 2, 8, 4, 9, 23, 51, 2, 15};
  int result;

  printf("Array A before being sorted\n");
  for(i = 0; i < len; i++){
    printf("%d ", A[i]);
  }
  printf("\n");

  quickSort(A, 0, len-1);
  printf("Array A after being sorted\n");
  for(i = 0; i < len; i++) printf("%d ", A[i]);
  printf("\n");

  do{
    printf("Enter an integer you want to find (-1 to exit): ");
    scanf("%d", &i);
    myfflush();
    
    if(i == -1) break;
    
    result = binarySearch(A, 0, 9, i);
    if(result != -1 ) printf("Found at %d\n", result);

    result = binarySearchv2(A, 0, 9, i);
    if(result != -1 ) printf("v2 Found at %d\n", result);

  }while(1);

}//end main

void quickSort(int *A, int l, int r)
{

  if(l < r){
    int pivot = partition(A, l, r);
    quickSort(A, l, pivot-1);
    quickSort(A, pivot+1, r);
  }//end if

}//end quickSort

int partition(int *A, int l, int r)
{

  int x = A[r];
  int i = l - 1;
  int j;

  for(j = l; j < r; j++){
    if(A[j] < A[r]){
      i++;
      swap(&A[i], &A[j]);
    }
  }//end for

  swap(&A[i+1], &A[r]);

  return i+1;

}//end partition


int binarySearch(int *A, int l, int r, int key)
{

  if(l <= r){
    int q = (l+r)/2;
    if(A[q] == key) return q;
    if(A[q] < key) return binarySearch(A, q+1, r, key);
    else return binarySearch(A, l, q-1, key);
  }

  return -1;

}

int binarySearchv2(int *A, int l, int r, int key)
{

  while(l <= r){
    int mid = (l+r)/2;

    if(A[mid] == key) return mid;

    if(A[mid] < key) l = mid+1;
    else r = mid - 1;
  }

  return -1;

}
