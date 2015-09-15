//binary search tree

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//typedef int bstdata;
typedef struct bstdata{
  char model[20];
  char RAM[10];
  float size;
  float cost;
} bstdata;

typedef struct bst bst;
typedef struct bst{
  bstdata data;
  bst *left;
  bst *right;
}bst;


//prototype
bst *newBSTNode(bstdata d);     //used to create a node containing data d, function return a pointer
void initializeBST(bst **root); //used to initialize the bst managed by pointer root
void insertBSTNode(bstdata d, bst **root);     //add an integer/character... into the tree, and then make a bst
bst *leftMostBST(bst *r);      //used to get the left most child of a bst, return pointer to the child
bst *rightMostBST(bst *r);     //used to get the right most child of a bst, return pointer to the child
bst *parentBST(bst *n, bst *r); //find parent of a node in bst
void delBSTNode(bst *n, bst **root);//used to del a node of the bst
int countNodeBST(bst *r);      //count the number of nodes of a bst
bst *findBST(char *key, bst *r);   //find a value d in bst, return pointer to the node containing d
void preOrderBST(bst *r);
void freeBST(bst **r);

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

  if(strcmp(d.model,(*root)->data.model)>0) insertBSTNode(d, &((*root)->right));
  else if(strcmp(d.model,(*root)->data.model)<0) insertBSTNode(d, &((*root)->left));

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

/*
void delBSTNode(bst *n, bst **root)
{
  bst *parent;
  if(n == NULL || *root == NULL) return;
  if((n->left == NULL) && ( n->right == NULL )) { //if r is a leaf, delete r immediatetly
    parent = parentBST(n, *root);
    if(parent->left == n) parent->left = NULL;
    else parent->right = NULL;
    free(n);    
  } else if( (n->left == NULL) || (n->right == NULL) ){     //if r has only 1 child
    if(n->left == NULL){
      parent = parentBST(n, *root);
      if()
    }
  }
}
*/

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


bst *parentBST(bst *n, bst *r)
{
  bst *parent;
  
  if(r == NULL || n == NULL) return NULL;
  if( (r->left == n) || (r->right == n) ) return r;
  if(strcmp(n->data.model,r->data.model)>0) parent = parentBST(n, r->right);
  else parent = parentBST(n, r->left);

  return parent;
}

int countNodeBST(bst *r)
{

  if(r == NULL) return 0;

  int c;

  c = countNodeBST(r->left) + countNodeBST(r->right);

  return c + 1;

}//end countNodeBST

void preOrderBST(bst *r)
{
  if(r == NULL) return;

  printf("%-15s%-15s%-15.0f%-15.3f\n", r->data.model, r->data.RAM, r->data.size, r->data.cost);
  preOrderBST(r->left);
  preOrderBST(r->right);

}

bst *findBST(char *key, bst *r)
{

  if(r == NULL) return NULL;

  if(!strcmp(r->data.model,key)) return r;

  if(strcmp(key,r->data.model)>0) return findBST(key, r->right);
  else return findBST(key, r->left);

}//end

void freeBST(bst **r){
  return; 
}
