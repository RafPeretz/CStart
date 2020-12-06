#include <stdio.h>

int main()
{
	printf("WITH scanf\n");
	printf("Please enter your string: ");
	char name[20];
	scanf("%s", name);
	printf("Please enter your char: ");
	char ch;
	scanf("%c", &ch);

	// scanf don't read the \n 
	printf("name: %s\nch: %d\n", name, ch);


	printf("WITH fgets\n");
	printf("Please enter your string: ");
	char name2[20];
	fgets(name2, 20, stdin);
	printf("Please enter your char: ");
	char c = getchar();

	// scanf don't read the \n 
	printf("name: %s\nch: %d\n", name2, c);
}