#include <stdio.h>

int checkRow(int grid[9][9], int row) {
    int seen[10] = {0};   // index 1–9 used

    for (int col = 0; col < 9; col++) {
        int val = grid[row][col];
        if (val < 1 || val > 9) return 0;   // invalid number
        if (seen[val] == 1) return 0;       // duplicate
        seen[val] = 1;
    }
    return 1;
}

int checkCol(int grid[9][9], int col) {
    int seen[10] = {0};

    for (int row = 0; row < 9; row++) {
        int val = grid[row][col];
        if (val < 1 || val > 9) return 0;
        if (seen[val] == 1) return 0;
        seen[val] = 1;
    }
    return 1;
}

int checkBox(int grid[9][9], int startRow, int startCol) {
    int seen[10] = {0};

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            int val = grid[startRow + r][startCol + c];
            if (val < 1 || val > 9) return 0;
            if (seen[val] == 1) return 0;
            seen[val] = 1;
        }
    }
    return 1;
}

int main() {
    int grid[9][9];

    printf("Enter a 9x9 Sudoku grid:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Check all rows
    for (int i = 0; i < 9; i++) {
        if (!checkRow(grid, i)) {
            printf("Invalid\n");
            return 0;
        }
    }

    // Check all columns
    for (int i = 0; i < 9; i++) {
        if (!checkCol(grid, i)) {
            printf("Invalid\n");
            return 0;
        }
    }

    // Check all 3×3 boxes
    for (int r = 0; r < 9; r += 3) {
        for (int c = 0; c < 9; c += 3) {
            if (!checkBox(grid, r, c)) {
                printf("Invalid\n");
                return 0;
            }
        }
    }

    printf("Valid\n");
    return 0;
}
