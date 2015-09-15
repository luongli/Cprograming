#include<stdio.h>
#include<stdlib.h>
#include"luong.h"
#include"btree.h"


int main(){
  
  btree* root;

  initializeBT(&root);
  insertLeftBT(1, &root);
  insertLeftBT(2, &root);
  insertRightBT(3, &root);

  preOrderBT(root);

}//end main
