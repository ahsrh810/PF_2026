#include <stdio.h>
#include <string.h>

int main() {
    char names[5][30];
    char temp[30];
	int i;
	int j;
	
    printf("Enter 5 student names:\n");
    for (i = 0; i < 5; i++) {
        scanf("%s", names[i]);
    }

    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted Names:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", names[i]);
    }
    return 0;
}
