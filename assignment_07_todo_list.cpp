// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <limits>

void printMenu() {
    std::cout << "============================\n";
    std::cout << "     TO-DO LIST MENU\n";
    std::cout << "============================\n";
    std::cout << "1. Add task\n";
    std::cout << "2. View tasks\n";
    std::cout << "3. Delete task\n";
    std::cout << "4. Quit\n";
    std::cout << "Enter your choice (1-4): ";
}

void addTask(std::vector<std::string>& tasks) {
    std::cout << "Enter task: ";
    std::string task;
    std::getline(std::cin >> std::ws, task); // read whole line, skipping leading whitespace/newline
    if (task.empty()) {
        std::cout << "No task entered. Nothing added.\n";
        return;
    }
    tasks.push_back(task);
    std::cout << "Task added: \"" << task << "\"\n";
}

void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in your to-do list.\n";
        return;
    }
    std::cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << (i + 1) << ". " << tasks[i] << "\n";
    }
}

void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete.\n";
        return;
    }
    viewTasks(tasks);
    std::cout << "Enter task number to delete: ";
    int num;
    if (!(std::cin >> num)) {
        std::cout << "Error: Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    if (num < 1 || static_cast<size_t>(num) > tasks.size()) {
        std::cout << "Error: Invalid task number.\n";
        // consume rest of line (if any)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    // store task for confirmation, then erase
    std::string removed = tasks[num - 1];
    tasks.erase(tasks.begin() + (num - 1));
    std::cout << "Task \"" << removed << "\" has been removed.\n";
    // consume rest of line (if any)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<std::string> tasks;
    while (true) {
        printMenu();
        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Error: Please enter a number between 1 and 4.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // consume the newline so subsequent getline works
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
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
using namespace std;

