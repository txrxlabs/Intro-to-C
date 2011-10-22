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
struct thing {
	char *name;
	char *description;
	int location;
	int portable;
} object[] = {
	{
		"hammer",
		"A small rock hammer",
		3, /* porch */
		1, 
	},
	{
		"coin",
		"a golden coin",
	 	1, /* field */
		1,
	},
	{
		"skull",
		"a small crystal skull",
		4, /* south forest */
		1,
	},
	{
		"dragon",
		"A huge, fire-breathing dragon",
		4, /* south forest */
		0,
	},
};

int playerloc = 1;

/* List of all the locations the game knows about */
struct room {
	char *name;		/* short name for the location */
	char *description;	/* longer description of the location */
	int travel_table[10];	/* list of locations one gets to from this room
				 * if you travel in each of 10 directions, 
				 * n, ne, e, se, s, sw, w, nw, up, down
				 */
} location[] = {
	{	/* Room 0 is the player's pocket. */
		"Player's pocket",
		"Player's pocket",
		{ -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, }, 
	},
	{	/* room 1 */
		"Field",
		"You are in a field.  A path leads away into the forest to the north\n"
		"and to the south.  A stream blocks travel to the east.  To the west is\n"
		"a small white house.\n",
		{ 2, -1, -1, -1, 4, -1, 3, -1, -1, -1, },
	},
	{	/* room 2 */
		"North Forest",
		"You are in a Forest.  A path leads away to the east and curves to the south.",
		{ -1, -1, 4, -1,  1, -1, -1, -1, -1, -1, },
	},
	{	/* room 3 */
		"Porch",
		"You are on the porch on the east side of a a small white house overlooking\n"
		"a field.",
		{ -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, },
	},
	{	/* room 4 */
		"South Forest",
		"You are in a forest.  A path leads off to the north and to the west.\n"
		"You are likely to be eaten by a Forest Monster.\n",
		{ 1, -1, -1, -1, -1, -1, 2, -1, -1, -1, },
	},
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
	unsigned int i;

	for (i = 0; i < ARRAYSIZE(object); i++)
		if (strcmp(word, object[i].name) == 0)
			return i;
	return -1;
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

void look(void)
{
	unsigned int i;
	int nothing = 1;

	printf("%s\n", location[playerloc].name);
	printf("\n%s\n\n", location[playerloc].description);

	printf("You see:\n");
	for (i = 0; i < ARRAYSIZE(object); i++)
		if (object[i].location == playerloc) {
			printf("  %s\n", object[i].description);
			nothing = 0;
		}

	if (nothing)
		printf("  Nothing special.\n");
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
	int action, i;
	int obj[100];
	char cmd[1000];
	
	do {
		look();
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
