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
	 * true.  This is the mainn diffence between the do-while
	 * and the while loop.  Notice the body is always executed
	 * at least once in the do-while loop.
	 */

	i = 0;
	do {
		printf("i = %d\n", i);
		i++;
	} while (i < 10);
	return 0;
}
