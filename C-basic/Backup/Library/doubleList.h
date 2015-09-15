#include<stdio.h>
#include<stdlib.h>

/*typedef struct{
  int mem;
  char ID[20];
} elementtype;
*/

typedef int elementtype;

typedef struct node node;
typedef struct node{
  elementtype element;
  node *next;
  node *prev;
} node;

typedef struct{
  node *first;
  node *last;
  int size;
} DoubleList;

//prototype
int isEmptyDL(DoubleList *q);
void initializeDL(DoubleList *q);
node *makeNewNodeDL(elementtype e);
void insertAtFirstDL(elementtype e, DoubleList *q);
void insertAtLastDL(elementtype e, DoubleList *q);
void delAtLastDL(DoubleList *q);
void freeDL(DoubleList *q);
void insertAfterDL(elementtype e, node *pos, DoubleList *q);
void delNodeDL(node *pos, DoubleList *q);
void printDL(DoubleList q);
void rprintDL(DoubleList q); //print a double linked list from last to first
int positionDL(node *n, DoubleList q); //MODIFY not check
node *searchDL(elementtype key, DoubleList q); //MODIFY
void writeFileDL(char *fileName, DoubleList q);  //MODIFY
void printStructDL(node *n);  //MODIFY 







node *makeNewNodeDL(elementtype e)
{

  node *p = (node *) malloc(sizeof(node));
  if(p == NULL){
    printf("Warning: Memory allocation is failed\n");
    return NULL;
  }

  p->element = e;
  p->next = NULL;
  p->prev = NULL;

  return p;

}//end makeNewNode

void initializeDL(DoubleList *q)
{
  q->first = NULL;
  q->last = NULL;
  q->size = 0;
}//END initializeQueue

int isEmptyDL(DoubleList *q)
{
  return (q->last) == NULL;
}//end isEmpty

void insertAtFirstDL(elementtype e, DoubleList *q)
{
  node *p = makeNewNodeDL(e);
  if(p == NULL){
    return;
  }//end if

  if(isEmptyDL(q)){
    q->first = p;
    q->last = p;
  }else{
    p->next = q->first;
    q->first->prev = p;
    q->first = p;
  }

  (q->size)++;

}//end

void delAtLastDL(DoubleList *q)
{
  if(isEmptyDL(q)){
    printf("List is empty\n");
    return;
  }

  if(q->last == q->first){
    free(q->last);
    q->last = NULL;
    q->first = NULL;
    q->size--;
    return;
  }

  node *to_del = q->last;
  q->last = q->last->prev;
  q->last->next = NULL;
  free(to_del);

  (q->size)--;

}//end


void freeDL(DoubleList *q)
{
  if(isEmptyDL(q)) return;

  node *to_del;

  while(q->first != NULL){
    to_del = q->first;
    q->first = q->first->next;
    free(to_del);
  }//end while

  q->size = 0;
    
}//end freeQueue

void insertAtLastDL(elementtype e, DoubleList *q)
{

  node *p = makeNewNodeDL(e);

  if(p == NULL){
    return;
  }

  if(isEmptyDL(q)){
    q->first = p;
    q->last = p;
  }else{
    p->prev = q->last;
    q->last->next = p;
    q->last = p;
  }

  (q->size)++;

}

void insertAfterDL(elementtype e, node *pos, DoubleList *q)
{
  node *p = makeNewNodeDL(e);

  if(p == NULL) return;

  if(pos->next == NULL){
    insertAtLastDL(e, q);
    return;
  }

  pos->next->prev = p;
  p->prev = pos;
  p->next = pos->next;
  pos->next = p;

  (q->size)++;

}//end insertAfter


void delNodeDL(node *pos, DoubleList *q)
{

  if(pos == NULL) return;

  if(pos == q->first && pos == q->last){
    free(pos);
    q->first = NULL;
    q->last = NULL;
    (q->size)--;
    return;
  }

  if(pos == q->first){
    node *tmp = q->first;
    tmp->next->prev = NULL;
    q->first = tmp->next;
    free(pos);
    (q->size)--;
    return;
  }

  if(pos == q->last){
    node *tmp = q->last;
    tmp->prev->next = NULL;
    q->last = tmp->prev;
    (q->size)--;
    free(pos);
    return;
  }

  pos->prev->next = pos->next;
  pos->next->prev = pos->prev;

  free(pos);

  (q->size)--;

}


void printDL(DoubleList q)
{
  
  if(isEmptyDL(&q)){
    printf("List is empty.\n");
    return;
  }

  node *travel = q.first;

  while(travel != NULL){
    printStructDL(travel);
    travel = travel->next;
  }

}

void rprintDL(DoubleList q)
{
  
  if(isEmptyDL(&q)){
    printf("List is empty.\n");
    return;
  }

  node *travel = q.last;

  while(travel != NULL){
    printStructDL(travel);
    travel = travel->prev;
  }

}



//////////////////////////////////--NEED MODIFIED--///////////////////////////


node *searchDL(elementtype key, DoubleList q)
{

  node *tmp = q.first;

  while(tmp != NULL){
    //if(!strcmp(tmp->element->ID,key)) return tmp;
    if(tmp->element == key) return tmp;
    tmp = tmp->next;
  }

  return NULL;

}//END SEARCH



void writeFileDL(char *fileName, DoubleList q)
{

  FILE *f;
  node *tmp;

  f = fopen(fileName, "w");

  tmp = q.first;

  while(tmp != NULL){
    fprintf(f, "%d \n", tmp->element);
    tmp = tmp->next;
  }

  fclose(f);

}


void printStructDL(node *n)
{

  if(n == NULL) return;

  printf("%d ", n->element);

}


int positionDL(int key, DoubleList q)
{

  int count = 0;

  node *n = searchDL(key, q);
  if(n == NULL) return -1;

  node *tmp = q.first;
  while(tmp != NULL){
    if(tmp == n) return count;
    else count++;
    tmp = tmp->next;
  }

}
