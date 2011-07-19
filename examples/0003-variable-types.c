#include <stdio.h>

int main()
{
	int a;
	short b;
	unsigned long c;
	unsigned char x;
	float pi;
	double e;

	printf("Hello, world!\n");

	a = 1;
	b = 012; /* note leading zero: 12 octal == 10 decimal */
	c = a + b;
	x = 0xff; /* hexadecimal */
	printf("a = %d, b= %hd, c = %lu\n", a, b, c);
	printf("0x%08lx\n", c);
	
	x = 'a';

	printf("x = %c\n", x);

	pi = 3.1415927;
	e = 2.7182818284590452353;

	printf("pi = %f, e = %g\n", pi, e);

	return 0;
}

