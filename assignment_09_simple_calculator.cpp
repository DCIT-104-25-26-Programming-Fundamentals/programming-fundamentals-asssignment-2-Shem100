// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <optional>

double add(double a, double b) {
    return a + b;
}

double subtractOp(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

std::optional<double> divide(double a, double b) {
    if (b == 0.0) return std::nullopt;
    return a / b;
}

std::optional<long long> modulus(long long a, long long b) {
    if (b == 0) return std::nullopt;
    return a % b;
}

double exponentiate(double base, double exp) {
    return std::pow(base, exp);
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printMenu() {
    std::cout << "============================\n";
    std::cout << "     SIMPLE CALCULATOR\n";
    std::cout << "============================\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Modulus\n";
    std::cout << "6. Exponentiation\n";
    std::cout << "7. Quit\n";
    std::cout << "Select an operation (1-7): ";
}

int main() {
    while (true) {
        printMenu();
        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Error: Invalid menu choice. Please enter a number between 1 and 7.\n";
            clearInput();
            continue;
        }

        if (choice == 7) {
            std::cout << "Goodbye!\n";
            break;
        }

        if (choice >= 1 && choice <= 4 || choice == 6) {
            double a, b;
            std::cout << "Enter first number : ";
            if (!(std::cin >> a)) {
                std::cout << "Error: Invalid input for first number.\n";
                clearInput();
                continue;
            }
            std::cout << "Enter second number: ";
            if (!(std::cin >> b)) {
                std::cout << "Error: Invalid input for second number.\n";
                clearInput();
                continue;
            }

            std::ios::fmtflags f = std::cout.flags(); // save format flags
            std::cout << std::fixed << std::setprecision(2);

            switch (choice) {
                case 1: {
                    double res = add(a, b);
                    std::cout << "Result: " << a << " + " << b << " = " << res << "\n";
                    break;
                }
                case 2: {
                    double res = subtractOp(a, b);
                    std::cout << "Result: " << a << " - " << b << " = " << res << "\n";
                    break;
                }
                case 3: {
                    double res = multiply(a, b);
                    std::cout << "Result: " << a << " * " << b << " = " << res << "\n";
                    break;
                }
                case 4: {
                    auto resOpt = divide(a, b);
                    if (!resOpt.has_value()) {
                        std::cout << "Error: Cannot divide by zero.\n";
                    } else {
                        std::cout << "Result: " << a << " / " << b << " = " << resOpt.value() << "\n";
                    }
                    break;
                }
                case 6: {
                    double res = exponentiate(a, b);
                    std::cout << "Result: " << a << " ^ " << b << " = " << res << "\n";
                    break;
                }
                default:
                    break;
            }

            std::cout.flags(f); // restore format flags
            // leave remaining input untouched (no unconditional clear)
        }
        else if (choice == 5) {
            long long a, b;
            std::cout << "Enter first integer : ";
            if (!(std::cin >> a)) {
                std::cout << "Error: Invalid input for first integer.\n";
                clearInput();
                continue;
            }
            std::cout << "Enter second integer: ";
            if (!(std::cin >> b)) {
                std::cout << "Error: Invalid input for second integer.\n";
                clearInput();
                continue;
            }
            auto resOpt = ::modulus(a, b);
            if (!resOpt.has_value()) {
                std::cout << "Error: Cannot perform modulus by zero.\n";
            } else {
                std::cout << "Result: " << a << " % " << b << " = " << resOpt.value() << "\n";
            }
        }
        else {
            std::cout << "Invalid choice. Please select a number between 1 and 7.\n";
            // no need to clear input here
        }
    }

    return 0;
}
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

