#include <stdio.h>

int main(int argc, char *argv[])
{
	int rc;
	char c;

	while (!feof(stdin)) {
		rc = scanf("%c", &c);
		if (rc != 1)
			break;
		if (c == '\n')
			printf("\r");
		printf("%c", c);
	}	
	return 0;
}

