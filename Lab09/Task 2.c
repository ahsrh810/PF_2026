#include<stdio.h>
#include<string.h>

int main() {
	char first[30];
	char last[30];
	char full[60] = "";
	
	printf("Enter first name: ");
	scanf("%s", first);
	
	printf("Enter last name: ");
	scanf("%s", last);
	
	strcat(full, first);
	strcat(full, " ");
	strcat(full, last);
	printf("Full name: %s\n", full);
}
