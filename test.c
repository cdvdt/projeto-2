#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "test.h"

/*int *a (int size) {
	int **p;
	mycall (size, p);
	return *p;
}*/

typedef struct cobaia {
	int key;
	char texto[80];
	int num;
} cobaia;

int main(void)
{
	int p[16] = {19, 65, 9, 17, 4, 1, 2, 6, 1, 9, 9, 2, 1, 1, 2, 4};
	int b, c;

	cobaia estrutura[2];
	
	syscall(351, 1, p, &b, sizeof(int) * 16);

	printf ("alpha: %d\n", b);

	estrutura[0].key = 0;
	strcpy (estrutura[0].texto, "teste var 0");
	estrutura[0].num = 27;

	estrutura[1].key = 1;
	strcpy (estrutura[1].texto, "teste var 1");
	estrutura[1].num = 27;

	syscall (351, 1, estrutura, &b, sizeof(cobaia) * 2);

	printf ("alpha2: %d\n", b);

	/*	syscall(351, 2, &c, &b, sizeof(int));*/

/*	printf ("beta%d\n", c);*/
}
