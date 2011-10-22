#include <stdio.h>

int main()
{

	int i;

	for (i = 0; i < 100; i++) {

		/* Examples of if statements.... */
		printf("i = %d", i);
		if ((i % 2) == 0)
			printf(" which is even");
		else
			printf(" which is odd");
		if ((i % 3) == 0)
			printf(" and divisible by 3");
		printf(".\n");

		/* "Ternary" operator '?' is like a compact if statement
		 * for selecting between two expressions.
		 *
		 * The form of a ternary expression is:
		 *
		 * expr1 ? expr2 : expr3
		 *
		 * where expr1, expr2, and expr3 are expressions.
		 * (the '?' is called the "ternary" operator because
		 * there are three parts.)
		 *
		 * The ternary expression evaluates expr1, and if 
		 * expr1 is true (non-zero), then the value of the whole thing
		 * is the value of expr2.  If expr1 is false (zero) then
		 * then the value of the whole thing is expr3.
		 *
		 * You can think of the "?" as "then" and the ":" as "else"
		 *
		 * You could express: "if I'm thirsty then drink water otherwise
		 * drink nothing" as:
		 *
		 * drink(thirsty ? water : nothing);
		 *
		 * Example usage:
		 */
		printf("%d is %s by 9\n", i, (i % 9) ? "not divisible" : "divisible");
	}
	return 0;
}

