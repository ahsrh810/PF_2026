#include <stdio.h>

void printGrid(int (*grid)[5]) {
    int r, c;
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col) {
    int count = 0;
    int dr, dc;
    for (dr = -1; dr <= 1; dr++) {
        for (dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            int r = row + dr;
            int c = col + dc;
            if (r >= 0 && r < 5 && c >= 0 && c < 5) {
                count += (grid[r][c] & 1);
            }
        }
    }
    return count;
}

void nextGeneration(int (*grid)[5]) {
    int r, c;
    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            int currentState = grid[r][c] & 1;
            int neighbors = countNeighbours(grid, r, c);
            int nextState = 0;

            if (currentState == 1) {
                if (neighbors == 2 || neighbors == 3) {
                    nextState = 1;
                }
            } else {
                if (neighbors == 3) {
                    nextState = 1;
                }
            }

            grid[r][c] |= (nextState << 1);
        }
    }

    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            grid[r][c] >>= 1;
        }
    }
}

int main() {
    int grid[5][5] = {0};
    int gen, i;

    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    do {
        printf("Enter number of generations (0-50): ");
        scanf("%d", &gen);
        if (gen < 0 || gen > 50) {
            printf("Invalid number\n");
        }
    } while (gen < 0 || gen > 50);

    for (i = 0; i <= gen; i++) {
        printf("Generation %d:\n", i);
        printGrid(grid);
        if (i < gen) {
            nextGeneration(grid);
        }
    }

    return 0;
}