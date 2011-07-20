#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void usage(char *program)
{
	fprintf(stderr, "usage: %s filename\n", program);
	exit(1);
}

int main(int argc, char *argv[])
{
	FILE *myfile;

	if (argc < 2)
		usage(argv[0]);

	/* creating a file... */

	myfile = fopen(argv[1], "w+");
		/* "w+" means open for reading/writing, create if needed */ 
	if (!myfile) {
		fprintf(stderr, "fopen: %s\n", strerror(errno));
	}
	fprintf(myfile, "blah blah blah\n");

	fwrite("0123456789", 1, 4, myfile); /* see also: fread() */

	fclose(myfile);
	exit(0);
}

