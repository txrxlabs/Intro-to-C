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

/* Create a new list node and initialize it */
static struct list_node *new_item(char *name, char *nickname)
{
	struct list_node *item;

	/* make a new list node */
	item = malloc(sizeof(*item));
	if (!item) {/* if item is NULL */
		printf("out of memory\n");
		return NULL;
	}
	/* fill the new node with the supplied data */
	memset(item->name, 0, sizeof(item->name));
	memset(item->nickname, 0, sizeof(item->name));
	strncpy(item->name, name, sizeof(item->name) - 1);
	strncpy(item->nickname, nickname, sizeof(item->nickname) - 1);
	item->next = NULL;
	return item;
}

static void add_item_to_front_of_list(struct list_node **list, char *name, char *nickname)
{
	struct list_node *item;

	item = new_item(name, nickname);

	/* Make the item's next point to the current front of the list */
	item->next = *list;
	/* Make the new front of the list be the new item. */
	*list = item;
}

static void append_to_list(struct list_node **list, char *name, char *nickname)
{
	struct list_node *i, *item;

	if (*list == NULL) {
		/* list is empty, adding to front is same as adding to end */
		add_item_to_front_of_list(list, name, nickname);
		return;
	}

	item = new_item(name, nickname);

	/* find the end of the list. */
	for (i = *list; i->next != NULL; i = i->next)
		/* empty loop body */;
	/* i now points to the last node in the list. */
	i->next = item;
}

static void print_list_node(struct list_node *node)
{
	printf("%s : %s\n", node->name, node->nickname);
}

static void print_list(struct list_node *list)
{
	struct list_node *i;

	for (i = list; i != NULL; i = i->next)
		print_list_node(i);
}

/* use recursion to print list backwards */
static void print_list_backwards(struct list_node *list)
{
	if (list == NULL)
		return;
	print_list_backwards(list->next);
	print_list_node(list);
}

/* Delete a node from a  list */
static void delete_node(struct list_node **list, struct list_node *node_to_delete,
			struct list_node *prev)
{
	if (prev == NULL) {
		*list = node_to_delete->next;
		free(node_to_delete);
		return;
	}
	prev->next = node_to_delete->next;
	free(node_to_delete);
}

/* find a node with the specified nick name and delete it from a list */
static void delete_item_from_list_by_nickname(struct list_node **list, char *nickname)
{
	struct list_node *prev, *curr;

	prev = NULL;
	for (curr = *list; curr != NULL; curr = curr->next) {
		if (strcmp(curr->nickname, nickname) == 0) {
			/* found it */
			delete_node(list, curr, prev);
			return;
		}
		prev = curr;
	}
}

int main(int argc, char *argv[])
{
	struct list_node *my_list = NULL;

	add_item_to_front_of_list(&my_list, "Calvin", "Spaceman Spiff");
	add_item_to_front_of_list(&my_list, "Snoopy", "Red Baron");
	append_to_list(&my_list, "Marty McFly", "Calvin Klien");
	append_to_list(&my_list, "Clark Kent", "Superman");
	append_to_list(&my_list, "Bruce Wayne", "Batman");
	print_list(my_list);
	printf("Deleting Superman... \n");
	delete_item_from_list_by_nickname(&my_list, "Superman");
	print_list(my_list);

	printf("------------------ backwards -------------------\n");
	print_list_backwards(my_list);
	return 0;
}

