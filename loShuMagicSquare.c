#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int rowSum(int square[3][3], int row); // Gets the sum of the specified row
int columnSum(int square[3][3], int column); // Gets the sum of the specified column
int diagonalSum(int square[3][3], int diagonal); // Gets the sum of the specified column
int isUniqueSquare(int square[3][3]); // Checks if all values in the square are unique
int isMagicSquare(int square[3][3]); // Checks if the square is a magic square
void printSquare(int square[3][3]); // Formats and prints the square

// Test squares
const int MAGIC_SQUARE[3][3] = {
    {4, 9, 2},
    {3, 5, 7},
    {8, 1, 6}
};
const int NOT_MAGIC_SQUARE[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int main(int argc, char const *argv[]) {
    // Stores the square in a 2D array
    int square[3][3];

    // Check argument count (should be equal to 10)
    if (argc > 1) {
        if (argc < 10) {
            // User provided arguments, but did not provide the amount of values required
            printf("Not enough arguments provided (need 9 values; got %d).\n", argc - 1);
            return EXIT_FAILURE;
        }

        for (int i = 1; i < 10; i++) {
            // Parse values into square
            int idx = i - 1;
            int value = atoi(argv[i]);
            if (value < 1 || value > 9) {
                // User provided a value out of range or was not an integer
                printf("Invalid value: %s (not a value between 1 and 9); exiting...\n", argv[i]);
                return EXIT_FAILURE;
            }
            square[idx / 3][idx % 3] = value;
        }
        printf("Square:\n");
        printSquare(square);

        // Check that square is unique
        if (!isUniqueSquare(square)) {
            printf("Square is not unique; exiting...\n");
            return EXIT_FAILURE;
        }
        
        // Check that square is a magic square
        if (isMagicSquare(square)) {
            printf("Square is a magic square!\n");
        } else {
            printf("Square is not a magic square.\n");
        }
    } else {
        // If user does not provide any arguments:
        printf("Provide 9 square values to test if the square is a Lo Shu Magic Square (all rows, columns, and diagonals add up to the same number).\n");
        printf("Usage: loShuMagicSquare [square]\n");
        printf("Running tests...\n\n");
        int magicSquare;

        // Create square that is a magic square
        memcpy(square, MAGIC_SQUARE, sizeof(square));
        printf("Valid magic square:\n");
        printSquare(square);
        magicSquare = isMagicSquare(square);
        if (magicSquare) {
            printf("Square is a magic square!\n\n");
        } else {
            printf("Square is not a magic square; exiting...\n");
            return EXIT_FAILURE;
        }

        // Create square that is not a magic square
        memcpy(square, NOT_MAGIC_SQUARE, sizeof(square));
        printf("Invalid magic square:\n");
        printSquare(square);
        magicSquare = isMagicSquare(square);
        if (magicSquare) {
            printf("Square is a magic square; exiting...\n");
            return EXIT_FAILURE;
        } else {
            printf("Square is not a magic square.\n\n");
        }

        // Create a randomized square until is a magic square is found
        printf("Generating random sqaures...\n");
        srand(time(NULL)); // Set random number generator seed
        int tries = 0; // Number of tries to find a random magic square
        while (!isMagicSquare(square)) {
            tries++; // Only count tries when a unique square is generated
            do {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        square[i][j] = (rand() % 9) + 1; // Generate a number between 1 and 9
                    }
                }
            } while (!isUniqueSquare(square));
        }
        printf("Found magic square after %d tries:\n", tries);
        printSquare(square);
    }

    return EXIT_SUCCESS;
}

int rowSum(int square[3][3], int row) {
    return square[row][0] + square[row][1] + square[row][2];
}

int columnSum(int square[3][3], int column) {
    return square[0][column] + square[1][column] + square[2][column];
}

int diagonalSum(int square[3][3], int diagonal) {
    // 0 = top left to bottom right, 1 = bottom left to top right
    return diagonal == 0 ? square[0][0] + square[1][1] + square[2][2] : square[2][0] + square[1][1] + square[0][2];
}

int isUniqueSquare(int square[3][3]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == j)
                continue; // Do not compare to self
            if (square[i / 3][i % 3] == square[j / 3][j % 3]) // Compare to other value in square
                return 0; // Square is not unique
        }
    }
    return 1; // Square is unique
}

int isMagicSquare(int square[3][3]) {
    // Get initial sum to check for
    int sum = rowSum(square, 0);

    // Sum each row
    int rowsEqual = rowSum(square, 0) == sum && rowSum(square, 1) == sum && rowSum(square, 2) == sum;
    if (!rowsEqual)
        return 0;

    // Sum each column
    int columnsEqual = columnSum(square, 0) == sum && columnSum(square, 1) == sum && columnSum(square, 2) == sum;
    if (!columnsEqual)
        return 0;

    // Sum both diagonals
    int diagonalsEqual = diagonalSum(square, 0) == sum && diagonalSum(square, 1) == sum;
    if (!diagonalsEqual)
        return 0;
    
    // All rows, columns, and diagonals sum to the same number
    return 1;
}

void printSquare(int square[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("[%d %d %d]\n", square[i][0], square[i][1], square[i][2]);
    }
}