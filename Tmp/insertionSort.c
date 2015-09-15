#include<stdio.h>
#include<time.h>
#include"/home/li/Cprograming/Library/luong.h"

//prototype
//void generateData(char *name, int *A, int len);
void insertionSort(int *A, int len);
void selectionSort(int *A, int len);
void bubbleSort(int *A, int len);

int main(int argv, char **argc)
{

  if(argv != 3){
    printf("Incorrect command.\n");
  }

  int len = 10;
  int i;
  int A[len];

  srand(time(NULL));
  generateData(A, "data10.txt", 0, 1000, len);
  for(i = 0; i < len; i++){
    printf("%d ", A[i]);
  }
  printf("\n");
  printf("Array A after being sorted, using \n");
  bubbleSort(A, len);
  
  for(i = 0; i < len; i++){
    printf("%d ", A[i]);
  }//end for

  printf("\n");

}//end main



void insertionSort(int *A, int len)
{
  int i, j;
  int k;

  for(i = 1; i < len; i++){
    k = A[i];
    j = i - 1;
    
    while(j >= 0 && k < A[j]){
      A[j+1] = A[j];
      j--;
    }

    A[j+1] = k;
  }

}//end insertionSort

void selectionSort(int *A, int len)
{

  int i, j, tmp;
  int max;

  for(i = 0; i < len-1; i++){
    max = i;
    for(j = i+1; j < len; j++){
      if(A[max] < A[j]){
	max = j;
      }
    }
    
    tmp = A[i];
    A[i] = A[max];
    A[max] = tmp;
  }

}


void bubbleSort(int *A, int len)
{

  int swapped = 0;
  int i;
  int tmp;
  do{
    swapped = 0;
    for(i = 0; i < len-1; i++){
      if(A[i] > A[i+1]){
	swapped = 1;
	tmp = A[i];
	A[i] = A[i+1];
	A[i+1] = tmp;
      }//end if
    }//end for
  }while(swapped == 1);

}//end bubbleSort
