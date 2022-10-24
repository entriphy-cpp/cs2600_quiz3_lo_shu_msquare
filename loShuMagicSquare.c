#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int rowSum(int square[3][3], int row); // Gets the sum of the specified row
int columnSum(int square[3][3], int column); // Gets the sum of the specified column
int diagonalSum(int square[3][3], int diagonal); // Gets the sum of the specified column
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
    int square[3][3];

    // Check argument count (should be equal to 10)
    if (argc > 1) {
        if (argc > 9) {
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
        } else {
            // User provided arguments, but did not provide the amount of values required
            printf("Not enough arguments provided (need 9 values; got %d).\n", argc - 1);
            return EXIT_FAILURE;
        }
    } else {
        // If user does not provide any arguments:
        printf("Usage: loShuMagicSquare [square]\n");
        printf("\tProvide 9 square values to test if the square is a Lo Shu Magic Square (all rows, columns, and diagonals add up to the same number).\n");
        printf("Running tests...\n");

        // Create square that is a magic square
        memcpy(square, MAGIC_SQUARE, sizeof(square));
        printf("Valid magic square:\n");
        printSquare(square);

        // Create square that is not a magic square
        memcpy(square, NOT_MAGIC_SQUARE, sizeof(square));
        printf("Invalid magic square:\n");
        printSquare(square);

        // Create a randomized square until is a magic square is found
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

int isMagicSquare(int square[3][3]) {
    // Sum each row

    // Sum each column

    // Sum both diagonals

    // Check that all sums are equal to each other

    // Return result
    return 1; // Placeholder return
}

void printSquare(int square[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("[%d %d %d]\n", square[i][0], square[i][1], square[i][2]);
    }
}