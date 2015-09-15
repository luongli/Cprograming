/*
  This is a C library of Luong
 */

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>

/*
  prototype
 */
void trimLeft(char s[]);	//eliminate the spaces at the beginning.
void trimRight(char s[]); 	//eliminate the spaces at the end
void trimMiddle(char s[]);	//eliminate the spaces at the middle of the string
void shiftString(char s[], int n1, int n2);	//shift a string at index n2 to n1
void standardName(char s[]);	//standard name
void increaseInt(int A[], int len);   //sorting an array of int increasingly
void decreaseInt(int A[], int len);   //sorting an array of int decreasingly
void swapInt(int *a, int *b);    //swap two integers
void myfflush();  //clear redundant
FILE *myfopen(char *name, char *mode);
char *changeExtend(char *name, char *extend);


/***************************************
*
* shiftString
*
***************************************/
void shiftString(char s[], int n1, int n2)
{

	int i;

	for(i = n2; i < strlen(s)+1; i++)
	{
		s[i+n1-n2] = s[i];
	}//end for

}//end shiftString


/****************************************
*
* trimLeft
*
*****************************************/
void trimLeft(char s[])
{

	int len = strlen(s);
	int i = 0;

	if(s[i] != ' ') return;
	else
	{
		while(s[i] == ' ') i++;

		shiftString(s, 0, i);
	}

}//end trimLeft


/*****************************************
*
* trimRight
*
******************************************/
void trimRight(char s[])
{
	int len = strlen(s);
	int i = len - 1;

	if(s[i] != ' ') return;
	else
	{
		while(s[i] == ' ') i--;
		s[i+1] = s[len];
	}//end else

}//end trimRight


/***************************************
*
* trimMiddle
*
****************************************/
void trimMiddle(char s[])
{

	int len = strlen(s);
	int i;
	int count;

	for(i = 1; i < len; i++)
	{

		if(s[i] == ' ')
		{
			count = 0;
			while(s[i] == ' '){
				i++;
				count++;
			};

			if(count > 1) shiftString(s, i+1 - count, i);
			i = i + 1 - count;	//update i
		}//end if

	}//end for

}//end trimMiddle


/**********************************************************
*
* standardName
*
***********************************************************/
void standardName(char s[])
{
	int i;

	//eliminate redundant space bars
	trimLeft(s);
	trimRight(s);
	trimMiddle(s);

	//Capitalize the first Character
	if(!isupper(s[0])) s[0] -= 32;
	for(i = 1; i < strlen(s); i++)
	{
		//printf("%d ", i);
		if(s[i] == ' '){
			if(!isupper(s[i+1]))
			{
				s[i+1] -= 32;
				i++;
			}//end nested if
		}//end if

	}//end for
}//end standardName


void swapInt(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

void decreaseInt(int A[], int len)
{
  int i, j;

  for(i = 0; i < len - 1; i++)
    for(j = 1; j < len; j++)
      {
	if(A[j-1] < A[j])
	  {
	    swapInt(&A[j-1], &A[j]);
	  }//end if

      }//end nested for
}//end decreaseInt


void increaseInt(int A[], int len)
{
  int i, j;

  for(i = 0; i < len - 1; i++)
    for(j = 1; j < len; j++)
      {
	if(A[j-1] > A[j])
	  {
	    swapInt(&A[j-1], &A[j]);
	  }//end if

      }//end nested for
}//end increaseInt


// my fflush
void myfflush() {
  int ch;
  while((ch = getchar()) && ch != '\n' && ch != EOF);
}



/**
 * Function: myfopen
 * Open file and handle file error
 */
FILE *myfopen(char *name, char *mode)
{
  FILE *f;

  //open file
  f = fopen(name, mode);
  
  //handle
  if(f == NULL){
    printf("File %s does not exist.\n", name);
    exit(1);
  }//end if

  return f;

}//end myfopen


/**
 * changeExtend
 * change the extend of a file name
 */
char *changeExtend(char *name, char *extend)
{
  int i = 0;

  char *newName;

  do{
    newName[i] = name[i];
    i++;
  }while(name[i] != '.');
  newName[i] = '.';
  strcat(newName, extend);

  return newName;
    
}
