#include <stdio.h>

/* literal strings enclosed in double-quotes are actually
 * constant char pointers.  The pointer points to the first
 * character in the string, and there is an (invisible) zero
 * byte (in C, written as the character '\0') which is used
 * by all the string functions in the C library as a sentinel
 * value to mark the end of the string.
 */
char *hello = "hello, world!";

int main()
{
	char *x = hello;

	for (x = hello; *x; x++) {
		printf("x = %p, *x = %c, *x = %03hhu\n", 
			x, *x, (unsigned char) *x);
	}
	return 0;
}
