#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void usage(char *program)
{
	fprintf(stderr, "usage: %s filename\n", program);
	exit(1);
}

int readfile(int fd, char *buf, int bufsize)
{
	int bytes_left, rc;
	char *b;

	bytes_left = bufsize;	
	b = buf;
	do {	
		rc = read(fd, b, bytes_left);
		if (rc < 0) {
			fprintf(stderr, "read: %s\n", strerror(errno));
			return -1;
		}
		if (rc > 0) {
			bytes_left -= rc;
			b += rc;
		}
	} while (bytes_left > 0);
	return 0;
}

int main(int argc, char *argv[])
{
	int fd, rc, i;
	char *buf = NULL;
	struct stat statbuf;

	/* Check that we've given it the proper number of arguments */
	if (argc < 2)
		usage(argv[0]);

	/* Open the first argument as a file... */
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "open: %s\n", strerror(errno));
		exit(1);
	}

	/* Stat the file, to find out how big it is. */
	rc = fstat(fd, &statbuf);
	if (rc < 0) {
		fprintf(stderr, "stat: %s\n", strerror(errno));
		exit(1);
	}

	/* allocate enough memory to contain the entire file */
	buf = malloc(statbuf.st_size);

	/* Note, testing the return value of malloc is slightly bogus due to
	 * the fact that most modern OSes have a default policy of
	 * overcommitting memory.  The memory isn't actually allocated
	 * by malloc.  Malloc just allocates virtual address space. 
	 * The memory is allocated only when the address is touched.
	 * By then, if it's not there, your process (or some process)
	 * will simply be killed.  Google: linux malloc overcommit
	 */
	if (!buf) {
		fprintf(stderr, "Insufficient memory.\n");
		exit(1);
	}

	/* if malloc lied to us, we'll find out now, rather than later. */
	/* Zero out the entire buffer. */
	memset(buf, 0, statbuf.st_size); /* might segfault if memory is tight */

	/* Read the entire file into the buffer. */
	rc = readfile(fd, buf, statbuf.st_size);
	if (rc < 0)
		exit(1);
	close(fd);

	for (i = 0; i < statbuf.st_size; i++) {
		if ((i % 20) == 0)
			printf("%08i:", i);
		printf("%02hhx ", (unsigned char) buf[i]);
		if (((i + 1) % 20) == 0)
			printf("\n");
	}
	free(buf); /* free the memory.  Valgrind is a nice tool to find mem leaks. */
	exit(0);
}

