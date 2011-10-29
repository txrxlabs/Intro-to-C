#ifndef __DISPLAY_MODULE_H__
#define __DISPLAY_MODULE_H__

#ifdef DECLARE_DISPLAY_MODULE_GLOBALS
#define GLOBAL
#else
#define GLOBAL extern
#endif

/* Here, we declare that there is a thing called a "struct display"
 * but we don't say anything about what is in it.  We can have pointers
 * to struct display, but not struct displays themselves, as we don't
 * know how big they are or what's in them.
 */
struct display;

/* here we declare some function prototypes for doing things with 
 * struct displays (or rather, with pointers to struct displays.
 */
GLOBAL struct display *create_display(int xdimension, int ydimension);
GLOBAL void draw_line(struct display *display, int x1, int y1, int x2, int y2);
GLOBAL void draw_rectangle(struct display *display, int x1, int y1, int x2, int y2);
GLOBAL void draw_circle(struct display *display, int x, int y, int r);
GLOBAL void show_display(struct display *display);
GLOBAL void free_display(struct display *display);

#undef GLOBAL

#endif

