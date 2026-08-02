// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
#include <iostream>
#include <climits>

void printFirstNTerms(int N) {
    if (N <= 0) {
        std::cout << "Error: N must be a positive integer." << std::endl;
        return;
    }

    std::cout << "Fibonacci sequence: ";

    long long a = 0, b = 1;
    for (int i = 1; i <= N; ++i) {
        if (i == 1) {
            std::cout << a;
        } else if (i == 2) {
            std::cout << " " << b;
        } else {
            // check for potential overflow before adding
            if (b > LLONG_MAX - a) {
                // If overflow would occur, stop printing safely.
                std::cout << " [stopped - overflow]" << std::endl;
                return;
            }
            long long c = a + b;
            std::cout << " " << c;
            a = b;
            b = c;
        }
    }
    std::cout << std::endl;
}

bool isFibonacciNumber(long long x) {
    if (x < 0) return false; // Fibonacci sequence defined here as non-negative numbers

    if (x == 0) return true;
    long long a = 0, b = 1;
    // iterate until b >= x or overflow would occur
    while (b < x) {
        if (b > LLONG_MAX - a) break; // would overflow on next sum
        long long c = a + b;
        a = b;
        b = c;
    }
    return b == x;
}

int main() {
    std::cout << "Choose operation:\n";
    std::cout << "1 - Print the first N Fibonacci terms (Part A)\n";
    std::cout << "2 - Check if a number is a Fibonacci number (Part B)\n";
    std::cout << "Enter choice (1-2): ";

    int choice;
    if (!(std::cin >> choice)) return 0;

    if (choice == 1) {
        int N;
        std::cout << "How many terms? ";
        if (!(std::cin >> N)) return 0;
        printFirstNTerms(N);
    } else if (choice == 2) {
        long long x;
        std::cout << "Enter a number to check: ";
        if (!(std::cin >> x)) return 0;
        if (isFibonacciNumber(x))
            std::cout << x << " is a Fibonacci number." << std::endl;
        else
            std::cout << x << " is NOT a Fibonacci number." << std::endl;
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}
// =============================================================================

#include <iostream>
using namespace std;

