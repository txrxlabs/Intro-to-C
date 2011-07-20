#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, -1 };

	int *i, j;

	/* Notice how i++ adds not 1, but sizeof(int) to i
	 * each time though the loop. 
	 */
	j = 0;
	for (i = a; *i != -1; i++, j++)
		printf("i = %p, *i = %d, &a[%d] = %p, a[%d] = %d\n",
			i, *i, j, &a[j], j, a[j]);

	/* It works with multiplication too */	
	printf("a + 7 = %p, *(a + 7) == %d, a[7] == %d\n", a + 7, *(a + 7), a[7]);

	/* In fact, the notation a[n] is equivalent to *(a + n).
	 * And because addition is commutative,  (a + b) == (b + a), 
	 * it therefore must also be equivalent to *(n + a), which
	 * oddly enough means we can even do this.
	 * (Yes this compiles, and works!)
	 */
	printf("7[a] == %d, &7[a] = %p\n", 7[a], &7[a]);
	/* But don't do that, cause that's just crazy. */

	return 0;
}
