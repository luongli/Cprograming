/**
 * implementing tree structure using linked list
 */
#include<stdio.h>
#include<stdlib.h>
#include "/home/li/Cprograming/Library/luong.h"

typedef struct Node Node;
typedef struct Node{
  int value;
  Node *leftMostChild;
  Node *rightSibling;
} Node;

#define SIZE sizeof(Node)

//prototype
Node *find(Node *r, int v);
Node *createTree(char *fileName);
int countNode(Node *r);
void preOrder(Node *root);
void addChild(Node *root, int value);
void inOrder(Node *root);
void postOrder(Node *root);
int height(Node *r);
int depth(Node *r, int v);

int main()
{
  
  char fileName[50];
  Node *root = NULL;

  printf("Enter data file name: ");
  scanf("%[^\n]", fileName);
  myfflush();

  root = createTree(fileName);
  printf("Done\n");

  //traversal
  printf("PreOrder\n");
  preOrder(root);
  printf("\n");
  printf("inOrder\n");
  inOrder(root);
  printf("\n");
  printf("PostOrder\n");
  postOrder(root);
  printf("\n");

  //count Nodes
  printf("The number of nodes is %d\n", countNode(root));

  Node *h = find(root, 2);
  printf("The height of node h is %d\n", height(h));
  printf("The depth of node 11 is %d\n", depth(root, 11));

  return 0;
}//end main

Node *createTree(char *fileName)
{

  int i, v, n, child;
  Node *p;
  Node *root;
  FILE *f;

  //open file
  f = myfopen(fileName, "r");
  while(1){
    fscanf(f, "%d", &v);
    if(v == -1) break;
    if(root == NULL){
      root = (Node *) malloc(SIZE);
      root->value = v;
      root->leftMostChild = NULL;
      root->rightSibling = NULL;
      p = root;
    }else{
      p = find(root, v);
      if(p == NULL){
	printf("Not found node containing value %d\n", v);
	return;
      }//end if
    }//end else

    fscanf(f, "%d", &n);

    for(i = 0; i < n; i++){
      fscanf(f, "%d", &child);
      addChild(p, child);
    }
    
  }//end while
  close(f);

  return root;

}//end createTree


Node *find(Node *r, int v)
{
  if(r == NULL) return NULL;
  if(r->value == v) return r;
  
  Node *p = r->leftMostChild;

  while(p != NULL){
    Node *pv = find(p, v);
    if(pv != NULL) return pv;
    p = p->rightSibling;
  }//end while

  return NULL;
}//end find


void preOrder(Node *root)
{

  if(root == NULL) return;

  printf("%d ", root->value);
  Node *p = root->leftMostChild;

  while(p != NULL){
    //printf("%d ", p->value);
    preOrder(p);
    p = p->rightSibling;
  }//end while

}//end preOrder

void addChild(Node *root, int value)
{

  //create a child with passed value
  Node *child = (Node *) malloc(sizeof(Node));
  child->value = value;
  child->leftMostChild = NULL;
  child->rightSibling = NULL;

  //add child to the right place
  if(root->leftMostChild == NULL){
    root->leftMostChild = child;
  }else{
    Node *p = root->leftMostChild;

    while(p->rightSibling != NULL) p = p->rightSibling;

    p->rightSibling = child;
  }//end else

}//end addChild


void inOrder(Node *root)
{

  if(root == NULL) return;

  Node *p = root->leftMostChild;
  inOrder(p);
  printf("%d ", root->value);

  while(p != NULL){
    p = p->rightSibling;
    inOrder(p);
  }//end while

}//end inOrder


void postOrder(Node *root)
{

  if(root == NULL) return;

  Node *p = root->leftMostChild;
  
  while(p != NULL){
    postOrder(p);
    p = p->rightSibling;
  }//end while

  printf("%d ", root->value);
}//end postOrder


int countNode(Node *r)
{

  int numNodes = 1;

  if(r == NULL) return 0;

  Node *p = r->leftMostChild;

  while(p != NULL){
    
    numNodes += countNode(p);
    p = p->rightSibling;

  }//end while

  return numNodes;

}//end countNode

int height(Node *r)
{

  int h = 0;

  if(r == NULL){
    return 0;
  }

  Node *p = r->leftMostChild;

  while(p != NULL){
    
    int hi = height(p);
    h = (h > hi) ? h : hi;
    p = p->rightSibling;

  }//end while

  return h+1;

}//end height


int depth(Node *r, int v)
{
  int d = 0;
  if(r == NULL) return 0;
  if(r->value == v) return 1;
  
  Node *p = r->leftMostChild;

  // if(p == NULL) return 0;

  while(p != NULL){
    if(p->value == v) return depth(p, v) + 1;
    else
  }

  return d;

}//end depth
