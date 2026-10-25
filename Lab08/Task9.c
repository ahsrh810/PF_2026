#include <stdio.h>

int sumShelf(const int *shelf, int count) {
    int sum = 0, i;
    for (i = 0; i < count; i++) {
        sum += *(shelf + i);
    }
    return sum;
}

int findLargestShelf(const int *counts, int shelves) {
    int maxIndex = 0, i;
    for (i = 1; i < shelves; i++) {
        if (*(counts + i) > *(counts + maxIndex)) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int shelfA[] = {101, 102, 103};
    int shelfB[] = {201, 202};
    int shelfC[] = {301, 302, 303, 304};

    int *shelves[] = {shelfA, shelfB, shelfC};
    int counts[] = {3, 2, 4};
    int numShelves = 3;
    int i;

    for (i = 0; i < numShelves; i++) {
        int sum = sumShelf(shelves[i], counts[i]);
        printf("Shelf %d total: %d\n", i + 1, sum);
    }

    int largestIndex = findLargestShelf(counts, numShelves);
    printf("Shelf with the most books: Shelf %d (%d books)\n", largestIndex + 1, counts[largestIndex]);

    return 0;
}