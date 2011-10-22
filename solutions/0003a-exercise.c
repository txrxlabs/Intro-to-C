#include <stdio.h>

int main()
{
	float degreesf, degreesc;

	printf("Enter degrees Fahrenheit: ");
	scanf("%f", &degreesf);
	degreesc = (degreesf - 32.0) * 5.0 / 9.0;
	printf("Degrees C: %f\n", degreesc);
	return 0;
}

