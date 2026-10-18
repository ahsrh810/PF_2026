#include<stdio.h>
int main()
{
	int i, j, matA[3][3] = {{1,2,1},{0,1,4},{5,6,0}};
	int Transpose[3][3], Adjoint[3][3];
	float Inverse[3][3];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            Transpose[j][i] = matA[i][j];
		}
    }
    printf("\n--- Transpose ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", Transpose[i][j]);
        }
        printf("\n");
    }
    float det = matA[0][0] * (matA[1][1] * matA[2][2] - matA[1][2] * matA[2][1]) -
                matA[0][1] * (matA[1][0] * matA[2][2] - matA[1][2] * matA[2][0]) +
                matA[0][2] * (matA[1][0] * matA[2][1] - matA[1][1] * matA[2][0]);
    
    printf("\nDeterminant = %.2f\n", det);
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int r1 = (i + 1) % 3, r2 = (i + 2) % 3;
            int c1 = (j + 1) % 3, c2 = (j + 2) % 3;
            
            float minor = matA[r1][c1] * matA[r2][c2] - matA[r1][c2] * matA[r2][c1];
            float cof = ((i + j) % 2 == 0 ? 1 : -1) * minor;
            
            Adjoint[j][i] = cof;
        }
    }

    printf("\n--- Adjoint Matrix ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", Adjoint[i][j]);
        }
        printf("\n");
    }
    
    if (det == 0) {
        printf("\nInverse does not exist (Determinant is 0).\n");
    } else {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                Inverse[i][j] = Adjoint[i][j] / det;
            }
        }
        printf("\n--- Inverse Matrix ---\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%8.2f ", Inverse[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
