#include <stdio.h>

int main()
{
	double radius;
	double area, circumference;
	double pi = 3.1415927;

	/* prompt the user for some information... */
	printf("Enter the radius of your circle: ");

	/* get an answer from the user (Don't worry too much
	 * about how this works just yet.  For now, just know
	 * that whatever number is typed in ends up being 
	 * assigned to the variable radius.)
	 */
	scanf("%lg", &radius);

	area = pi * radius * radius;
	circumference = pi * radius * 2.0;
	printf("A circle with radius %g has an area of %g\n", radius, area);
	printf("and a circumference of %g\n", circumference);
	return 0;
}

