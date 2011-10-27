#include <stdio.h>
#include <stdlib.h>
#ifndef __APPLE__ 
#include <malloc.h>  /* apple puts the header for malloc/free in stdlib.h */
#endif

struct list_entry {
	void *some_data;  /* void pointer, you can make this point to any type */
	struct list_entry *next;
};

void *get_data(struct list_entry *e)
{
	return e->some_data;
}

void set_data(struct list_entry *e, void *data)
{
	e->some_data = data;
}

/* Insert e at the front of the list */
void insert(struct list_entry **list, void *data)
{
	struct list_entry *entry;

	entry = malloc(sizeof(*entry));
	set_data(entry, data);
	entry->next = *list;
	*list = entry;
}

/* Create a type called "list_action" which is a pointer to a function
 * returning void which accepts a pointer to a struct list_entry as a
 * parameter
 */
typedef void (*list_action)(struct list_entry *e);

void for_each_entry(struct list_entry *list, list_action action)
{
	struct list_entry *i;

	for (i = list; i; i = i->next)
		action(i);
}

void for_each_entry_backwards(struct list_entry *list, list_action action)
{
	if (list == NULL)
		return;
	for_each_entry_backwards(list->next, action);
	action(list);
}

/* Create an instance of a list_action function for printing strings */
void print_string_entry(struct list_entry *e)
{
	char *x;

	x = get_data(e);
	printf("%s\n", x);
}

/* Create an instance of a list_action function for printing ints */
void print_int_entry(struct list_entry *e)
{
	int *x;
	x = get_data(e);
	printf("%d\n", *x);
}

/* free all the elements of a list by iterating over them */
void iterative_free_list(struct list_entry *list)
{
	struct list_entry *i, *next;

	for (i = list; i != NULL; i = next) {
		next = i->next;
		free(i);
	}
}

/* free all the elements of a list by recursively freeing the tail
 * of the list, then freeing the remaining head.
 */
void recursive_free_list(struct list_entry *list)
{
	if (list == NULL)
		return;
	recursive_free_list(list->next);
	free(list);
}

/* free all the elements of a list by recursively freeing the tail
 * of the list, then freeing the remaining head.
 */
void tail_recursive_free_list(struct list_entry *list)
{
	struct list_entry *tail;

	if (list == NULL)
		return;
	tail = list->next;
	free(list);
	tail_recursive_free_list(tail);
}

#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

int main(int argc, char *argv[])
{
	int i;
	struct list_entry *list = NULL;
	struct list_entry *list2 = NULL;
	int numbers[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

	
	for (i = 0; i < argc; i++)
		insert(&list, argv[i]); 

	printf("Here's the reversed list of program arguments.\n");
	for_each_entry(list, print_string_entry);

	for (i = 0; i < (int) ARRAYSIZE(numbers); i++)
		insert(&list2, &numbers[i]);

	printf("Here's the reversed list of numbers\n");
	for_each_entry(list2, print_int_entry);

	printf("Here's the reversed list of numbers printed in reverse\n");
	for_each_entry_backwards(list2, print_int_entry);

	recursive_free_list(list);
	iterative_free_list(list2);
	
	return 0;
}
	
