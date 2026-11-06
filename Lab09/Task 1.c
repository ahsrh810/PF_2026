#include <stdio.h>
#include <string.h>

int main() {
	char name[30];
	char copy[30];
	
	printf("Enter your name: ");
	fgets(name, sizeof(name), stdin);
	
	name[strcspn(name, "\n")] = '\0';
	printf("Length of name: %lu\n", strlen(name));
	printf("Size of name array (sizeof): %lu\n", sizeof(name));
	
	strcpy(copy, name);
	printf("Copied name: %s\n", copy);
	return 0;
}
