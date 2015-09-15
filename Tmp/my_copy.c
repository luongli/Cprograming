#include<stdio.h>
#include "/home/li/Cprograming/Library/luong.h"

#define MAX 100
#define B_MAX 1000

void get_input(char *buffer, int size)
{
  int i;
  char ch;

  for(i = 0; i < size; i++){
    ch = getchar();

    if(ch != '\n')
      buffer[i] = ch;
    else{
      buffer[i] = '\0';
      break;
    }
    
  }//end for

  myfflush();

}//end get_input

int main()
{

  char source[MAX] = {0};
  char target[MAX] = {0};
  int i;
  FILE *f_in, *f_out;
  char buffer[B_MAX];

  do{
    printf("Enter the source file name: ");
    get_input(source, MAX);
    printf("source = \"%s\"\n", source);
    f_in = fopen(source, "r");
    if(f_in == NULL) printf("File %s not found\n", source);
  }while(f_in == NULL);

  printf("Enter the target file name: ");
  get_input(target, MAX);
  
  f_out = fopen(target, "w");
  
  // copy file
  while(fgets(buffer, B_MAX, f_in) != NULL){
    fputs(buffer, f_out);
  }

  printf("Done.\n");

  fclose(f_in);
  fclose(f_out);

}
