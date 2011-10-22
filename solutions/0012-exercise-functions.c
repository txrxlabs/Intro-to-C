#include <stdio.h>

int get_number_from_user(char *title)
{
	int n;

	printf("%s", title);
	scanf("%d", &n);
	return n;
}

void print_difference(int n, int m)
{
	printf("%d - %d = %d\n", n, m, n - m);
}

void print_product(int n, int m)
{
	printf("%d * %d = %d\n", n, m, n * m);
}

void print_rectangle(int rows, int columns)
{
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++)
			printf("*");
		printf("\n");
	} 
}

int main()
{
	int n;
	int m;

	do {
		n = get_number_from_user("Enter a number: ");
		m = get_number_from_user("Enter another number: ");
		print_difference(n, m);
		print_product(n, m);
		print_rectangle(n, m);
	} while (n >= 0 && m >= 0);
	return 0;
}

