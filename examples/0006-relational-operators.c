#include <stdio.h>

int main()
{

	int a;

	/*
	 * The relational operators are:
	 *
	 * ==, !=, >, <, >=, <=
	 *
	 */

	/* Notice that when relational operaters are evaluated,
	 * they are integers!
	 * 0 means "false", non-zero means "true"
	 */

	printf("(3 == 3) : %d\n", 3 == 3);
	printf("(0 == 1) : %d\n", 0 == 1);
	printf("(0 != 1) : %d\n", 0 != 1);
	printf("(0 < 1) : %d\n", 0 < 1);
	printf("(0 > 1) : %d\n", 0 > 1);
	printf("(0 >= 1) : %d\n", 0 >= 1);
	printf("(0 <= 1) : %d\n", 0 <= 1);

	/* 
	 * relational operators can be combined with logical operators
	 *
	 * Logical operators are:
	 *
	 * &&, ||, !   ("and", "or" and "not")
	 */

	printf("(1 == 1) && (2 == 2) == %d\n", (1 == 1) && (2 == 2));
	printf("(1 == 0) || (2 == 2) == %d\n", (1 == 0) || (2 == 2));
	printf("((1 == 0) || (2 == 2)) && (0 == 1) == %d\n",
			((1 == 0) || (2 == 2)) && (0 == 1));

	/* ... or, because they are integers, even arithmetic operators!  */

	printf("(1 == 1) * (2 == 2) == %d\n", (1 == 1) * (2 == 2));
	printf("(1 == 0) + (2 == 2) == %d\n", (1 == 0) + (2 == 2));
	printf("((1 == 0) + (2 == 2)) * (0 == 1) == %d\n",
			((1 == 0) + (2 == 2)) * (0 == 1));

	/* Note, since the value of an assignment expression is
	 * the value assigned, it is easy to accidentally use a
	 * single = when you meant to use "=="
	 */

	a = 5;
	printf("The value of a is %d\n", a);
	printf("value of (a == 6): %d\n", a == 6);
	printf("value of (a = 6): %d\n", a = 6);
	printf("The value of a is %d\n", a);

	/* Some people habitually use so-called "Yoda expressions"
	 * to avoid such problems.
	 */
	printf("As Yoda might put it: the value of (6 == a) is %d\n", (6 == a));

	return 0;
}

