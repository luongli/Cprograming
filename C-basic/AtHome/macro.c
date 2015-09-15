#include<stdio.h>
#include"/home/li/Cprograming/Library/luong.h"

#define PI 3.14
#define CIRCLE_AREA(x) (PI * (x) * (x))
#define DEBUG 0
#define _TIME_ 3

int main()
{
  int r;

  do{
    printf("Enter the radius (-1 to exit): ");
    scanf("%d", &r);
    #ifdef DEBUG
    printf("r = %d\n", r);
    //printf("_LINE_ = %d\n", _LINE_);
    printf("_TIME_ = %d\n", _TIME_);
    #endif
    if(r == -1) break;
    printf("The area of the circle is %.3f\n", CIRCLE_AREA(r));
  }while(1);

}
