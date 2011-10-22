#include <stdio.h>

int main()
{
	int i, j;

	/* The "for loop" has the following form:
         *
         * for (initializer; test; increment) {
         * 	body;
         * }
         *
         * The are 4 parts, the initializer, the test,
         * the increment, and the body.  
         *
         * The initializer can be any statement.
         * The test can be any experession.
         * The increment can by any statement.
         * The body can by any statement or block of statements.
         *
         * All of the parts are optional.
         *
         * The for loop does:
         *
         * 1. executes the initializer.
         * 2. tests the condition (if any)
         * 3. If the condition is not false (or empty)
         *    then
         * 4.       execute the body;
         * 5.       execute the increment
         * 6.       goto step 2.
         * 5. otherwise
         *         the loop is finished.
         *
         */

	printf("count from 0 to 9...\n");
	for (i = 0; i < 10; i++)
		printf("i = %d\n", i);

	printf("\ncount from 0 to 100 by 10's\n");
	for (i = 0; i <= 100; i += 10)
		printf("i = %d\n", i);

	printf("\ncount from 10 down to 1\n");
	for (i = 10; i > 0; i--)
		printf("i = %d\n", i);

	printf("\ncount from 1 to 5, three times\n");
	for (i = 0; i < 3; i++) {
		printf("i = %d\n", i);
		for (j = 1; j <= 5; j++)
			printf("    j = %d\n", j);
	}
	return 0;
}
