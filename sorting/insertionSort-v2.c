#include<stdio.h>
#include<time.h>

#define LENGTH 1000000

//prototype
void generateData(char *fileName, int n);
void readData(char *fileName, int *p);
void insertionSort(int *p, int n);
void printArray(int *p, int n);
void writeOutput(char *fileName, int *p, int n);







int main(int argc, char **argv)
{
  int A[LENGTH];
  int i;

  generateData(argv[1], LENGTH);
  readData(argv[1], A);

  //print the original order of the array
  /*printf("The original array:\n");
  printArray(A, LENGTH);
  */

  /**
   * Insertion sort
   */
  insertionSort(A, LENGTH);
  printf("\n\n\n\nThe array after sorted:\n");
  //printArray(A, LENGTH);
  writeOutput(argv[2], A, LENGTH);

  return 0;

}//end main







//generateData
void generateData(char *fileName, int n)
{

  FILE *f;
  int i;

  f = fopen(fileName, "w+");
  fprintf(f, "%d\n", n);

  srand(time(NULL));
  for(i = 0; i < n; i++)
    fprintf(f, "%d ", rand()%999);
  fclose(f);

}//end generateData






//READDATA
void readData(char *fileName, int *p)
{
  
  int i;
  int n;
  FILE *f;
  
  f = fopen(fileName, "r");
  fscanf(f,"%d", &n);
  
  for(i = 0; i < n; i++)
    fscanf(f, "%d", p++);

  fclose(f);
}



/**
 * define insertionSort
 */
void insertionSort(int *p, int n)
{
  int i, j;
  int pos;
  int key;

  for(i = 1; i < n; i++)
    {
      j = i - 1;
      key = p[i];

      while(j >= 0 && p[j] < key){
	p[j+1] = p[j];
	j--;
      }//end while
      
      p[j+1] = key;
    }//end for

}//end insertionSort





/**
 * define  printArray
 */
void printArray(int *p, int n)
{
  int i;
  
  for(i = 0; i < n; i++)
    printf("%d ", *p++);
    printf("\n");
}


/**
 * define writeOutput
 */
void writeOutput(char *fileName, int *p, int n)
{
  FILE *f;
  int i;

  

  f = fopen(fileName, "w+");
  for(i = 0; i < n; i++)
    {
      fprintf(f, "%d ", p[i]);
    }
  fclose(f);

}//end writeOutput
