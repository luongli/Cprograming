#include<stdio.h>

typedef struct Book{
	char ten[100];
	char nxb[40];
	int gia;
} book_t;



int main()
{
	book_t sach[100];
	int i;
	//char buffer;


	printf("Nhap ten giao trinh: ");
	gets(sach[0].ten);

	/*do{
		printf("Nhap ten giao trinh: ");
		gets(book_t.ten);

	}while()*/

	return 0;
}