#include<stdio.h>
#include<stdlib.h>

typedef char* elementtypes;
typedef struct nodes nodes;
struct nodes{
  elementtypes element;
  nodes* next;
};

//nodes* top;

nodes *makeNewNodesS(elementtypes e)
{
  nodes *p = (nodes*) malloc(sizeof(nodes));
  p->element = e;
  p->next = NULL;
  
  return p;
}

void initializeS(nodes **top)
{
  *top = NULL;
}

int isEmptyS(nodes **top)
{
  return *top == NULL;
}

/*
void printListS(nodes *p)
{
  if(p == NULL){
  }else{
    do{
      printf("%d ", p->element);
      p=p->next;
    }while(p!=NULL);
  }
}
*/


void pushS(elementtypes e, nodes **top){
  nodes *new = makeNewNodesS(e);
  if(*top == NULL){
    *top = new;
  }else{
    new->next = *top;
    *top = new;
  }//end else

}//end insertBegining

elementtypes popS(nodes **top)
{
  nodes* del;
  elementtypes e;
  if(top == NULL){
    printf("Underflow.\n");
    return NULL;
  }

  del = *top;
  e = del->element;
  *top = (*top)->next;
  free(del);
  return e;
}//end delBegining

elementtypes getTopS(nodes **top)
{
  if(*top == NULL){
    printf("Overflow\n");
    return NULL;
  }
  return (*top)->element;
}

void freeListS(nodes *p)
{
  nodes *to_free = p;
  while(p != NULL){
    p = p->next;
    free(to_free);
    to_free = p;
  }
}
