#include"luong.h"
#include<stdio.h>
#include<time.h>


int main()
{
  int A[20];
  int i;

  srand(time(NULL));

  for(i = 0; i < 20; i++)
    {
      A[i] = rand()%50;
      printf("%d ", A[i]);
    }

  printf("\n\n");

  //sorting A decreasingly
  decreaseInt(A, 20);

  printf("Decreasingly\n");
  for(i = 0; i < 20; i++)
    {
      printf("%d ", A[i]);
    }

  printf("\n\n");

  increaseInt(A, 20);

  printf("Increasingly\n");
  for(i = 0; i < 20; i++)
    {
      printf("%d ", A[i]);
    }
  printf("\n\n");

  return 0;
}
