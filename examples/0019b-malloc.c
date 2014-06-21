#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int *x;

	printf("x = %p\n", x);

	/* malloc allocates however many bytes you ask it to and reterns
	 * a pointer to the memory it allocated.
	 */
	x = malloc(sizeof(int));
	printf("x (after malloc) = %p\n", x);

	/* once allocated, you can use that memory. */
	*x = 10;

	printf("*x = %d\n", *x);

	/* free() releases memory previously allocated by malloc.
	 * it is a mistake to free a pointer not obtained by malloc,
	 * or to free a pointer more than once after a single call
	 * to malloc.
	 */ 
	free(x);
	return 0;
}

