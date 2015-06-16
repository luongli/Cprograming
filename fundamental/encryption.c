/*
	ancient encryption
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define LENGTH 100
#define EXIT 5

void encrypt(char s[], int key);		//encrypt a string with the key
void decrypt(char s[], int key);		//decrypt a encrypted string with the key
int getMenu();	//build getMenu



int main()
{

	int choice;
	char c;
	int key = 0;
	char s[LENGTH];

	do
	{

		choice = getMenu();

		getchar();
		//while((c = getchar()) == '\n') printf("2. %d", c);

		//check;
		//printf("2. %d\n", choice);

		//determine and perform user's action
		switch(choice)
		{

			case 1: //enter text
				printf("1. Enter text\n");
				printf("Enter your text to encrypt:\n");
				scanf("%[^\n]", s);

				break;

			case 2:	//enter key
				printf("2. Enter key\n");
				do
				{
					printf("Enter your key: ");
					scanf("%d", &key);

					if(key <= 0) printf("key must be greater than 0\n");
				}while(key <= 0);

				break;

			case 3:	//encrypt the inputed text
				printf("3. Encrypt the text\n");
				encrypt(s, key);

				printf("The encrypted text:\n%s\n", s);
				printf("Done\n");

				break;

			case 4:	//decrypt the text
				printf("4. Decrypt the text\n");
				decrypt(s, key);

				printf("The decrypted text:\n%s\n", s);
				printf("Done\n");

				break;

			case 5:
				break;

			default: printf("Invalid input. Please input again\n");

		}//end switch

	}while(choice != EXIT);

}//end main


/************************************************************
*
* getMenu
*
*************************************************************/
int getMenu()
{
	int choice;

	printf("\n\n");
	printf("|.|=======================================================|.|\n");
	printf("|.| 1. Enter text                                         |.|\n");
	printf("|.| 2. Enter key                                          |.|\n");
	printf("|.| 3. Encrypt text                                       |.|\n");
	printf("|.| 4. Decrypt text                                       |.|\n");
	printf("|.| 5. Exit                                               |.|\n");
	printf("|.|=======================================================|.|\n");
	printf("    Choose an action: ");

	scanf("%d", &choice);

	printf("\n");

	if(0 < choice < 9) return choice;
	else return 8;

	//return choice;

	//check the input
	//if('0' < choice <= '9' ) return choice - '0';
	//else return 6;

	/*switch(choice)
	{
		case ['1','9']:
			return choice - '0';

		default: return 6;
	}//end switch*/
	

}//end getMenu



/******************************************************************************
*
* encrypt
*
******************************************************************************/
void encrypt(char s[], int key)
{

	int i;

	if(key > 26) key %=  26;

	if(key == 0) return;
	else
	{
		
		for(i = 0; i < strlen(s); i++)
		{
			if(s[i] != ' ')
				{
					if(isupper(s[i]))
					{
						if(s[i] + key > 'Z') s[i] = s[i] + key - 'Z' + 'A' - 1;
						else s[i] = s[i] + key;
					}
					else
					{
						if(s[i] + key > 'z') s[i] = s[i] + key - 'z' + 'a' - 1;
						else s[i] = s[i] + key;
					}
					
				}//end if
			
		}//end for

	}//end else

}//end encrypt




/******************************************************************************
*
* decrypt
*
******************************************************************************/
void decrypt(char s[], int key)
{

	int i;

	if(key > 26) key %=  26;

	if(key == 0) return;
	else
	{
		
		for(i = 0; i < strlen(s); i++)
		{
			if(s[i] != ' ')
			{
				if(isupper(s[i]))
				{
					if(s[i] - key < 'A') s[i] = s[i] - key + 'Z' - 'A' + 1;
					else s[i] = s[i] - key;
				}
				else
				{
					if(s[i] - key < 'a') s[i] = s[i] - key + 'z' - 'a' + 1;
					else s[i] = s[i] - key;
				}
			}//end if
		}//end for

	}//end else

}//end decrypt