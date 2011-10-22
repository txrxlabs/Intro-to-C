#include <stdio.h>
#include <stdint.h>

int main()
{
	uint32_t a, b;

	a = 0xffff00f0;
	b = 0x0f00ffff;

	/* bitwise "or" */
	printf("0x%08x | 0x%08x == %08x\n", a, b, a | b);
	/* bitwise "and" */
	printf("0x%08x & 0x%08x == %08x\n", a, b, a & b);
	/* bitwise "xor" */
	printf("0x%08x ^ 0x%08x == %08x\n", a, b, a ^ b);
	/* bitwise "not" */
	printf("~0x%08x == %08x\n", a, ~a);
	/* right shift operator */
	printf("0x%08x >> 3 == 0x%08x\n", a, a >> 3);
	/* left shift operator */
	printf("0x%08x << 3 == 0x%08x\n", b, b >> 3);
	return 0;
}
