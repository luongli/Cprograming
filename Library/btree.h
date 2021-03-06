#include<stdio.h>
#include<stdlib.h>

typedef int bdata;

/*typedef struct bdata{
  //fields here
}
*/

typedef struct btree btree;
typedef struct btree{
  bdata data;
  btree *left;
  btree *right;
} btree;


//prototype
btree *newBTNode(bdata d);
void initializeBT(btree **root);
void insertLeftBT(bdata d, btree **root);
void insertRightBT(bdata d, btree **root);
int isEmpty(btree **root);
btree *rightChild(btree *r);
btree *leftChild(btree *r);
btree *createfrom2(bdata d, btree *l, btree *r);
void printNode(btree *n);  //MODIFY
void preOrderBT(btree *r);

btree *newBTNode(bdata d)
{
  btree *p = (btree *) malloc(sizeof(btree));
  p->data = d;
  p->left = NULL;
  p->right = NULL;
  
  return p;
}

void initializeBT(btree **root)
{
  *root = NULL;
}//END initializeBT

void insertLeftBT(bdata d, btree **root)
{
  btree *p = newBTNode(d);
  
  if((*root) == NULL) (*root) = p;
  else{
    if((*root)->left != NULL){
      printf("ERROR: This node already had left child\n");
      return;
    }else{
      (*root)->left = p;
    }
  }

}


void insertRightBT(bdata d, btree **root)
{
  btree *p = newBTNode(d);
  
  if((*root) == NULL) (*root) = p;
  else{
    if((*root)->right != NULL){
      printf("ERROR: This node already had right child\n");
      return;
    }else{
      (*root)->right = p;
    }
  }

}




int isEmpty(btree **root)
{
  return ((*root) == NULL);
}


btree *rightChild(btree *r)
{
  if(r == NULL) return NULL;

  return r->right;
}


btree *leftChild(btree *r)
{
  if(r == NULL) return NULL;

  return r->left;
}


btree *createfrom2(bdata d, btree *l, btree *r)
{

  btree * new =(btree *)malloc(sizeof(btree));
  if(new != NULL){
    new->data = d;
    new->left = l;
    new->right = r;
  }
  return new;

}


void preOrderBT(btree *r)
{
  if(r == NULL) return;

  printNode(r);
  preOrderBT(r->left);
  preOrderBT(r->right);

}//end preOrder

void printNode(btree *n)
{

  printf("%d ", n->data);

}
