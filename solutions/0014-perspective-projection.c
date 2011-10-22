#include <stdio.h>

void perspective_projection(float x, float y, float z,
	float z1, float *x1, float *y1) 
{
    *x1 = z1 * (x / (z1 + z));
    *y1 = z1 * (y / (z1 + z));
}
    
int main()
{
	float x, y, z, x1, y1, z1;

	x = 20.0;
	y = 20.0;
	z = 50.0;
	z1 = 25.0;

	perspective_projection(x, y, z, z1, &x1, &y1);

	printf("screen coords for (%f,%f,%f) are (%f,%f)\n", x, y, z, x1, y1);
	return 0;
}


