#include <stdio.h>

int main()
{
	int a, b, c;  	/* declare 3 ints */
	int *x, *y, *z; /* declare 3 pointers to ints. */

	/* initialize a b and c to zero */
	a = 0;
	b = 0;
	c = 0;

	/* the & is the "address of" operator */
	x = &a; /* assign the address of a to x */
	y = &b; /* assign the address of b to y */
	z = &c; /* assign the address of c to z */

	/* We can see what pointers look like: */
	printf("x = %p, y = %p, z = %p\n", x, y, z);

	/* the "unary *" operator accesses whatever a pointer
	 * points to.  We can "dereference" a pointer, meaning, we
	 * access what the pointer points to.
	 */

	*x = 1; /* assign the value 1 to what x points to */
	*y = 2; /* assign the value 2 to what y points to */
	*z = 3; /* assign the value 3 to what z points to */

	printf("a = %d, b = %d, c = %d\n", a, b, c);

	a = 100;
	b = 200;
	c = 300;

	printf("*x = %d, *y = %d, *z = %d\n", *x, *y, *z);

	return 0;
}

