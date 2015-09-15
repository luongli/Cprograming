#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int h;
  int min;
  int wait;
} elementtype;
typedef struct node node;
typedef struct node{
  elementtype element;
  node *next;
  } node;*/

typedef struct{
  node *front;
  node *rear;
  int size;
} QueueList;


node *makeNewNodeQ(elementtype e)
{

  node *p = (node *) malloc(sizeof(node));
  if(p == NULL){
    printf("Warning: Memory allocation is failed\n");
    return NULL;
  }

  p->element = e;
  p->next = NULL;

  return p;

}//end makeNewNode

void initializeQueue(QueueList *q)
{
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;
}//END initializeQueue

int isEmpty(QueueList *q)
{
  return (q->rear) == NULL;
}//end isEmpty

void enQueue(elementtype e, QueueList *q)
{
  node *p = makeNewNodeQ(e);
  if(p == NULL){
    printf("Queue is full\n");
    return;
  }//end if

  if(isEmpty(q)){
    q->front = p;
    q->rear = p;
    (q->size)++;
  }else{
    q->front->next = p;
    q->front = p;
    (q->size)++;
  }

}//end enQueue

elementtype deQueue(QueueList *q)
{
  if(isEmpty(q)){
    printf("Queue is empty\n");
    return ;
  }

  elementtype value = q->rear->element;
  node *to_del = q->rear;
  q->rear = q->rear->next;
  (q->size)--;
  free(to_del);
  
  return value;

}//end deQueue

void freeQueue(QueueList *q)
{
  if(isEmpty(q)) return;

  node *to_del;

  while(q->rear != NULL){
    to_del = q->rear;
    q->rear = q->rear->next;
    free(to_del);
  }//end while
    
}//end freeQueue

/*
void printQueue(QueueList q)
{
  
  if(isEmpty(&q)){
    printf("Queue is empty.\n");
    return;
  }

  node *travel = q.rear;

  while(travel != NULL){
    printf("%-15s%-10dwaiting\n", travel->element.ID, travel->element.mem);
    travel = travel->next;
  }

}//end printQueue
*/
