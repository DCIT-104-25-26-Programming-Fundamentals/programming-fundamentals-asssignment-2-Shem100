// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
#include <iostream>
#include <vector>
#include <iomanip>

double computeSum(const std::vector<double>& arr) {
    double s = 0.0;
    for (size_t i = 0; i < arr.size(); ++i) {
        s += arr[i];
    }
    return s;
}

double computeAverage(const std::vector<double>& arr) {
    if (arr.empty()) return 0.0;
    double s = computeSum(arr);
    return s / static_cast<double>(arr.size());
}

double findMaximum(const std::vector<double>& arr) {
    // assume arr is non-empty when called
    double mx = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > mx) mx = arr[i];
    }
    return mx;
}

double findMinimum(const std::vector<double>& arr) {
    // assume arr is non-empty when called
    double mn = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < mn) mn = arr[i];
    }
    return mn;
}

int main() {
    int n;
    std::cout << "How many numbers? ";
    if (!(std::cin >> n)) return 0; // abort on input error

    if (n <= 0) {
        std::cout << "Error: Number of elements must be a positive integer." << std::endl;
        return 0;
    }

    std::vector<double> nums;
    nums.reserve(n);

    for (int i = 0; i < n; ++i) {
        double x;
        std::cout << "Enter number " << (i + 1) << ": ";
        if (!(std::cin >> x)) {
            std::cout << "Input error." << std::endl;
            return 0;
        }
        nums.push_back(x);
    }

    std::cout << std::endl << "Results:" << std::endl;
    double sum = computeSum(nums);
    double avg = computeAverage(nums);
    double mx = findMaximum(nums);
    double mn = findMinimum(nums);

    // Print results. Average with one decimal like the example.
    std::cout << "Sum:     " << ( (sum == (long long)sum) ? std::to_string((long long)sum) : std::to_string(sum) ) << std::endl;
    std::cout << "Average: " << std::fixed << std::setprecision(1) << avg << std::endl;
    std::cout << "Maximum: " << ( (mx == (long long)mx) ? std::to_string((long long)mx) : std::to_string(mx) ) << std::endl;
    std::cout << "Minimum: " << ( (mn == (long long)mn) ? std::to_string((long long)mn) : std::to_string(mn) ) << std::endl;

    return 0;
}
// =============================================================================

#include <iostream>
using namespace std;

