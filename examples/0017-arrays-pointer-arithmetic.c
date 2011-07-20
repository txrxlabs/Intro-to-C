#include <stdio.h>
#include <stdint.h>

/* You can create an array of pointers to chars as well */

char *direction[] = {
	"north",
	"northeast",
	"east",
	"southeast",
	"south",
	"southwest",
	"west",
	"northwest",
	"up", 
	"down",
};

/* This is the idiomatic way in C to get the number of elements
 * in a statically initialized array 
 */
#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

void print_array_of_char_ptrs(char *title, char *a[], int nitems)
{
	int i;

	printf("%s\n", title);
	for (i = 0; i < nitems; i++)
		printf("&a[%d] = %p, a[%d] = %p, contains: '%s'\n",
			i, &a[i], i, a[i], a[i]);
}

void print_array_of_ints(char *title, uint32_t *a, int nitems)
{
	int i;
	unsigned int j;
	unsigned char *x;

	printf("%s\n", title);
	for (i = 0; i < nitems; i++) {
		printf("&a[%d] = %p, a[%d] = %u, ",
			i, &a[i], i, a[i]);
		x = (unsigned char *) &a[i];

		printf("memory dump of %d bytes at %p: ", sizeof(a[i]), &a[i]);
		for (j = 0; j < sizeof(a[i]); j++) {
			printf("0x%02hhx ", *x);
			x++;
		}
		printf("\n");
	}
}

/* Now you know enough to be able to understand the proper way 
 * to declare main... 
 */
int main(int argc, char *argv[])
{
	uint32_t x[] = { 0, 1, 2, 3, 4, 5, 6, 0xaabbccdd };

	print_array_of_char_ptrs("Contents of argv[]", argv, argc);
	print_array_of_char_ptrs("Contents of direction[]",
		direction, ARRAYSIZE(direction));
	print_array_of_ints("Array of ints:", x, ARRAYSIZE(x));

	return 0;
}

