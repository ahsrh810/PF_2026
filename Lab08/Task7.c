#include <stdio.h>

void reverseArray(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    int temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void printArray(const int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int n, i;
    int songs[20];

    do {
        printf("Enter number of songs: ");
        scanf("%d", &n);
        if (n < 1 || n > 20) {
            printf("Invalid size\n");
        }
    } while (n < 1 || n > 20);

    printf("Enter song IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &songs[i]);
    }

    printf("Original: ");
    printArray(songs, n);

    reverseArray(songs, n);

    printf("Reversed: ");
    printArray(songs, n);

    return 0;
}