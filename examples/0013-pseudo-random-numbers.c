#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* chance is a function that returns a float.
 * It returns a pseudo random value between 0.0 and 1.0
 *
 * The first time it is called, it will seed the random
 * number generator with a value obtained from the system
 * clock.
 *
 */
float chance()
{
	/* we need to remember if we have already seeded the
	 * random number generator between calls, so use static.
	 */
	static int seeded = 0; /* first time, we have not seeded */

	if (!seeded) {
		/* this must be the first time... */
		struct timeval tv;

		/* get the system time... */
		gettimeofday(&tv, NULL);

		/* Seed the random number generator with the 
		 * microseconds portion of the time value
		 */
		srand(tv.tv_usec);

		/* remember that we already seeded the random 
		 * number generator.
		 */
		seeded = 1;
	}

	/* Get a random integer between 0 and RAND_MAX and scale it
	 * down to a float between 0.0 and 1.0.  
	 *
	 * Notice the typecasting. without it, the integer value
	 * 0 would be returned due to truncating integer division.
	 */
	return (float) rand() / (float) RAND_MAX;
}

int main()
{
	int i;

	for (i = 0; i < 10; i++)
		printf("Random chance is: %g\n", chance());
	return 0;
}

