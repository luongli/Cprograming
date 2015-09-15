#include<stdio.h>
#include<stdlib.h>
#include"/home/li/Cprograming/Library/luong.h"

int main()
{
  int a;
  char buffer[20];

  //printf("Enter a number: ");
  a = inputInt("Enter a number: ", 0, 100, "range in 0-100");
  toString(a, buffer);
  printf("buffer = %s\n", buffer);
  /*
  do{
    printf("Enter a number (-1 to exit): ");
    scanf("%d", &a);
    myfflush();
    if(a == -1) break;
    toString(a, buffer);
    printf("buffer = %s\n", buffer);
  }while(1);
  */

  printf("Enter a string: ");
  scanf("%[^\n]", buffer);
  myfflush();
  toLower(buffer);
  printf("buffer = %s\n", buffer);
  toUpper(buffer);
  printf("buffer = %s\n", buffer);

}
