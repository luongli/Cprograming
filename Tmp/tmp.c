#include<stdio.h>

int main(int argc, char **argv)
{
  int i;
  FILE *f;
  
  f = fopen(argv[1], "w+");
  for(i = 2; i < argc; i++)
    fprintf(f, "%s ", argv[i]);

  printf("Done.\n");
  fclose(f);

  return 0;
}//end main


