#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Idiomatic macro to determine the number of elements in
 * a statically declared array
 */
#define ARRAYSIZE(x) (sizeof(x) / sizeof((x)[0]))


typedef int (*verbfunc)(int *objlist);

int gonorth(int *objlist); 
int gonortheast(int *objlist); 
int goeast(int *objlist); 
int gosoutheast(int *objlist); 
int gosouth(int *objlist); 
int gosouthwest(int *objlist); 
int gowest(int *objlist); 
int gonorthwest(int *objlist); 
int goup(int *objlist); 
int godown(int *objlist); 
int go(int *objlist); 
int take(int *objlist); 
int drop(int *objlist); 
int look(int *objlist); 
int examine(int *objlist); 
int quit(int *objlist);
int inventory(int *objlist);

struct verbword {
	char *word;
	verbfunc execute;
} verb[] = {
	{ "n", gonorth },
	{ "ne", gonortheast },
	{ "e", goeast },
	{ "se", gosoutheast },
	{ "s", gosouth },
	{ "sw", gosouthwest },
	{ "w", gowest },
	{ "nw", gonorthwest },
	{ "u", goup },
	{ "d", godown },
	{ "go", go },
	{ "get", take },
	{ "take", take },
	{ "drop", drop },
	{ "look", look },
	{ "examine", examine },
	{ "quit", quit },
	{ "inventory", inventory },
	{ NULL, NULL },
};

