#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* By combining structs with pointers, we can chain structs together. */

struct list_node {
	char name[100];
	char nickname[100];
	struct list_node *next;
	/* notice above, the "next" field is a pointer to the same
	 * type of structure that "next" is a member of.
	 */
};

static void add_item_to_front_of_list(struct list_node **list, char *name, char *nickname)
{
	struct list_node *item;

	/* make a new list node */
	item = malloc(sizeof(*item));
	if (!item) {/* if item is NULL */
		printf("out of memory\n");
		return;
	}
	/* fill the new node with the supplied data */
	memset(item->name, 0, sizeof(item->name));
	memset(item->nickname, 0, sizeof(item->name));
	strncpy(item->name, name, sizeof(item->name) - 1);
	strncpy(item->nickname, nickname, sizeof(item->nickname) - 1);

	/* Make the item's next point to the current front of the list */
	item->next = *list;
	/* Make the new front of the list be the new item. */
	*list = item;
}

static void print_list_node(struct list_node *node)
{
	printf("%s : %s\n", node->name, node->nickname);
}

static void print_list(struct list_node *list)
{
	struct list_node *i;

	/* Iterate over the list, printing each element... */
	for (i = list; i != NULL; i = i->next)
		print_list_node(i);
}

int main(int argc, char *argv[])
{
	struct list_node *my_list = NULL;

	add_item_to_front_of_list(&my_list, "Calvin", "Spaceman Spiff");
	add_item_to_front_of_list(&my_list, "Snoopy", "Red Baron");
	print_list(my_list);
	return 0;
}

