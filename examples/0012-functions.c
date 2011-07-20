#include <stdio.h>

/* variables, local variables, parameters... */

/* you can declare variables outside the scope of any function.
 * These are "globals". 
 */

int myglobal;

/* You can initialize globals while declaring them.
 * Note that this initialization happens at compile time, not runtime.
 */

int x = 5;

static int z;  /* "static" on a global definition limits the scope
		* of this symbol, z, to just this source file.
		*/

// extern int y;
		  /* "extern" means that there is some symbol y
		   * which declares an integer, but it is not in
		   * this file, it is in some other file and will
		   * be resolved at link time.
		   */

void myfunction()
{
	int x; /* <-- note this is a different x than the global x.
	          every invocation of myfunction creates a new x which
		  exists just for the duration of the function call.
		  when the function returns, this new x disappears.
		*/

	/* if you declare a static variable inside a function, then there
	 * is just one copy of that variable shared by all function
	 * invocations, and its value persists between function calls.
	 */
	static int y = 7;

	/* printf is just another function which the C library provides
	 * your functions can call functions like printf, or other functions
	 * which you create.
	 */

	x = 1;
	printf("myfunction, x = %d, y = %d\n", x, y);

	/* notice how y counts up with each subsequent call
	 * to myfunction, but x does not. */
	y++;
	x++;

	/* just fall off the end of a void function */
}

/* functions can take parameters... */
void myotherfunction(int n)
{
	int i;

	for (i = 0; i < n; i++)
		/* Here, myotherfunction calls myfunction. */
		myfunction();
	printf("myotherfunction\n");

	/* or just return; to leave a void function. */
	return;
}

/* 
 * main is a special function which is the first thing
 * called by the OS when your program starts.
 */
int main()
{
	printf("main!\n");

	/* here, main calls myfunction... */
	myfunction();

	/* and then calls myotherfunction. */
	myotherfunction(5);

	/* main is not a void function, but a function returning
	 * an int, so we return 0.
	 */
	z = 5;
	printf("z = %d\n", z);
	return 0;
}
