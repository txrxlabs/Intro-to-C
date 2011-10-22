#include <stdio.h>

/* literal strings enclosed in double-quotes are actually
 * constant char pointers.  The pointer points to the first
 * character in the string, and there is an (invisible) zero
 * byte (in C, written as the character '\0') which is used
 * by all the string functions in the C library as a sentinel
 * value to mark the end of the string.
 */

char *hello = "hello, world!";

/* Note that you can also declare an array of characters in 
 * a similar way.  hello2 can be thought of as a constant
 * pointer to a character.
 */
char hello2[] = "HELLO, WORLD!";

void dumpstring(char *x)
{
	for (; *x; x++) {
		printf("x = %p, *x = %c, *x = %03hhu\n", 
			x, *x, (unsigned char) *x);
	}
}

void dumpstring2(char x[])
{
	int i;

	for (i = 0; x[i]; i++) {
		printf("&x[%d] = %p, x[%d] = %c, x[%d] = %03hhu\n", 
			i, &x[i], i, x[i], i, (unsigned char) x[i]);
	}
}

int main()
{
	/* notice that you can treat an array of characters as
	 * a (constant) pointer to a character and a pointer to
	 * a character as an array.
	 */
	dumpstring(hello);
	dumpstring2(hello);
	dumpstring(hello2);
	dumpstring2(hello2);

	/* in general, arrays act like constant pointers, and pointers
	 * can be treated as arrays.
	 */
	return 0;
}
