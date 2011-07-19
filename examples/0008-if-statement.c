#include <stdio.h>

int main()
{

	int i;

	for (i = 0; i < 100; i++) {
		printf("i = %d", i);
		if ((i % 2) == 0)
			printf(" which is even");
		else
			printf(" which is odd");
		if ((i % 3) == 0)
			printf(" and divisible by 3");
		printf(".\n");
	}
	return 0;
}

