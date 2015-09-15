#include<stdio.h>
//#include"/home/li/Cprograming/Library/luong.h"
#include<time.h>
#include<string.h>

#define MAX_NAME 20

int main(int argv, char **argc)
{

  if(argv > 4){
    printf("Too many arguments!\n");
    return 0;
  }

  if(argv < 3){
    printf("Missing arguments.\n");
    return 0;
  }

  int low = atoi(argc[1]);
  int high = atoi(argc[2]);
  int n = atoi(argc[3]);
  int len = strlen(argc[3]);
  FILE *f;
  char name[MAX_NAME] = "data-";
  int i;
  int range = high - low + 1;

  srand(time(NULL));

  if(len > 10){
    printf("Overflow buffer\n");
    return 0;
  }else{
    strcat(name, argc[3]);
    strcat(name, ".txt");
  }

  f = fopen(name, "w");
  
  for(i = 0; i < n; i++)
    fprintf(f,"%d ", rand()%range+low);

  fclose(f);

}
