#include<stdio.h>
#include<stdlib.h>

/*typedef struct{
  int mem;
  char ID[20];
} elementtype;
*/

typedef int elementtype;

typedef struct dlnode dlnode;
typedef struct dlnode{
  elementtype element;
  dlnode *next;
  dlnode *prev;
} dlnode;

typedef struct{
  dlnode *first;
  dlnode *last;
  int size;
} DoubleList;

//prototype
int isEmptyDL(DoubleList *q);
void initializeDL(DoubleList *q);
dlnode *makeNewNodeDL(elementtype e);
void insertAtFirstDL(elementtype e, DoubleList *q);
void insertAtLastDL(elementtype e, DoubleList *q);
void delAtLastDL(DoubleList *q);
void freeDL(DoubleList *q);
void insertAfterDL(elementtype e, dlnode *pos, DoubleList *q);
void delNodeDL(dlnode *pos, DoubleList *q);
void printDL(DoubleList q);
void rprintDL(DoubleList q); //print a double linked list from last to first
dlnode *getNodeAtPosDL(int pos, DoubleList q);

/////////////////////--NEED TO BE MODIFIED--////////////////////////////////
int positionDL(int key, DoubleList q); //MODIFY not check
dlnode *searchDL(elementtype key, DoubleList q); //MODIFY
void writeFileDL(char *fileName, DoubleList q);  //MODIFY
void printStructDL(dlnode *n);  //MODIFY 







dlnode *makeNewNodeDL(elementtype e)
{

  dlnode *p = (dlnode *) malloc(sizeof(dlnode));
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
  dlnode *p = makeNewNodeDL(e);
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

  dlnode *to_del = q->last;
  q->last = q->last->prev;
  q->last->next = NULL;
  free(to_del);

  (q->size)--;

}//end


void freeDL(DoubleList *q)
{
  if(isEmptyDL(q)) return;

  dlnode *to_del;

  while(q->first != NULL){
    to_del = q->first;
    q->first = q->first->next;
    free(to_del);
  }//end while

  q->size = 0;
    
}//end freeQueue

void insertAtLastDL(elementtype e, DoubleList *q)
{

  dlnode *p = makeNewNodeDL(e);

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

void insertAfterDL(elementtype e, dlnode *pos, DoubleList *q)
{
  dlnode *p = makeNewNodeDL(e);

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


void delNodeDL(dlnode *pos, DoubleList *q)
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
    dlnode *tmp = q->first;
    tmp->next->prev = NULL;
    q->first = tmp->next;
    free(pos);
    (q->size)--;
    return;
  }

  if(pos == q->last){
    dlnode *tmp = q->last;
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

  dlnode *travel = q.first;

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

  dlnode *travel = q.last;

  while(travel != NULL){
    printStructDL(travel);
    travel = travel->prev;
  }

}


dlnode *getNodeAtPosDL(int pos, DoubleList q)
{

  int i;
  dlnode *tmp = q.first;

  if(pos >= q.size){
    printf("ERROR: Enter position is greater than the size of list\nFile: %s %d\n", __FILE__, __LINE__);
    return NULL;
  }
  
  for(i = 0; (i < pos) && (tmp != NULL); i++){
    tmp = tmp->next;
  }

  return tmp;

}



//////////////////////////////////--NEED MODIFIED--///////////////////////////


dlnode *searchDL(elementtype key, DoubleList q)
{

  dlnode *tmp = q.first;

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
  dlnode *tmp;

  f = fopen(fileName, "w");

  tmp = q.first;

  while(tmp != NULL){
    fprintf(f, "%d \n", tmp->element);  //MODIFY HERE
    tmp = tmp->next;
  }

  fclose(f);

}


void printStructDL(dlnode *n)
{

  if(n == NULL) return;

  printf("%d ", n->element);  //MODIFY HERE

}


int positionDL(int key, DoubleList q)
{

  int count = 0;

  dlnode *n = searchDL(key, q);  //MODIFY PARAMETER KEY
  if(n == NULL) return -1;

  dlnode *tmp = q.first;
  while(tmp != NULL){
    if(tmp == n) return count;
    else count++;
    tmp = tmp->next;
  }

}
