#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char name[50];
	int i;
	
    fp = fopen("std.txt", "w");
    if (fp == NULL) {
        printf("Error for writing!\n");
        return 1;
    }

    printf("Enter 3 student names:\n");
    for (i = 0; i < 3; i++) {
        scanf("%s", name);
        fprintf(fp, "%s\n", name);
    }
    fclose(fp);

    fp = fopen("std.txt", "r");
    if (fp == NULL) {
        printf("Error for reading!\n");
        return 1;
    }

    printf("\nNames read from std.txt:\n");
    int count;
    for(count = 0; fscanf(fp, "%s", name) != EOF; count++) {
        printf("%d. %s\n", count, name);
    }
    fclose(fp);

    printf("Total students in file: %d\n", count);

    return 0;
}
