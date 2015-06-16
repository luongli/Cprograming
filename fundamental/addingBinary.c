/**
 * adding two binary numbers
 */

#include<stdio.h>
#include<time.h>

#define LENGTH 20

//prototype
void generateBinary(int *p, int len);
void printBinary(int *p, int len);
//void addBinary(int *p1, int *p2, int len);

int main()
{
  int A[LENGTH];
  int B[LENGTH];
  int C[LENGTH + 1] = { 0 };
  int i;

  srand(time(NULL));

  generateBinary(A, LENGTH);
  printf("A = \t ");
  printBinary(A, LENGTH);

  generateBinary(B, LENGTH);
  printf("B = \t ");
  printBinary(B, LENGTH);

  //adding two binary
  for(i = LENGTH-1; i >= 0; i--){
    if ( A[i] + B[i] + C[i+1] < 2 )
      C[i+1] = A[i] + B[i] + C[i+1];
    else {
      if ( A[i] + B[i] + C[i+1] == 2  ) {
	C[i+1] = 0;
	C[i] = 1;
      }else
	C[i] = 1;	
    }//end else
  }//end for

  printf("C = \t");
  printBinary(C, LENGTH+1);

  return 0;
  
}//end main


void generateBinary(int *p, int len)
{
  int i;
  
  for(i = 0; i < len; i++){
    p[i] = rand()%2;
  }//end for

}//end generateBinary

void printBinary(int *p, int len)
{
  int i;

  for(i = 0; i < len; i++){
    printf("%d", *(p++));
  }

  printf("\n");
}

