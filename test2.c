#include<stdio.h>
#include<stdlib.h>

typedef struct cobaia {
	int key;
	char texto[80];
	int num;
} cobaia;

int main(int argv, char **argc) {
	int b, c, p[16], i;
	cobaia estrutura[2];

	if (argv == 2) {
		c = atoi (argc[1]);
		syscall(351, 0, NULL, &c, NULL);
		return 0;
	}

	else if (argv == 3) {
		c = atoi (argc[1]);
		b = atoi (argc[2]);
	}

	else return 1;
	//printf("%d\n", b);

	if (c == 1) {
		syscall(351, 2, p, &b, sizeof(int)*16);

		for (i = 0; i < 16; i++)printf("%d\t", p[i]);
		printf ("\n");
	}

	else if (c == 2) {
		syscall(351, 2, estrutura, &b, sizeof(cobaia)*2);

		printf ("key: %d, texto: %s, num: %d\n", estrutura[0].key, estrutura[0].texto, estrutura[0].num);
		printf ("key: %d, texto: %s, num: %d\n", estrutura[1].key, estrutura[1].texto, estrutura[1].num);
	}
	else return 1;

	return 0;
}