#include <stdio.h>

void computeTotals(int (*marks)[3], int rows, int totals[]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        totals[i] = 0;
        for (j = 0; j < 3; j++) {
            totals[i] += *(*(marks + i) + j);
        }
    }
}

int findTopper(const int *totals, int rows) {
    int maxIndex = 0;
    int i;
    for (i = 1; i < rows; i++) {
        if (*(totals + i) > *(totals + maxIndex)) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int marks[3][3];
    int totals[3];
    int i, j;

    for (i = 0; i < 3; i++) {
        printf("Enter marks for Student %d (3 subjects): ", i + 1);
        for (j = 0; j < 3; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    computeTotals(marks, 3, totals);

    for (i = 0; i < 3; i++) {
        printf("Total for Student %d: %d\n", i + 1, totals[i]);
    }

    int topperIndex = findTopper(totals, 3);
    printf("Student %d is the topper with total %d\n", topperIndex + 1, totals[topperIndex]);

    return 0;
}