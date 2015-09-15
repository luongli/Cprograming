#include<stdio.h>
#include<time.h>
#include"luong.h"

#define MAX 20

//prototype
void insertionSort(int *A, int len);
void selectionSort(int *A, int len);
void heapSort(int *A, int len);
//void buildHeap(int *A, int len);
void maxHeapify(int *A, int i, int len);
int partition(int *A, int left, int right);
int partition2(int *A, int left, int right);
int partition3(int *A, int left, int right);
void quickSort(int *A, int left, int right);
void printArray(int *A, int left, int right);
void merge(int *A, int p, int q, int r);
void mergeSort(int *A, int p, int r);




void insertionSort(int *A, int len)
{

  int i, j, k;

  for(i = 1; i < len; i++){
    j = i-1;
    k = A[i];
    while(j >= 0 && k < A[j]){
      A[j+1] = A[j];
      j--;
    }//end while
    A[j+1] = k;
  }//end for

}//end insertionSort

void selectionSort(int *A, int len)
{

  int i, j, min, tmp;
  for(i = 0; i < len-1; i++){
    min = i;
    for(j = i+1; j <= len-1; j++)
      if(A[j] < A[min]) min = j;
    tmp = A[i];
    A[i] = A[min];
    A[min] = tmp;
  }

}


/////////////////////////////----HEAP SORT-----////////////////////////////////


void maxHeapify(int *A, int i, int len)
{

  int left = 2*i;
  int right = 2*i + 1;
  int largest;
  int tmp;

  if( (left < len) && (A[i] < A[left]) ) largest = left;
  else largest = i;

  if( (right < len) && (A[largest] < A[right]) ) largest = right;

  if(largest != i){
    tmp = A[i];
    A[i] = A[largest];
    A[largest] = tmp;
    maxHeapify(A, largest, len);
  }//end if

}//end maxHeapify

void heapSort(int *A, int len)
{

  int i;
  int n = len-1;

  for(i = len/2; i > 0; i--){
    maxHeapify(A, i, len);
  }

  for(i = len-1; i>0; i--){
    swapInt(&A[i], &A[1]);
    len--;
    maxHeapify(A, 1, len);
  }

}


//////////////////////////////----QUICK SORT-----/////////////////////////////



int partition(int *A, int left, int right)
{

  int pivot = right;
  int i;
  int j = left;

  for(i = left; i < right; i++){
    if(A[i] < A[pivot]){
      swapInt(&A[i], &A[j]);
      j++;
    }
  }

  swapInt(&A[j], &A[pivot]);

  return j;

}//end partition


void quickSort(int *A, int left, int right)
{
  //printf("left = %d\nright= %d\n", left, right);
  if(left < right){
    int pivot = partition2(A, left, right);
    //printf("pivot = %d\n", pivot);
    //printArray(A, 0, 4);
    //printf("\n\n");
    quickSort(A, left, pivot-1);
    quickSort(A, pivot+1, right);
    
  }
}


void printArray(int *A, int left, int right)
{
  int i;

  for(i = left; i <= right; i++) printf("%d ", A[i]);
  printf("\n");

}

int partition2(int *A, int left, int right)
{

  int mid = (left + right)/2;
  int medium;
  int i;
  int j = left;

  //find medium
  if(A[left] <= A[right]){
    if(A[right] <= A[mid]) medium = right;
    else if(A[left] <= A[mid]) medium = mid;
    else medium = left;
  }else{
    if(A[left] <= A[mid]) medium = left;
    else if(A[right] <= A[mid]) medium = mid;
    else medium = right;
  }

  if(medium != right) swapInt(&A[medium], &A[right]);

  for(i = left; i < right; i++){
    if(A[i] < A[right]){
      swapInt(&A[i], &A[j]);
      j++;
    }
  }

  swapInt(&A[j], &A[right]);

  return j;

}//end partition


///////////////////////---MERGE SORT----/////////////////////////////////////

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





/********
int main()
{

  int A[MAX];
  int B[MAX];
  int C[MAX];
  int i;
  clock_t begin, end;

  srand(time(NULL));

  for(i = 0; i < MAX; i++) A[i] = B[i] = C[i] = rand()%20;

  for(i = 0; i < MAX; i++) printf("%d ", A[i]);
  printf("\n");

  quickSort(A, 0, MAX-1);
  
  for(i = 0; i < MAX; i++) printf("%d ", A[i]);
  printf("\n");

}
********/
