#include <stdio.h>

int main()
{
	int a, b, c;

	printf("Hello, world!\n");

	/* straight forward assignments */
	a = 1;
	b = 2;
	c = a + b;
	printf("a = %d, b= %d, c = %d\n", a, b, c);

	/* b is assigned value of c, then a assigned the value of b 
	 * (same as c) 
	 */
	a = b = c;

	/* Same as: a = a + 1; */
	a += 1;

	/* Same as: b = b - 5; */
	b -= 5;

	/* Almost same as c = c + 1;  */
	c++;

	/* Same as: c = c * 2 */
	c *= 2;

	/* Almost same as c = c - 1; */
	c--;

	/* Almost same as c = c - 1; */
	--c;

	printf("a = %d, b= %d, c = %d\n", a, b, c);

	/* Arithmetic operators
	 * a + b   Addition
	 * a - b   Subtraction
	 * a / b   Division (with integer types, truncates
	 * a * b   Multiplication
	 * a % b   Modulo (remainder after division)
	 * -a      Unary minus
	 * +a      Unary plus
	 */

	return 0;
}

