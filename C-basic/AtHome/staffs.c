/*
	calculate salary of staffs
*/

#include<stdio.h>
#include<time.h>

#define LENGTH 10

typedef struct
{
	char name[20];
	int age;
	float salary[12];
} Staff;

/*prototype*/
void inputStaffs(Staff *staff, int n);
void printStaffs(Staff *staff, int n);
float calSalary(Staff staff);

int main()
{
	//declare an array of staffs
	Staff staffs[LENGTH];

	//khoi dong bo sinh so
	srand(time(NULL));

	//input staffs
	inputStaffs(staffs, LENGTH);

	printStaffs(staffs, LENGTH);
}//end main

/*
	inputStaffs
*/
void inputStaffs(Staff *staff, int n)
{
	int i; //counter
	int j;

	for(i = 0; i < n; i++)
	{
		//input name
		int k = rand()%19;
		for(j = 0; j < k; j++)
		{
			do{
				staff[i].name[j] = rand()%'z';
			}while(staff[i].name[j] < 'a');
		}//end for
		staff[i].name[k] = '\0';

		//input age
		do{
			staff[i].age = rand()%65;
		}while(staff[i].age < 20);

		//input salary
		for(j = 0; j < 12; j++){
			do{
				staff[i].salary[j] = rand()%200;
			}while(staff[i].salary[j]<100);
		}//end for
	}//end for
}//end inputStaffs

/* printfStaffs*/
void printStaffs(Staff *staff, int n)
{
	int i; //counter

	printf("%-30s%-15s%-20s\n", "Name", "Age", "Total salary");

	for(i = 0; i < n; i++)
	{

		printf("%-30s%-15d%-20f\n", staff[i].name, staff[i].age, calSalary(staff[i]));

	}//end for
}//end printStaffs



/* calculate the salary of staff*/
float calSalary(Staff staff)
{
	int i;
	float total = 0;

	for(i = 0; i < 12; i++)
	{
		total += staff.salary[i];
	}

	return total;
}//end calSalary