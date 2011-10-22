#include <stdio.h>
#include <string.h>

/* If we have to keep track of something with related attributes,
 * we can use a struct.  For example:
 */

/* create a new type, "struct address_book_entry" */
struct address_book_entry {
	char name[256];
	char addr1[256];
	char addr2[256];
	char city[256];
	char state[256];
	char zipcode[20];
};

/* then we could declare an array of these structs */
struct address_book_entry entry[1000];

int main(int argc, char *argv[])
{

	struct address_book_entry *e;

	/* members of the struct are accessed by using the . operator */
	strcpy(entry[0].name, "Herman Munster");
	strcpy(entry[0].addr1, "1212 Mockingbird Lane");
	strcpy(entry[0].addr2, "");
	strcpy(entry[0].city, "Springfield");
	strcpy(entry[0].state, "Undead");
	strcpy(entry[0].zipcode, "00000");

	/* We can have pointers to structs... */
	e = &entry[0];

	/* members can be accessed using the *, though operator precedence
	 * makes this somewhat inconvenient... */

	printf("(*e).name = %s\n", (*e).name);

	/* To alleviate this inconvience, there is the -> operator
	 * s->m is equivalent to (*s).m
	 */

	printf("e->name = %s\n", e->name);

	return 0;
}

