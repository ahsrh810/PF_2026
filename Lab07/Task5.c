#include <stdio.h>
#include <stdbool.h>

int main() {
    int arr[3][3][3];

    printf("Enter elements for 3x3x3 matrix set:\n");
    for (int l = 0; l < 3; l++) {
        printf("--- Layer %d ---\n", l);
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                printf("Element [%d][%d]: ", r, c);
                scanf("%d", &arr[l][r][c]);
            }
        }
    }

    bool match01 = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[0][i][j] != arr[1][i][j]) {
                match01 = false;
                break;
            }
        }
        if (!match01) break;
    }

    bool match12 = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[1][i][j] != arr[2][i][j]) {
                match12 = false;
                break;
            }
        }
        if (!match12) break;
    }

    bool match02 = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[0][i][j] != arr[2][i][j]) {
                match02 = false;
                break;
            }
        }
        if (!match02) break;
    }

    printf("\n--- Layer Similarity Report ---\n");
    printf("Layer 0 and Layer 1 are: %s\n", match01 ? "IDENTICAL" : "DISTINCT");
    printf("Layer 1 and Layer 2 are: %s\n", match12 ? "IDENTICAL" : "DISTINCT");
    printf("Layer 0 and Layer 2 are: %s\n", match02 ? "IDENTICAL" : "DISTINCT");

    if (match01 && match12) {
        printf("\nConclusion: All three layers are identical!\n");
    } else if (!match01 && !match12 && !match02) {
        printf("\nConclusion: All three layers are completely distinct!\n");
    } else {
        printf("\nConclusion: Some layers match while others are distinct.\n");
    }

    return 0;
}