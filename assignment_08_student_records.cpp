// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <optional>

struct Student {
    std::string name;
    int id;
    std::vector<double> scores;
};

void printMenu() {
    std::cout << "================================\n";
    std::cout << "   STUDENT RECORD SYSTEM MENU\n";
    std::cout << "================================\n";
    std::cout << "1. Add student\n";
    std::cout << "2. Display all students\n";
    std::cout << "3. Calculate average score\n";
    std::cout << "4. Quit\n";
    std::cout << "Enter your choice (1-4): ";
}

std::optional<double> computeAverage(const std::vector<double>& scores) {
    if (scores.empty()) return std::nullopt;
    double sum = 0.0;
    for (double s : scores) sum += s;
    return sum / static_cast<double>(scores.size());
}

int findStudentIndexById(const std::vector<Student>& students, int id) {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == id) return static_cast<int>(i);
    }
    return -1;
}

void addStudent(std::vector<Student>& students) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear line
    Student s;
    std::cout << "Student name: ";
    std::getline(std::cin, s.name);
    if (s.name.empty()) {
        std::cout << "Error: Name cannot be empty. Student not added.\n";
        return;
    }

    std::cout << "Student ID: ";
    if (!(std::cin >> s.id)) {
        std::cout << "Error: Invalid ID. Student not added.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (findStudentIndexById(students, s.id) != -1) {
        std::cout << "Error: A student with ID " << s.id << " already exists. Student not added.\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    int count;
    std::cout << "How many scores? ";
    if (!(std::cin >> count) || count < 0) {
        std::cout << "Error: Invalid number of scores. Student not added.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    s.scores.reserve(count);
    for (int i = 1; i <= count; ++i) {
        double sc;
        std::cout << "Enter score " << i << ": ";
        if (!(std::cin >> sc)) {
            std::cout << "Error: Invalid score input. Aborting add.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        s.scores.push_back(sc);
    }

    students.push_back(std::move(s));
    std::cout << "Student \"" << students.back().name << "\" added successfully.\n";
    // consume leftover newline if any
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayAllStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students have been added yet.\n";
        return;
    }

    // Header
    std::cout << std::left
              << std::setw(25) << "Name"
              << std::setw(12) << "ID"
              << std::setw(30) << "Scores"
              << std::setw(10) << "Average"
              << '\n';

    std::cout << std::string(77, '-') << '\n';

    for (const auto& s : students) {
        std::cout << std::left << std::setw(25) << s.name
                  << std::setw(12) << s.id;

        // Scores as comma-separated list
        std::string scoresStr;
        for (size_t i = 0; i < s.scores.size(); ++i) {
            if (i) scoresStr += ", ";
            // print score without forcing a specific precision (scores may be ints or decimals)
            std::ostringstream oss;
            oss << s.scores[i];
            scoresStr += oss.str();
        }
        if (scoresStr.size() > 28) {
            // truncate to fit the column if too long
            scoresStr = scoresStr.substr(0, 25) + "...";
        }
        std::cout << std::setw(30) << scoresStr;

        auto avgOpt = computeAverage(s.scores);
        if (avgOpt.has_value()) {
            std::cout << std::fixed << std::setprecision(2) << std::setw(10) << avgOpt.value();
            // reset format flags for next line
            std::cout.unsetf(std::ios_base::floatfield);
        } else {
            std::cout << std::setw(10) << "N/A";
        }

        std::cout << '\n';
    }
}

void calculateAverageForStudent(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students have been added yet.\n";
        return;
    }

    std::cout << "Enter student ID: ";
    int id;
    if (!(std::cin >> id)) {
        std::cout << "Error: Invalid ID.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    int idx = findStudentIndexById(students, id);
    if (idx == -1) {
        std::cout << "Error: Student ID " << id << " not found.\n";
        return;
    }

    const Student& s = students[idx];
    auto avgOpt = computeAverage(s.scores);
    if (avgOpt.has_value()) {
        std::cout << s.name << "'s average score: " << std::fixed << std::setprecision(2) << avgOpt.value() << '\n';
        // reset format flags
        std::cout.unsetf(std::ios_base::floatfield);
    } else {
        std::cout << s.name << " has no scores recorded.\n";
    }
}

int main() {
    std::vector<Student> students;
    while (true) {
        printMenu();
        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Error: Please enter a number between 1 and 4.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageForStudent(students);
                break;
            case 4:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
        }
    }

    return 0;
}
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

