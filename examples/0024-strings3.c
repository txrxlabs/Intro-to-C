#include <stdio.h>
#include <string.h>
#include <ctype.h> /* for tolower */
#include <stdlib.h>

struct dictionary_entry {
	char *native;
	char *translation;
};

struct dictionary_entry english2spanish[] = {
	{ "one", "uno" },
	{ "two", "dos" },
	{ "three", "tres" },
	{ NULL, NULL },
};
	
struct dictionary_entry english2french[] = {
	{ "one", "un" },
	{ "two", "deux" },
	{ "three", "trois" },
	{ NULL, NULL },
};

struct dictionary {
	struct dictionary_entry *dictionary;
	char *language;
} dlist[] = {
	{ english2spanish, "spanish", },
	{ english2french, "french", },
	{ NULL, NULL },
};

void lowercase(char *s)
{
	char *i;

	for (i = s; *i; i++)
		*i = tolower(*i);
}

void getcommand(char *command, int bufsize)
{
	char *c;
	int len;

	printf("-> ");
	c = fgets(command, bufsize, stdin); 
	if (c == NULL)
		exit(1);
	len = strlen(command);
	command[len - 1] = '\0'; /* cut off trailing '\n' */
	lowercase(command);
}

struct dictionary_entry *lookup(struct dictionary_entry *dictionary, char *word)
{
	int i;

	for (i = 0; dictionary[i].native != NULL; i++)
		if (strcmp(dictionary[i].native, word) == 0)
			return &dictionary[i];
	return NULL;
}

void process(char *command)
{
	static struct dictionary_entry *current_dictionary = english2spanish;
	char *nextword;
	struct dictionary_entry *translation;
	int i;

	printf("processing '%s'\n", command);
	if (strcmp(command, "quit") == 0)
		exit(0);

	nextword = strtok(command, " ,.");
	do {
		translation = lookup(current_dictionary, nextword);
		if (translation != NULL) {
			printf("%s ", translation->translation);
			continue;
		}

		/* Maybe they want to switch dictionaries? */
		for (i = 0; dlist[i].dictionary != NULL; i++) {
			if (strcmp(dlist[i].language, nextword) == 0) {
				current_dictionary = dlist[i].dictionary;
				break;
			}
		}
		/* if not found... */
		if (dlist[i].dictionary == NULL)
			printf("*%s* ", nextword);
	} while ((nextword = strtok(NULL, " ,.")) != NULL);
	printf("\n");
}

int main(int argc, char *argv[])
{
	char command[1000];

	while (1) {
		getcommand(command, sizeof(command));
		process(command);
	}
	exit(0);
}

