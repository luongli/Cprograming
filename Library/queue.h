#include<stdio.h>
#include<stdlib.h>

#define MAX 10
typedef int elementtype;
typedef struct{
  elementtype elements[MAX];
  int front, rear;
}Queue;

void initializeQueue(Queue *q)
{
  q->front = -1;
  q->rear = -1;
}//end initializeQueue

int isEmpty(Queue q)
{
  if(q.front == q.rear) return 1;
  else return 0;
}//end isEmpty

int isFull(Queue q)
{
  if(!isEmpty(q) && (q.rear - q.front)%MAX == 0) return 1;
  else return 0;
}//end isFull

void enQueue(elementtype e, Queue *q)
{
  if(isFull(*q)){
    printf("Warning: The queue is full\n");
    return;
  }//end if

  q->elements[++(q->rear) % MAX] = e;
  
}//end enQueue

elementtype deQueue(Queue *q)
{
  if(isEmpty(*q)){
    printf("The queue is empty.\n");
    return 0;
  }

  return q->elements[++(q->front) % MAX];
}//END deQueue
