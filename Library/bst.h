//binary search tree

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//typedef int bstdata;
typedef struct bstdata{
  char mssv[9];
  char name[30];
  char sdt[12];
  float diem;
} bstdata;

typedef struct bst bst;
typedef struct bst{
  bstdata data;
  bst *left;
  bst *right;
}bst;


//prototype
bst *newBSTNode(bstdata d);               //used to create a node containing data d, function return a pointer
void initializeBST(bst **root);           //used to initialize the bst managed by pointer root

void insertBSTNode(bstdata d, bst **root);//MODIFY
                                          //add an integer/character... into the tree, and then make a bst

bst *leftMostBST(bst *r);                 //used to get the left most child of a bst, return pointer to the child
bst *rightMostBST(bst *r);                //used to get the right most child of a bst, return pointer to the child
bst *parentBST(bst *n, bst *r); //MODIFY  //find parent of a node in bst
void delBSTNode(bst *n, bst **root);      //used to del a node of the bst
int countNodeBST(bst *r);                 //count the number of nodes of a bst
bst *findBST(char *key, bst *r);//MODIFY  //find a value d in bst, return pointer to the node containing d
int heightBST(bst *r);  //not check
int depthBST(bst *n, bst *r);//not check

void printNode(bst *n);  //MODIFY
void preOrderBST(bst *r);
void postOrderBST(bst *r);
void inOrderBST(bst *r);

void writeNode(FILE *f, bst *n); //MODIFY
void preWriteBST(FILE *f, bst *r);
void postWriteBST(FILE *f, bst *r);
void inWriteBST(FILE *f, bst *r);
void freeBST(bst *r);
int lowerThanKey(float key, bst *r);  //MODIFY
int higherThanKey(float key, bst *r); //MODIFY

////////////////////////////////////////define function/////////////////////////////////////////

bst *newBSTNode(bstdata d)
{
  bst *p = (bst *) malloc(sizeof(bst));
  p->left = NULL;
  p->right = NULL;
  p->data = d;

  return p;
}//end newBSTNode

void initializeBST(bst **root)
{
  *root = NULL;
}//end initializeBST


void insertBSTNode(bstdata d, bst **root)
{
  //  bst *p = newBSTNode(d);

  if(*root == NULL){  //if root is null, then add d to bst
    bst *p = newBSTNode(d);
    *root = p;
    return;
  }

  if(strcmp(d.mssv,(*root)->data.mssv)>0) insertBSTNode(d, &((*root)->right));  //MODIFY
  else if(strcmp(d.mssv,(*root)->data.mssv)<0) insertBSTNode(d, &((*root)->left));

}//end addBSTNode

bst *leftMostBST(bst *r)
{
  while(r!=NULL){
    if(r->left == NULL) return r;
    else r = r->left;
  }

  return NULL;
}//end leftMost


bst *rightMostBST(bst *r)
{
  while(r!=NULL){
    if(r->right == NULL) return r;
    else r = r->right;
  }

  return NULL;
}//end rightMost

void freeBST(bst *r){

  if(r == NULL) return; 

  freeBST(r->left);
  freeBST(r->right);
  free(r);

}


void delBSTNode(bst *n, bst **root)
{

  if(n == NULL || *root == NULL) return;

  bst *parent;
  bst *farMost;

  //if left child has more node than right child, then take the right most of it and vice versa
  if(n->left == NULL && n->right == NULL){
    if(n == *root){
      *root = NULL;
      free(n);
      return;
    }
    parent = parentBST(n, *root);
    if(parent->left == n) parent->left = NULL;
    else parent->right = NULL;
    free(n);
  }else if(countNodeBST(n->left) > countNodeBST(n->right)){
    farMost = rightMostBST(n->left);
    parent = parentBST(farMost, *root);
    n->data = farMost->data;

    if(parent->right == farMost) parent->right = farMost->left;
    else parent->left = farMost->left;

    free(farMost);
  }else{
    farMost = leftMostBST(n->right);
    parent = parentBST(farMost, *root);
    n->data = farMost->data;

    if(parent->left == farMost) parent->left = farMost->right;
    else parent->right = farMost->right;

    free(farMost);
  }

}


