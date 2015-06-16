/*
  merge sort and binary search in practice
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "luong.h"
#include<time.h>

#define END 1000000000

//prototype
void merge(int *A, int p, int q, int r);
void mergeSort(int *A, int p, int r);
int binarySearch(int *A, int p, int r, int key);
void generateData(int *A, char *name, int len);
void writeOutput(int *A, char *name, int len);

int main(int argv, char **argc)
{
  
  if(argv != 3){
    printf("Command is not correct\n");
    return 1;
  }

  int len = atoi(argc[2]);
  int i;
  int A[len];
  char *output;
  int sum, key, pos;

  srand(time(NULL));
  
  generateData(A, argc[1], len);

  printf("Generate data done!\n");

  mergeSort(A, 0, len-1);

  printf("Array sorted\n");

  //output the array to screen
  for(i = 0; i < len; i++){
    printf("%d ", A[i]);
  }

  output = changeExtend(argc[1], "out");
  writeOutput(A, output, len);

  //search for the sum in the array
  printf("Enter the sum you want to find: ");
  scanf("%d", &sum);

  i = 0;

  while(((key = sum - A[i]) > 0) && (i < len)){
    pos = binarySearch(A, i+1, len - 1, key);
    
    if(pos != -1){
      printf("A[%d] = %d ---- A[%d] = %d\n", i, A[i], pos, A[pos]);
    }

    i++;
  }

  printf("\nDone search\n");

  //exit(0);


}


void generateData(int *A, char *name, int len)
{
  FILE *f;
  int i;

  f = fopen(name, "w");
  if(f == NULL){ 
    printf("Cannot open file\n");
    return;
  }

  for(i = 0; i < len; i++){
    A[i] = rand()%(2*len);
    printf("%d ", A[i]);
    fprintf(f, "%d ", A[i]);
  }

  fclose(f);
}//end generateData


void mergeSort(int *A, int p, int r)
{
  if(p < r){
    int q = (p + r)/2;
    mergeSort(A, p, q);
    mergeSort(A, q+1, r);
    merge(A, p, q, r);
  }
}

void merge(int *A, int p, int q, int r)
{
  
  int n1 = q - p + 1;
  int n2 = r - q;

  int i, j, k;
  int L[n1 + 1];
  int R[n2 + 1];

  for(i = 0; i < n1; i++) L[i] = A[p + i];
  for(i = 0; i < n2; i++) R[i] = A[q + i + 1];

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
    }
  }

}

int binarySearch(int *A, int p, int r, int key)
{
  if(p == r) return -1;
  else{
    int q = (p + r)/2;
    if(key == A[q]) return q;
    else if(A[q] < key) binarySearch(A, q + 1, r, key);
    else binarySearch(A, p, q, key);
  }
  
}


void writeOutput(int *A, char *name, int len)
{
  
  FILE *f;
  int i;

  f = fopen(name, "w");

  //checking error
  if(f == NULL){
    printf("Cannot open file %s\n", name);
    return;
  }

  for(i = 0; i < len ; i++){
    fprintf(f,"%d ", A[i]);
  }

  fclose(f);

}//end writeOutput
