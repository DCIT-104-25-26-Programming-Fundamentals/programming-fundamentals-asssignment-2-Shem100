// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
#include <iostream>
#include <iomanip>

void printSingleTable(int number) {
    std::cout << "Multiplication Table for " << number << ":\n";
    for (int i = 1; i <= 12; ++i) {
        // Format similar to the example: number  x  i  =  product
        std::cout << number
                  << "  x  "
                  << std::setw(2) << i
                  << "  =  "
                  << std::setw(3) << (number * i)
                  << '\n';
    }
}

void printTablesUpToN(int N) {
    for (int num = 1; num <= N; ++num) {
        printSingleTable(num);
        if (num != N) {
            std::cout << "---------------------------\n";
        }
    }
}

int main() {
    std::cout << "Choose operation:\n";
    std::cout << "1 - Single multiplication table (Part A)\n";
    std::cout << "2 - Tables from 1 to N (Part B)\n";
    std::cout << "Enter choice (1-2): ";

    int choice;
    if (!(std::cin >> choice)) return 0;

    if (choice == 1) {
        int number;
        std::cout << "Enter a number: ";
        if (!(std::cin >> number)) return 0;
        printSingleTable(number);
    } else if (choice == 2) {
        int N;
        std::cout << "Enter N: ";
        if (!(std::cin >> N)) return 0;
        if (N <= 0) {
            std::cout << "Error: N must be a positive integer." << std::endl;
            return 0;
        }
        printTablesUpToN(N);
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}
// =============================================================================

#include <iostream>
using namespace std;

