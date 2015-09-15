#include<stdio.h>
#include<stdlib.h>
#include"luong.h"
#include"doubleList.h"


int main(){
  
  DoubleList dl;
  int i;
  int len = 10;
  int k;
  int count;

  initializeDL(&dl);

  for(i = 0; i < len; i++) insertAtLastDL(i, &dl);

  printDL(dl);
  printf("\n");

  dlnode * found = searchDL(5, dl);

  insertAfterDL(6, found, &dl);

  printDL(dl);
  printf("\n");
  printf("size = %d\n", dl.size);

  found = searchDL(6, dl);
  delNodeDL(found, &dl);

  printDL(dl);
  printf("\n");

  insertAtFirstDL(0, &dl);
  printDL(dl);
  printf("\n");

  delAtLastDL(&dl);
  printDL(dl);
  printf("size = %d\n", dl.size);
  printf("\n");

  do{
    printf("Enter a key to search:");
    scanf("%d", &k);
    myfflush();
    if(k == -1) break;
    count = positionDL(k, dl);
    if(count != -1) printf("Found at position %d\n", count);
  }while(1);

  do{
    printf("Enter a position: ");
    scanf("%d", &k);
    myfflush();
    if(k == -1) break;
    dlnode *tmp = getNodeAtPosDL(k, dl);
    if(tmp == NULL) continue;
    printf("Found node is %d\n", tmp->element);
  }while(1);

  writeFileDL("duong.txt", dl);

  rprintDL(dl);
  printf("\n");

  while(!isEmptyDL(&dl)){
    delNodeDL(dl.last, &dl);
  }

  printDL(dl);

}//end main
