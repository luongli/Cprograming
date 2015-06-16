#include<stdio.h>
#include<string.h>
#include"/home/li/Cprograming/luong.h"

int main(int argv, char **argc)
{
  
  int i;
  int A[10000];

  if(argv != 3){
    printf("Wrong command.\n");
    return 1;
  }

  generateData(A, argc[1], -1000, 1000, atoi(argc[2]));

}
