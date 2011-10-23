#include <stdio.h>

/* 
 * since a student asked, here is an alternate solution
 * to exercise 7, in which you print a triangle of asterisks
 * a given number of rows high and wide:
 *
 * eg: 3:    *         eg 5:   *
 *           **                **
 *           ***               ***
 *                             ****
 *                             *****
 */

void print_triangle_row(int ncolumns)
{
	if (ncolumns == 0) {
		printf("\n");
		return;
	}
	printf("*");
	print_triangle_row(ncolumns - 1);
}

/* Assuming you've already printed the first (current_row - 1) rows,
 * print the remaining rows.
 */
void print_triangle_tail(int current_row, int rows_left)
{
	/* If no rows left to print, nothing left to do */
	if (rows_left == 0)
		return;

	/* print the current row... */
	print_triangle_row(current_row);

	/* print the remaining rows. */
	print_triangle_tail(current_row + 1, rows_left - 1);
}

int main()
{
	int value, i, j;

	printf("Enter a positive integer: ");
	scanf("%d", &value);
	print_triangle_tail(1, value);
	return 0;
}
