#include <stdio.h>

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

#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

void print_array_of_char_ptrs(char *title, char *a[], int nitems)
{
	int i;

	printf("%s\n", title);
	for (i = 0; i < nitems; i++)
		printf("&a[%d] = %p, a[%d] = %p, contains: '%s'\n",
			i, &a[i], i, a[i], a[i]);
}

/* Now you know enough to be able to understand the proper way 
 * to declare main... 
 */
int main(int argc, char *argv[])
{
	print_array_of_char_ptrs("Contents of argv[]", argv, argc);
	print_array_of_char_ptrs("Contents of direction[]",
		direction, ARRAYSIZE(direction));
	return 0;
}
	
		
