#include <stdio.h>
#include <string.h>

/* Idiomatic macro to determine the number of elements in
 * a statically declared array
 */
#define ARRAYSIZE(x) (sizeof(x) / sizeof((x)[0]))

/* List of all the verbs the game knows about */
char *verb[] = {
	"go",
	"take",
	"get",
	"drop",
	"inventory",
	"look",
	"quit",
	NULL
};

/* List of all the objects the game knows about */
char *noun[] = {
	"hammer",
	"coin",
	"skull",
	"dragon",
	NULL,
};

/* Read a command from the user.  The command will be truncated
 * to len to avoid buffer overrun, if necessary.
 */
void read_command(char *cmd, int len)
{
	char *x;

	printf("> ");
	x = fgets(cmd, len, stdin);
	return;
}


/* Look up a word in an array of words, and return which entry
 * it is.  If not found, will return -1.
 */
int lookup_word(char *word, char *dictionary[])
{
	int i;

	for (i = 0; dictionary[i] != NULL; i++)
		if (strcmp(word, dictionary[i]) == 0)
			return i;
	return -1;
}

int lookup_verb(char *word)
{
	return lookup_word(word, verb);
}

int lookup_noun(char *word)
{
	return lookup_word(word, noun);
}

/* When parsing a command, these are the characters that we consider
 * to be what separates words from each other.
 */ 
#define DELIMITERS " ,.!-?;\n\t"

/* given a string, cmd, break it into words, and look up 
 * each word and convert all the words into indexes into
 * the noun and verb arrays.
 */  
void parse_command(char *cmd, int *action, int *obj, int maxobjs)
{
	char *x;
	int i;

	/* Assume first word is a verb, and look it up. */
	x = strtok(cmd, DELIMITERS);
	*action = lookup_verb(x);
	if (*action == -1) {
		printf("I don't understand the word '%s'\n", x);
		return;
	}

	/* Process the rest of the words, assuming they are nouns
	 * and store the object numbers in the obj[] array.
	 * Terminate the list of objects with object number -1.
	 */
	for (i = 0; ;i++) {

		/* If we filled up the list of objects, then complain and bail out */
		if (i >= maxobjs - 1)  {
			printf("Too many objects in that sentence, I can't remember them all.\n");
			*action = -1;
			return;
		}

		/* Get the next word ... */
		x = strtok(NULL, DELIMITERS);
		if (!x) {
			obj[i] = -1;
			return;
		}

		/* Look it up and store the index in the obj[] array */
		obj[i] = lookup_noun(x);

		/* If we didn't know a word, set the verb action to -1 and bail out */
		if (obj[i] == -1) {
			printf("I don't understand the word '%s'\n", x);
			*action = -1;
			return;
		}
	}
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
	int action, i;
	int obj[100];
	char cmd[1000];
	
	do {
		read_command(cmd, sizeof(cmd) - 1);
		parse_command(cmd, &action, obj, ARRAYSIZE(obj));
		printf("action = %d\n", action);

		/* If we didn't understand, just get another command and try again. */
		if (action == -1)
			continue;

		/* Print out the verb number and the list of object numbers */
		for (i = 0; obj[i] != -1; i++)
			printf("obj[%d] = %d\n", i, obj[i]);

	} while (action == -1 || strcmp(verb[action], "quit") != 0);
	return 0;	
}
