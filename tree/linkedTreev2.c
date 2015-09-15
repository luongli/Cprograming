/**
 * implementing tree structure using linked list
 */
#include<stdio.h>
#include<stdlib.h>
#include "/home/li/Cprograming/luong.h"

typedef struct Node Node;
typedef struct Node{
  int value;
  Node *leftMostChild;
  Node *rightSibling;
} Node;

#define SIZE sizeof(Node)

//prototype
Node *find(Node *r, int v);
void createTree(Node **root, char *fileName);
void preOrder(Node *root);
void inOrder(Node *r);
void postOrder(Node *root);
void addChild(Node *root, int value);

int main()
{
  
  char fileName[50];
  Node *root = NULL;

  printf("Enter data file name: ");
  scanf("%[^\n]", fileName);
  myfflush();

  createTree(&root, fileName);
  printf("Ok\n");
  printf("root = %p\n", root);
  
  //traversal
  printf("Traversal using preorder\n");
  preOrder(root);
  printf("\n");
  printf("Traversal using inorder\n");
  inOrder(root);
  printf("\n");
  printf("Traversal using postOrder\n");
  postOrder(root);
  printf("\n");

  return 0;
}//end main

void createTree(Node **root2, char *fileName)
{

  int i, v, n, child;
  Node *p;
  FILE *f;
  Node *root;

  //open file
  f = myfopen(fileName, "r");
  while(1){
    fscanf(f, "%d", &v);
    if(v == -1) break;
    if(root == NULL){
      root = (Node *) malloc(SIZE);
      (root)->value = v;
      (root)->leftMostChild = NULL;
      (root)->rightSibling = NULL;
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

  *root2 = root;

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


void inOrder(Node *r)
{

  if(r == NULL) return;

  Node *p = r->leftMostChild;
  inOrder(p);
  printf("%d ", r->value);
  //p = p->rightSibling;

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
  }

  printf("%d ", root->value);

}//end postOrder
