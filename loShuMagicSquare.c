#include <stdlib.h>
#include <stdio.h>

int rowSum(int *square, int row); // Gets the sum of the specified row
int columnSum(int *square, int column); // Gets the sum of the specified column
int isMagicSquare(int *square); // Checks if the square is a magic square
void printSquare(int *square); // Formats and prints the square

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
                    printf("Invalid value: %s; exiting...\n", argv[i]);
                    return EXIT_FAILURE;
                }
                square[idx / 3][idx % 3] = value;
            }
        } else {
            // User provided arguments, but did not provide the amount of values required
            printf("Not enough arguments provided (need 9 values; got %d).\n", argc - 1);
            return EXIT_FAILURE;
        }
    } else {
        // If user does not provide any arguments:
        // - Create matrix that is a magic square
        // - Create matrix that is not a magic square
        // - Create a randomized matrix until is a magic square is found
    }
    
    return EXIT_SUCCESS;
}

int rowSum(int *square, int row) {
    return 0; // Placeholder return
}

int columnSum(int *square, int column) {
    return 0; // Placeholder return
}

int isMagicSquare(int *square) {
    // Sum each row

    // Sum each column

    // Sum both diagonals

    // Check that all sums are equal to each other

    // Return result
    return 1; // Placeholder return
}

void printSquare(int *square) {
    // Print square
}