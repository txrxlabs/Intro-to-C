#include <stdio.h>
#include <malloc.h>
#include <string.h> /* for memset() */

#define DECLARE_DISPLAY_MODULE_GLOBALS
#include "0025-display-module.h"

struct display {
	int x, y;
	char *pixels;
};

struct display *create_display(int xdimension, int ydimension)
{
	struct display *d;

	d = malloc(sizeof(*d));
	d->x = xdimension;
	d->y = ydimension;
	d->pixels = malloc(sizeof(char) * d->x * d->y);
	memset(d->pixels, ' ', sizeof(char) * d->x * d->y);
	return d;
}

static void draw_point(struct display *display, int x, int y)
{
	display->pixels[y * display->x + x] = '*';
}

/* 
 * Bresenham's line drawing algorithm -- google it if you want to know 
 * how this works.
 */
void draw_line(struct display *display, int x1, int y1, int x2, int y2)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;

	dx = x2 - x1;
	if (dx < 0)
		dx = -dx;

	dy = y2 - y1;
	if (dy < 0)
		dy = -dy;

	incx = (x2 < x1) ? -1 : 1;
	incy = (y2 < y1) ? -1 : 1;

	if (dx > dy) {
		draw_point(display, x1, y1);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++) {
			if (e >= 0) {
				y1 += incy;
				e += inc1;
			} else {
				e += inc2;
			}
			x1 += incx;
			draw_point(display, x1, y1);
		}
	} else {
		draw_point(display, x1, y1);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++) {
			if (e >= 0) {
				x1 += incx;
				e += inc1;
			} else {
				e += inc2;
			}
			y1 += incy;
			draw_point(display, x1, y1);
		}
	}
}

void draw_rectangle(struct display *display, int x1, int y1, int x2, int y2)
{
	draw_line(display, x1, y1, x1, y2);
	draw_line(display, x2, y1, x2, y2);
	draw_line(display, x1, y1, x2, y1);
	draw_line(display, x1, y2, x2, y2);
}

/* A variant of Bresenham's circle drawing routine */
void draw_circle(struct display *display, int xc, int yc, int r)
{
	int x = 0; 
	int y = r; 
	int p = 3 - 2 * r;
	if (!r)
		return;     

	while (y >= x) { 
		/* only formulate 1/8 of circle */
		draw_point(display, xc-x, yc-y); /* upper left left */
		draw_point(display, xc-y, yc-x); /* upper upper left */
		draw_point(display, xc+y, yc-x); /* upper upper right */
		draw_point(display, xc+x, yc-y); /* upper right right */
		draw_point(display, xc-x, yc+y); /* lower left left */
		draw_point(display, xc-y, yc+x); /* lower lower left */
		draw_point(display, xc+y, yc+x); /* lower lower right */
		draw_point(display, xc+x, yc+y); /* lower right right */
		if (p < 0)
			p += 4 * x++ + 6; 
		else
			p += 4 * (x++ - y--) + 10; 
	} 
}

void show_display(struct display *display)
{
	int x, y;

	for (y = 0; y < display->y; y++) {
		for (x = 0; x < display->x; x++)
			printf("%c", display->pixels[y * display->x + x]);
		printf("\n");
	}
}

void free_display(struct display *display)
{
	free(display->pixels);
	free(display);
}

