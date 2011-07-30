#include <stdio.h>

int main()
{
	int i;

	for (i = 1; i <= 100; i++) {
		if ((i % 3) == 0 && (i % 5) == 0) {
			printf("fizzbuzz\n");
		} else {
			if ((i % 3) == 0) {
				printf("fizz\n");
			} else {
				if ((i % 5) == 0) {
					printf("buzz\n");
				} else {
					printf("%d\n", i);
				}
			}
		}
	}

#if 0
	/* alternately, a slightly more compact solution... */

	for (i = 1; i <= 100; i++) {
		if ((i % 3) != 0 && (i % 5) != 0) {
			printf("%d\n", i);
			continue;
		}
		if ((i % 3) == 0)
			printf("fizz");
		if ((i % 5) == 0)
			printf("buzz");
		printf("\n");
	}
#endif
	return 0;
}

