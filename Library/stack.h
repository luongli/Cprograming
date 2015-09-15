#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef int Eltype;
typedef Eltype StackType[MAX];

int top;

void initialize(StackType stack)
{
  top = 0;
}

int empty(StackType stack)
{
  return top == 0;
}

int full(StackType stack)
{
  return top == MAX;
}

void push(Eltype el, StackType stack)
{
  if(full(stack))
    printf("Stack overflow");
  else stack[top++] = el;
}

Eltype pop(StackType stack)
{
  if(empty(stack)){
    printf("Stack overflow.\n");
    return -1;
  }else return stack[--top];
}
