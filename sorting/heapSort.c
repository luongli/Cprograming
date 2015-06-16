#include<stdio.h>
#include"luong.h"

//prototype
void max_heapify(int *, int, int);
void build_max_heap(int *, int);
void heap_sort(int *, int);
void loadFile(int *, char *, int);
void printArray(int *, int);

int main(int argv, char **argc)
{

  if(argv < 3){
    printf("ERROR: Missing argument\n");
    return 0;
  }

  if(argv > 3){
    printf("ERROR: Too many arguments\n");
    return 0;
  }

  int len = atoi(argc[2]);
  int A[len+1];
  int i;

  //load file
  loadFile(A, argc[1], len);

  for(i = 1; i <= len; i++) printf("%d ", A[i]);
  printf("\n");

  heap_sort(A, len);

  printf("Array after being sorted\n");
  for(i = 1; i <= len; i++) printf("%d ", A[i]);
  printf("\n");

}

void max_heapify(int *A, int i, int len)
{
	int left = 2*i;
	int right = 2*i+1;
	int largest, tmp;

	if( (left <= len) && (A[i] < A[left]) )	largest = left;
	else largest = i;

	if( (right <= len) && (A[largest] < A[right]) ) largest = right;

	if(largest != i){
		tmp = A[largest];
		A[largest] = A[i];
		A[i] = tmp;
		max_heapify(A, largest, len);
	}
}


void build_max_heap(int *A, int len)
{
  int i;
	for(i = len/2; i > 0; i--)
		max_heapify(A, i, len);
}

void heap_sort(int *A, int len)
{
  int i;
	build_max_heap(A, len);
	for(i = len; i >= 1; i--){
		swapInt(&A[i], &A[1]);
		//printArray(A, len);
		len--;
		max_heapify(A, 1, len);
	}
}

void loadFile(int *A, char *name, int len)
{

  FILE *f;
  int i;
  
  f = fopen(name, "r");

  for(i = 1; i <= len; i++) fscanf(f,"%d ", &A[i]);

  fclose(f);

}

void printArray(int *A, int len)
{

  int i ;
  
  for(i = 1; i <= len; i++) printf("%d ", A[i]);
  printf("\n");

}
