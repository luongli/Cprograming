/*
	shift string
*/

#include<stdio.h>
#include<string.h>

#define EXIT 4

void shiftLeft(char s[], int n);	//used to shift a tring by n character
void shiftRight(char s[], int n);	//used to shift a string by n character
int getMenu();						//build menu


int main()
{
	int choice;
	char s[100];

	do
	{
		choice = getMenu();

		getchar();

		//determine and perform user action
		switch(choice)
		{

			case 1:	//enter a string
				printf("Enter a string: ");
				scanf("%[^\n]%*c", s);

				printf("The original string is \"%s\"\n", s);

				break;

			case 2: //shift the string left 1 position
				
				printf("After shift left 1 position:\n");

				shiftLeft(s, 1);

				printf("%s\n", s);

				break;

			case 3: //shift the string right 1 position

				printf("After shift right 1 position:\n");

				shiftRight(s, 1);

				printf("%s\n", s);

				break;


			case 4:
				break;

			default: printf("Invalid Input. Please input again\n");			

		}

	}while(choice != EXIT);
}//end main


/********************************************
*
* get Menu
*
***********************************************/
int getMenu()
{

	int choice;

	printf("\n\n");
	printf("|.|=====================================================|.|\n");
	printf("|.| 1. Enter a string                                   |.|\n");
	printf("|.| 2. Shift string left 1 position                     |.|\n");
	printf("|.| 3. Shift string right 1 position                    |.|\n");
	printf("|.| 4. Exit                                             |.|\n");
	printf("|.|=====================================================|.|\n");
	printf("    Choose an action: ");

	scanf("%d", &choice);

	printf("\n");

	return choice;

}//end getMenu


/**************************************************
*
* shiftLeft
*
***************************************************/
void shiftLeft(char s[], int n)
{

	char tmp;
	int i, j;
	int len = strlen(s);
	char cp[len];

	for(i = 0; i < len; i++)
	{
		if(i < n){
			j = len + i - n;
			cp[j] = s[i];
		} else cp[i-n] = s[i];
	}//end for

	//copy string
	for(i = 0; i < len; i++) s[i] = cp[i];

	
}//end shiftLeft



/**************************************************
*
* shiftRight
*
***************************************************/
void shiftRight(char s[], int n)
{

	char tmp;
	int i, j;
	int len = strlen(s);
	char cp[len];

	for(i = 0; i < len; i++)
	{
		if(i > len - 1 - n){
			j = -len + i + n;
			cp[j] = s[i];
		} else cp[i+n] = s[i];
	}//end for

	//copy string
	for(i = 0; i < len; i++) s[i] = cp[i];

}//end shiftLeft