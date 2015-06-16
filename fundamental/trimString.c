/*
	trimming string
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define EXIT 4

void trimLeft(char s[]);	//eliminate the spaces at the beginning.
void trimRight(char s[]); 	//eliminate the spaces at the end
void trimMiddle(char s[]);	//eliminate the spaces at the middle of the string
void shiftString(char s[], int n1, int n2);	//shift a string at index n2 to n1
void standardName(char s[]);	//standard name
int getMenu(); 				//build menu

int main()
{
	int choice;
	char s[100];

	do
	{
		
		choice = getMenu();
		getchar();

		//determine and perform action
		switch(choice)
		{

			case 1: //enter a string
				printf("Enter a string: ");
				scanf("%[^\n]%*c", s);//scanf("%[^\n]%*c", s);

				break;

			case 2: //trim string
				trimLeft(s);
				trimRight(s);
				trimMiddle(s);

				printf("s after being trimmed: \"%s\"\n", s);

				break;

			case 3:
				standardName(s);

				printf("your name after being standard: \"%s\"\n", s);

				break;

			case EXIT: break;

			default: printf("Invalid input. Please input again\n");

		}//end switch


	}while(choice != EXIT);

}//end main


/************************************
*
* getMenu
*
*************************************/
int getMenu()
{
	int choice;

	printf("\n\n");
	printf("|.|=========================================================|.|\n");
	printf("|.| 1. Enter a string                                       |.|\n");
	printf("|.| 2. Trim string                                          |.|\n");
	printf("|.| 3. Standard Name                                        |.|\n");
	printf("|.| 4. Exit                                                 |.|\n");
	printf("|.|=========================================================|.|\n");
	printf("    Choose an action: ");
	scanf("%d", &choice);
	printf("\n");

	return choice;
}//end getMenu


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
		printf("%d ", i);
		if(s[i] == ' '){
			if(!isupper(s[i+1]))
			{
				s[i+1] -= 32;
				i++;
			}//end nested if
		}//end if

	}//end for
}//end standardName