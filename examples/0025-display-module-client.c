#include <stdio.h>
#include "0025-display-module.h"

int main(int argc, char *argv[])
{
	struct display *d;
	int xd = 79;
	int yd = 23;

	d = create_display(xd + 1, yd + 1);

	draw_rectangle(d, 0, 0, xd, yd);
	draw_line(d, 0, 0, xd, yd); 
	draw_line(d, 0, yd, xd, 0); 
	draw_circle(d, xd / 2, yd / 2, yd / 3);
	show_display(d);

	free_display(d);
	return 0;
}
