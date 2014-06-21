#include <stdio.h>
#include <stdlib.h>

/* By combining structs with pointers, we can chain structs together. */

struct list_node {
	char name[100];
	char address[100];
	struct list_node *next;
	/* notice above, the "next" field is a pointer to the same
	 * type of structure that "next" is a member of.
	 */
};

int main(int argc, char *argv[])
{
	struct list_node *my_list = NULL;
}