/* List of all the objects the game knows about */
struct thing {
	char *name;
	char *description;
	char *examine;
	int location;
	int portable;
} object[] = {
	{ "north", "north", NULL, -1, 0, },
	{ "northeast", "northeast", NULL, -1, 0, },
	{ "east", "east", NULL, -1, 0, },
	{ "southeast", "southeast", NULL, -1, 0, },
	{ "south", "south", NULL, -1, 0, },
	{ "southwest", "southwest", NULL, -1, 0, },
	{ "west", "west", NULL, -1, 0, },
	{ "northwest", "northwest", NULL, -1, 0, },
	{ "up", "up", NULL, -1, 0, },
	{ "down", "down", NULL, -1, 0, },
	{
		"hammer",
		"A small rock hammer",
		NULL,
		3, /* porch */
		1, 
	},
	{
		"coin",
		"a golden coin",
		"The coin appears to be a gold doubloon from the Spanish Main.",
	 	1, /* field */
		1,
	},
	{
		"skull",
		"a small crystal skull",
		NULL,
		4, /* south forest */
		1,
	},
	{
		"dragon",
		"A huge, fire-breathing dragon",
		"The dragon does not wish to be examined.",
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
	int visited;
} location[] = {
	{	/* Room 0 is the player's pocket. */
		"Player's pocket",
		"Player's pocket",
		{ -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, }, 
		0,
	},
	{	/* room 1 */
		"Field",
		"You are in a field.  A path leads away into the forest to the north\n"
		"and to the south.  A stream blocks travel to the east.  To the west is\n"
		"a small white house.\n",
		{ 2, -1, -1, -1, 4, -1, 3, -1, -1, -1, },
		0,
	},
	{	/* room 2 */
		"North Forest",
		"You are in a Forest.  A path leads away to the east and curves to the south.",
		{ -1, -1, 4, -1,  1, -1, -1, -1, -1, -1, },
		0,
	},
	{	/* room 3 */
		"Porch",
		"You are on the porch on the east side of a a small white house overlooking\n"
		"a field.",
		{ -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, },
		0,
	},
	{	/* room 4 */
		"South Forest",
		"You are in a forest.  A path leads off to the north and to the west.\n"
		"You are likely to be eaten by a Forest Monster.\n",
		{ 1, -1, -1, -1, -1, -1, 2, -1, -1, -1, },
		0,
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

int lookup_verb(char *word)
{
	unsigned int i;

	for (i = 0; verb[i].word != NULL; i++)
		if (strcmp(word, verb[i].word) == 0)
			return i;
	return -1;
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

int haveit(int obj)
{
	return object[obj].location == 0;
}

int ishere(int obj)
{
	return object[obj].location == playerloc;
}

int look(int *objlist)
{
	unsigned int i;
	int nothing = 1;

	if (objlist[0] != -1) {
		printf("look %s?  I don't understand.\n", object[objlist[0]].name);
		return 0;
	}
	printf("%s\n", location[playerloc].name);
	printf("\n%s\n\n", location[playerloc].description);

	printf("You see:\n");
	for (i = 0; i < ARRAYSIZE(object); i++)
		if (ishere(i)) {
			printf("  %s\n", object[i].description);
			nothing = 0;
		}

	if (nothing)
		printf("  Nothing special.\n");
	return 0;
}

int go(int *objlist)
{
	int i;
	int nothing = -1;

	for (i = 0; objlist[i] != -1; i++) {
		/* check that a direction is specified, not "go bananas" or similar */
		if (objlist[i] < 0 || objlist[i] > 9) {
			printf("I do not understand.\n");
			return 0;
		}

		/* check that travel in the specified direction is permitted */
		if (location[playerloc].travel_table[objlist[i]] == -1) {
			printf("You can't go that way.\n");
			return 0;
		}

		/* Move the player to wherever he gets if he goes thataway */
		playerloc = location[playerloc].travel_table[objlist[i]];
	}
	if (!location[playerloc].visited)
		look(&nothing);
	else
		printf("%s\n", location[playerloc].name);
	return 0;
}

int     gonorth(__attribute__((unused))int *objlist) { int dir[] = { 0, -1 }; return go(dir); }
int gonortheast(__attribute__((unused))int *objlist) { int dir[] = { 1, -1 }; return go(dir); }
int      goeast(__attribute__((unused))int *objlist) { int dir[] = { 2, -1 }; return go(dir); }
int gosoutheast(__attribute__((unused))int *objlist) { int dir[] = { 3, -1 }; return go(dir); }
int     gosouth(__attribute__((unused))int *objlist) { int dir[] = { 4, -1 }; return go(dir); }
int gosouthwest(__attribute__((unused))int *objlist) { int dir[] = { 5, -1 }; return go(dir); }
int      gowest(__attribute__((unused))int *objlist) { int dir[] = { 6, -1 }; return go(dir); }
int gonorthwest(__attribute__((unused))int *objlist) { int dir[] = { 7, -1 }; return go(dir); }
int        goup(__attribute__((unused))int *objlist) { int dir[] = { 8, -1 }; return go(dir); }
int      godown(__attribute__((unused))int *objlist) { int dir[] = { 9, -1 }; return go(dir); }

int take(int *objlist)
{
	int i;

	for (i = 0; objlist[i] != -1; i++) {

		/* check that the object is here... */
		if (!ishere(objlist[i])) {
			printf("%s: That is not here.\n", object[objlist[i]].description);
			continue;
		}

		/* check that the object is portable... */
		if (!object[objlist[i]].portable) {
			printf("%s: You can't take that.\n", object[objlist[i]].description); 
			continue;
		}

		/* ok, take it... */
		object[objlist[i]].location = 0;
		printf("%s: Taken.\n", object[objlist[i]].description); 
	}
	return 0;
}

int drop(int *objlist)
{
	int i;

	for (i = 0; objlist[i] != -1; i++) {
		/* check that the player has the object... */

		if (!haveit(objlist[i])) {
			printf("%s: You do not have that.\n", object[objlist[i]].description);
			continue;
		}

		/* drop it. */
		object[objlist[i]].location = playerloc;
		printf("%s: Dropped.\n", object[objlist[i]].description);
	}
	return 0;
}

int inventory(int *objlist)
{
	unsigned int i;
	int nothing = 1;

	if (objlist[0] != -1) { /* they said something like, "inventory kangaroo" */ 
		printf("I do not understand.\n");
		return 0;
	}

	printf("You are carrying:\n");
	for (i = 0; i < ARRAYSIZE(object); i++)
		if (haveit(i)) {
			nothing = 0;
			printf("  %s\n", object[i].description);
		}

	if (nothing)
		printf("  Nothing.\n");

	return 0;
}

int examine(int *objlist)
{
	struct thing *o;
	int i;

	if (objlist[0] == -1) {
		printf("I do not understand what it is that you wish to examine.\n");
		return 0;
	}

	for (i = 0; objlist[i] != -1; i++) {
		if (!haveit(objlist[i]) && !ishere(objlist[i])) {
			printf("%s: I do not see that around here.\n",
				object[objlist[i]].description); 
				continue;
		}
		o = &object[objlist[i]];
		printf("%s: %s\n", o->description,
			o->examine != NULL ? o->examine : "You see nothing special about it.\n");
	}
	return 0;
}

int quit(__attribute__((unused)) int *objlist)
{
	exit(0);
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
	int action;
	int obj[100];
	char cmd[1000];
	int nothing = -1;

	look(&nothing);	
	do {
		location[playerloc].visited = 1;

		read_command(cmd, sizeof(cmd) - 1);
		parse_command(cmd, &action, obj, ARRAYSIZE(obj));

		/* If we didn't understand, just get another command and try again. */
		if (action == -1)
			continue;

		verb[action].execute(obj);

	} while (1);
	return 0;	
}
