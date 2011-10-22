#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
 * Your program starts with the open file pointers, of type
 * FILE *.
 *
 * stdin, stdout, stderr
 */

int main(int argc, char *argv[])
{
	char str[100], *x;
	int len;

	fprintf(stderr, "Here is some text to stderr\n");
	fprintf(stdout, "Here is some text to stdout\n");
	
	do {
		printf("Please enter some text from stdin: ");
		x = fgets(str, 100, stdin);
		if (x) {
			/* Fgets will leave the trailing ctrl-M on the string.
			 * We want to cut it off.
			 */
			len = strlen(str);
			if (len > 0)
				str[len - 1] = '\0';
			printf("You typed: '%s'\n", str);
		}
	} while (!feof(stdin));
	printf("\n");
	exit(0); /* flushes and closes open files */
}

