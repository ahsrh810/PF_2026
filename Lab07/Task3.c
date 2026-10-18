#include <stdio.h>

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Error: Columns of Matrix A must match Rows of Matrix B!\n");
        return 0;
    }

    float A[3][3], B[3][3], C[3][3] = {0};

    printf("Enter Matrix A elements:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%f", &A[i][j]);

    printf("Enter Matrix B elements:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%f", &B[i][j]);

    // Multiplication using three nested loops
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\n--- Resultant Matrix (C = A x B) ---\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%.2f \t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}