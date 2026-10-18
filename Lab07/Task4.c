#include <stdio.h>

int main() {
    int arr[3][3][3];
    int totalSum = 0;
    int maxVal, minVal;
    int first = 1;

    printf("Enter elements for 3x3x3 array:\n");
    for (int l = 0; l < 3; l++) {
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                printf("Layer %d, Row %d, Col %d: ", l, r, c);
                scanf("%d", &arr[l][r][c]);

                if (first) {
                    maxVal = minVal = arr[l][r][c];
                    first = 0;
                } else {
                    if (arr[l][r][c] > maxVal) maxVal = arr[l][r][c];
                    if (arr[l][r][c] < minVal) minVal = arr[l][r][c];
                }
                totalSum += arr[l][r][c];
            }
        }
    }

    printf("\n--- Layer-wise Totals --- \n");
    for (int l = 0; l < 3; l++) {
        int layerSum = 0;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                layerSum += arr[l][r][c];
            }
        }
        printf("Layer %d Total Sum = %d (Average = %.2f)\n", l, layerSum, layerSum / 9.0);
    }

    printf("\n--- Overall Data Insights ---\n");
    printf("Global Total Sum: %d\n", totalSum);
    printf("Global Maximum: %d\n", maxVal);
    printf("Global Minimum: %d\n", minVal);

    return 0;
}