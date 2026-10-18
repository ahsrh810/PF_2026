#include <stdio.h>
#include <stdbool.h>

int main() {
    int r, c;
    printf("Enter rows and columns (up to 5x5): ");
    scanf("%d %d", &r, &c);

    float A[5][5];
    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    bool isSquare = (r == c);
    bool isRectangular = !isSquare;
    bool isZero = true;
    bool isDiagonal = isSquare;
    bool isIdentity = isSquare;
    bool isUpper = isSquare;
    bool isLower = isSquare;
    bool isSymmetric = isSquare;
    bool isSkew = isSquare;

    float scalarVal = isSquare ? A[0][0] : 0;
    bool isScalar = isSquare;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (A[i][j] != 0) isZero = false;

            if (isSquare) {
                if (i != j && A[i][j] != 0) isDiagonal = false;
                if (i == j && A[i][j] != 1) isIdentity = false;
                if (i == j && A[i][j] != scalarVal) isScalar = false;
                if (i > j && A[i][j] != 0) isUpper = false;
                if (i < j && A[i][j] != 0) isLower = false;
                if (A[i][j] != A[j][i]) isSymmetric = false;
                if (A[i][j] != -A[j][i]) isSkew = false;
            }
        }
    }

    printf("\n--- Matrix Classifications ---\n");
    if (isSquare) printf("- Square Matrix\n");
    if (isRectangular) printf("- Rectangular Matrix\n");
    if (isZero) printf("- Zero / Null Matrix\n");
    if (isDiagonal) printf("- Diagonal Matrix\n");
    if (isIdentity) printf("- Identity Matrix\n");
    if (isScalar) printf("- Scalar Matrix\n");
    if (isUpper) printf("- Upper Triangular Matrix\n");
    if (isLower) printf("- Lower Triangular Matrix\n");
    if (isSymmetric) printf("- Symmetric Matrix\n");
    if (isSkew) printf("- Skew-Symmetric Matrix\n");
    if (r == 1) printf("- Row Matrix\n");
    if (c == 1) printf("- Column Matrix\n");

    return 0;
}