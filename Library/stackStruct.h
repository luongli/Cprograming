#include<stdio.h>
#include<stdlib.h>

#define MAX 300

typedef int Eltype;
typedef struct {
  Eltype storage[MAX];
  int top;
} StackRec;
typedef StackRec StackType;

void initialize(StackType *stack)
{
  (*stack).top = 0;
}

int full(StackType stack)
{
  return stack.top == MAX;
}

int empty(StackType stack)
{
  return stack.top == 0;
}

void push(Eltype el, StackType *stack)
{
  if(full(*stack))
    printf("Stack overflow.\n");
  else (*stack).storage[(*stack).top++] = el;
}

Eltype pop(StackType *stack)
{
  if(empty(*stack)){
    printf("Stack underflow.\n");
    return -1;
  }else return (*stack).storage[--(*stack).top];
}
