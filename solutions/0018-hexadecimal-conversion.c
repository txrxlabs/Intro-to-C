#include <stdio.h>
#include <string.h>

void print_hexnumber(unsigned int value)
{
	char *hexdigit = "0123456789abcdef";
	char answer[100], tmpstring[100];
	char digit[2];

	strcpy(answer, "");
	digit[1] = '\0'; /* null terminate digit */
	do {
		digit[0] = hexdigit[value & 0x0f];
		value = value >> 4;
		strcpy(tmpstring, digit);
		strcat(tmpstring, answer);
		strcpy(answer, tmpstring);
	} while (value != 0);
	printf("0x%s\n", answer);
}

int main(int argc, char *argv[])
{
	int number;

	do {
		printf("Enter a decimal integer (-1 to quit): ");
		scanf("%d", &number);
		printf("%d converted to hexadecimal is:\n", number);
		print_hexnumber(number);
	} while (number != -1);
	return 0;
}
