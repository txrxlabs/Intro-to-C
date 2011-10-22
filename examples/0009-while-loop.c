#include <stdio.h>

int main()
{
	/* while loop has the following form:
	 *
	 * while (expression)
	 * 	body
	 *
	 * expression can be any expression.
	 *
	 * the body can be a statement or block of statements.
	 *
	 * 1. The expression is evaluated
	 * 2. If true, the body is executed.
	 *    otherwise, leave the loop.
	 * 3. goto 1.
	 */

	int i = 0;

	while (i < 10) {
		printf("i = %d\n", i);
		i++;
	}
	return 0;
}