int countNodeBST(bst *r)
{

  if(r == NULL) return 0;

  int c;

  c = countNodeBST(r->left) + countNodeBST(r->right);

  return c + 1;

}//end countNodeBST


int heightBST(bst *r)
{

  int h = 0;

  if(r == NULL){
    return 0;
  }

  int hi = heightBST(r->left);
  h = (h > hi) ? h : hi;
  hi = heightBST(r->right);
  h = (h > hi) ? h : hi;

  return h+1;

}//end height


int depthBST(bst *n, bst *r)
{
  if(n == NULL) return -1;

  return (heightBST(r) - heightBST(n) +1);
}



void preOrderBST(bst *r)
{
  if(r == NULL) return;

  printNode(r);
  preOrderBST(r->left);
  preOrderBST(r->right);

}//end preOrder

void postOrderBST(bst *r)
{

  if(r == NULL) return;

  postOrderBST(r->left);
  postOrderBST(r->right);
  
  printNode(r);

}//end postOrder

void inOrderBST(bst *r)
{

  if(r == NULL) return;

  inOrderBST(r->left);
  printNode(r);
  inOrderBST(r->right);

}//end inOrder


void preWriteBST(FILE *f, bst *r)
{
  if(r == NULL) return;

  writeNode(f, r);
  preWriteBST(f, r->left);
  preWriteBST(f, r->right);

}//end preWrite

void postWriteBST(FILE *f, bst *r)
{

  if(r == NULL) return;

  postWriteBST(f, r->left);
  postWriteBST(f, r->right);
  
  writeNode(f, r);

}//end postWrite

void inWriteBST(FILE *f, bst *r)
{

  if(r == NULL) return;

  inWriteBST(f, r->left);
  writeNode(f, r);
  inWriteBST(f, r->right);

}//end inWrite



///////////////////////--NEED TO BE MODIFIED--////////////////////////////////

 /*
bst *findBST(char *key, bst *r)
{

  if(r == NULL) return NULL;

  if(!strcmp(r->data.model,key)) return r;  //MODIFY

  if(strcmp(key,r->data.model)>0) return findBST(key, r->right); //MODIFY
  else return findBST(key, r->left);

}//end

*/


bst *parentBST(bst *n, bst *r)
{
  bst *parent;
  
  if(r == NULL || n == NULL) return NULL;
  if( (r->left == n) || (r->right == n) ) return r;
  if(strcmp(n->data.mssv,r->data.mssv)>0) parent = parentBST(n, r->right);  //MODIFY
  else parent = parentBST(n, r->left);

  return parent;
}

/*
int lowerThanKey(float key, bst *r)
{

  int count = 0;

  if(r == NULL) return 0;

  if(r->data.diem < key) {  //MODIFY
    printNode(r);
    count++;
  }

  count += lowerThanKey(key, r->left);
  count += lowerThanKey(key, r->right);

  return count;

}//end lowerThanKey


int higherThanKey(float key, bst *r)
{

  int count = 0;

  if(r == NULL) return 0;

  if(r->data.diem > key) {  //MODIFY
    printNode(r);
    count++;
  }

  count += higherThanKey(key, r->left);
  count += higherThanKey(key, r->right);

  return count;

}//end higherThanKey

*/


void printNode(bst *n)
{

  printf("%-10s%-30s%-15s%-5.2f\n", n->data.mssv, n->data.name, n->data.sdt, n->data.diem);  //MODIFY

}


void writeNode(FILE *f, bst *n)
{

  fprintf(f, "%-10s%-30s%-15s%-5.2f\n", n->data.mssv, n->data.name, n->data.sdt, n->data.diem);  //MODIFY

}
