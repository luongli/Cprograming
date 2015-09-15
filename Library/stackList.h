#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
typedef struct node node;
struct node{
  elementtype element;
  node* next;
};

//node* top;

node *makeNewNode(elementtype e)
{
  node *p = (node*) malloc(sizeof(node));
  p->element = e;
  p->next = NULL;
  
  return p;
}

void initialize(node **top)
{
  *top = NULL;
}

int isEmpty(node **top)
{
  return *top == NULL;
}

void printList(node *p)
{
  if(p == NULL){
  }else{
    do{
      printf("%d ", p->element);
      p=p->next;
    }while(p!=NULL);
  }
}


void push(elementtype e, node **top){
  node *new = makeNewNode(e);
  if(*top == NULL){
    *top = new;
  }else{
    new->next = *top;
    *top = new;
  }//end else

}//end insertBegining

elementtype pop(node **top)
{
  node* del;
  elementtype e;
  if(top == NULL){
    printf("Underflow.\n");
    return -1;
  }

  del = *top;
  e = del->element;
  *top = (*top)->next;
  free(del);
  return e;
}//end delBegining

elementtype getTop(node **top)
{
  if(*top == NULL){
    printf("Overflow\n");
    return 0;
  }
  return (*top)->element;
}

void freeList(node *p)
{
  node *to_free = p;
  while(p != NULL){
    p = p->next;
    free(to_free);
    to_free = p;
  }
}
