#include <stdio.h>

int main()
{
	int value, i, j;

	printf("Enter a positive integer: ");
	scanf("%d", &value);

	for (i = 0; i < value; i++) {
		for (j = 0; j <= i; j++) 
			printf("*");
		printf("\n");
	}
	return 0;
}
