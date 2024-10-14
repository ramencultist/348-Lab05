#include <stdio.h>

//Kyle Fleming
//93089
//Frida 1 pm
//Lab 05
// Program that takes TWO PREDEFINED matrixes and applies matrix functions to them
//collaborators - None

#define SIZE 5  // constant for matrix size

// add two matrices and store the result
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];  // Add corresponding elements of m1 and m2
        }
    }
}

// multiply two matrices and store the result
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Initialize the result to zero
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
        }
    }

    // matrix multiplication
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// transpose a matrix and store the result
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];  // swapping rows and columns
        }
    }
}

// print a matrix in a user-friendly (readable) format
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);  // Print each element with a tab space
        }
        printf("\n");  // New line after each row
    }
}

int main() {
    // Sample matrices m1 and m2 given in instructions pdf
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int sum[SIZE][SIZE];        // sum of m1 and m2
    int product[SIZE][SIZE];    // product of m1 and m2
    int transpose[SIZE][SIZE];  // transpose of given matrix

    // addition of m1 and m2
    addMatrices(m1, m2, sum);
    printf("Sum of m1 and m2:\n");
    printMatrix(sum);

    // multiplication of m1 and m2
    multiplyMatrices(m1, m2, product);
    printf("Product of m1 and m2:\n");
    printMatrix(product);

    // Transpose of matrix given
    transposeMatrix(m1, transpose);
    printf("Transpose of m1:\n");
    printMatrix(transpose);

    return 0;
}

