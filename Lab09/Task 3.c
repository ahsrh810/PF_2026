#include <stdio.h>
#include <string.h>

int main() {
    char pass[30] = "lab10pass";
    char input[30];
    printf("Enter password: ");
    scanf("%s", input);
    
    if (strcmp(input, pass) == 0) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    if (strncmp(input, pass, 3) == 0) {
        printf("First 3 characters match\n");
    } else { 
		printf("First 3 characters don't match\n");
    }

    return 0;
}
