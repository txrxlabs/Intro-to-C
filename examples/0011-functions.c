#include <stdio.h>

/*
 * you can create your own functions, which is just
 * a chunk of code that you can give a name and then
 * refer to by that name.
 *
 * Note that these functions return "void" which means
 * that they do not return anything.  There is no return
 * statement, they just "fall off the end."  You could also
 * put a "return;" at the end to return void.
 */
void myfunction()
{
	/* printf is just another function which the C library provides
	 * your functions can call functions like printf, or other functions
	 * which you create.
	 */
	printf("myfunction\n");

	/* just fall off the end of a void function */
}

void myotherfunction()
{
	/* Here, myotherfunction calls myfunction. */
	myfunction();
	printf("myotherfunction");

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
	myotherfunction();

	/* main is not a void function, but a function returning
	 * an int, so we return 0.
	 */
	return 0;
}
