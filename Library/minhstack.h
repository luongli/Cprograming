#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node{
  void* element;
  node* next;
};

node *makeNewNode(void* e)
{
  node *new = (node*) malloc(sizeof(node));
  new->element = e;
  new->next = NULL;
  
  return new;
}

int empty(node* top)
{
  return top == NULL;
}

void printList(node **top, char* what)
{
  if(top == NULL)
    return;
  node* tmp = *top;
  while(tmp != NULL){
    printf(what, tmp->element);
    tmp = tmp->next;
  }
  printf("\n");
}


void push(node** top, void* e){
  node *new = makeNewNode(e);
  if(top == NULL){
    *top = new;
  }else{
    new->next = *top;
    *top = new;
  }//end else

}//end insertBegining

void* pop(node **top)
{
  node* del;
  void* e;
  if(*top == NULL){
    printf("Underflow.\n");
    return -1;
  }

  del = *top;
  e = del->element;
  *top = del->next;
  free(del);
  return e;
}//end delBegining

void freeList(node **top)
{
  node *to_free = *top;
  while(*top != NULL){
    *top = to_free->next;
    free(to_free);
    to_free = *top;
  }
}
