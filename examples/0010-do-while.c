#include <stdio.h>

int main()
{
	int i;

	/* do while loop has the following form:
	 *
	 * do {
	 * 	body
	 * } while (expression);
	 *
	 * Very similar to the while loop.
	 *
	 * The body is executed while the expression is
	 * true.  Notice the body is always executed at least
	 * once in the do-while loop.  This is the mainn difference
	 * between the do-while and the while loop.
	 */

	i = 0;
	do {
		printf("i = %d\n", i);
		i++;
	} while (i < 10);
	return 0;
}
