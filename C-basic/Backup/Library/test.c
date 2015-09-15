#include<stdio.h>
#include<stdlib.h>
#include"luong.h"
#include"doubleList.h"


int main(){
  
  DoubleList dl;
  int i;
  int len = 10;

  initializeDL(&dl);

  for(i = 0; i < len; i++) insertAtLastDL(i, &dl);

  printDL(dl);
  printf("\n");

  node * found = searchDL(5, dl);

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

  writeFileDL("duong.txt", dl);

  rprintDL(dl);
  printf("\n");

  while(!isEmptyDL(&dl)){
    delNodeDL(dl.last, &dl);
  }

  printDL(dl);

}//end main
