// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
#include <iostream>
#include <iomanip>

const int MAX = 10;

void readMatrix(int rows, int cols, int mat[MAX][MAX]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            if (!(std::cin >> mat[i][j])) {
                std::cerr << "Input error.\n";
                std::exit(1);
            }
        }
    }
}

void printMatrix(int rows, int cols, int mat[MAX][MAX]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(6) << mat[i][j];
        }
        std::cout << '\n';
    }
}

void transposeMatrix(int m, int n, int a[MAX][MAX], int t[MAX][MAX]) {
    // result will be n x m
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            t[i][j] = 0; // initialize (not strictly necessary)
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            t[j][i] = a[i][j];
}

void addMatrices(int m, int n, int a[MAX][MAX], int b[MAX][MAX], int s[MAX][MAX]) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            s[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(int m, int n, int p, int a[MAX][MAX], int b[MAX][MAX], int prod[MAX][MAX]) {
    // A is m x n, B is n x p, result is m x p
    // initialize result to 0
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j)
            prod[i][j] = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                prod[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    std::cout << "Choose operation:\n";
    std::cout << "1 - Transpose a matrix (Part A)\n";
    std::cout << "2 - Add two matrices (Part B)\n";
    std::cout << "3 - Multiply two matrices (Part C)\n";
    std::cout << "Enter choice (1-3): ";

    int choice;
    if (!(std::cin >> choice)) return 0;

    if (choice == 1) {
        // Part A - Transpose
        int m, n;
        std::cout << "Enter number of rows: ";
        if (!(std::cin >> m)) return 0;
        std::cout << "Enter number of columns: ";
        if (!(std::cin >> n)) return 0;

        if (m <= 0 || n <= 0 || m > MAX || n > MAX) {
            std::cout << "Error: rows and columns must be between 1 and " << MAX << ".\n";
            return 0;
        }

        int a[MAX][MAX];
        int t[MAX][MAX];

        readMatrix(m, n, a);

        transposeMatrix(m, n, a, t);

        std::cout << "\nOriginal Matrix:\n";
        printMatrix(m, n, a);

        std::cout << "\nTransposed Matrix:\n";
        printMatrix(n, m, t);

    } else if (choice == 2) {
        // Part B - Add
        int m, n;
        std::cout << "Enter number of rows: ";
        if (!(std::cin >> m)) return 0;
        std::cout << "Enter number of columns: ";
        if (!(std::cin >> n)) return 0;

        if (m <= 0 || n <= 0 || m > MAX || n > MAX) {
            std::cout << "Error: rows and columns must be between 1 and " << MAX << ".\n";
            return 0;
        }

        int a[MAX][MAX], b[MAX][MAX], s[MAX][MAX];

        std::cout << "Enter elements for first matrix:\n";
        readMatrix(m, n, a);

        std::cout << "Enter elements for second matrix:\n";
        readMatrix(m, n, b);

        addMatrices(m, n, a, b, s);

        std::cout << "\nMatrix A:\n";
        printMatrix(m, n, a);

        std::cout << "\nMatrix B:\n";
        printMatrix(m, n, b);

        std::cout << "\nResult (A + B):\n";
        printMatrix(m, n, s);

    } else if (choice == 3) {
        // Part C - Multiply
        int m, n, p;
        std::cout << "Enter number of rows of A (M): ";
        if (!(std::cin >> m)) return 0;
        std::cout << "Enter number of columns of A / rows of B (N): ";
        if (!(std::cin >> n)) return 0;
        std::cout << "Enter number of columns of B (P): ";
        if (!(std::cin >> p)) return 0;

        if (m <= 0 || n <= 0 || p <= 0 || m > MAX || n > MAX || p > MAX) {
            std::cout << "Error: dimensions must be between 1 and " << MAX << ".\n";
            return 0;
        }

        int a[MAX][MAX], b[MAX][MAX], prod[MAX][MAX];

        std::cout << "Enter elements for matrix A (" << m << "x" << n << "):\n";
        readMatrix(m, n, a);

        std::cout << "Enter elements for matrix B (" << n << "x" << p << "):\n";
        readMatrix(n, p, b);

        multiplyMatrices(m, n, p, a, b, prod);

        std::cout << "\nMatrix A:\n";
        printMatrix(m, n, a);

        std::cout << "\nMatrix B:\n";
        printMatrix(n, p, b);

        std::cout << "\nResult (A x B):\n";
        printMatrix(m, p, prod);

    } else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

