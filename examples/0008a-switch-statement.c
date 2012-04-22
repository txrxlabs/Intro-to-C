#include <stdio.h>

int main(int argc, char *argv[])
{
	int choice;

	do {
		printf("1. Animal\n");
		printf("2. Mineral\n");
		printf("3. Vegetabl\n");
		printf("4. Other\n");
		printf("Enter choice (0 to exit): ");

		scanf("%d", &choice);

		switch (choice) {
		case 0: break;
		case 1:	printf("Penguin\n");
			break;
		case 2:	printf("Quartz\n");
			break;
		case 3:	printf("Green Beans\n");
			break;
		case 4: printf("Linux\n");
			break;
		default:printf("Please enter a number between 0 and 4\n");
			break;
		}
	} while (choice != 0);

	return 0;
}
