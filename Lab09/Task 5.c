#include <stdio.h>
#include <string.h>

int main() {
    char city[5][30];
    int max = 0;
    int longInd = 0;
	int i;
    printf("Enter 5 city names:\n");
    for (i = 0; i < 5; i++) {
        fgets(city[i], sizeof(city[i]), stdin);
        city[i][strcspn(city[i], "\n")] = '\0';

        int current = strlen(city[i]);
        if (current > max) {
            max = current;
            longInd = i;
        }
    }
    printf("All Cities:\n");
    for (i = 0; i < 5; i++) {
        printf("- %s\n", city[i]);
    }
    printf("Longest city name: %s (Length: %d)\n", city[longInd], max);

    return 0;
}
