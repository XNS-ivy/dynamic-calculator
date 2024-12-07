#include <iostream>
#include <functional>
#include <map>
#include <string>

void showMenu() {
    std::cout << "\n======= Dynamic Calculator =======\n";
    std::cout << "Select an operation:\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)";
    std::cout << "5. Modulus (%)\n";
    std::cout << "6. Exit\n";
    std::cout << "=================================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::map<std::string, std::function<double(double, double)>> operations;

    // Defining the operations dynamically
    operations["1"] = [](double a, double b) { return a + b; };
    operations["2"] = [](double a, double b) { return a - b; };
    operations["3"] = [](double a, double b) { return a * b; };
    operations["4"] = [](double a, double b) {
        if (b == 0) {
            std::cerr << "Error: Division by zero is undefined.\n";
            return 0.0;
        }
        return a / b;
    };
    operations["5"] = [](double a, double b) -> double {
        if (static_cast<int>(b) == 0) {
            std::cerr << "Error: Modulus by zero is undefined.\n";
            return 0.0;
        }
        return static_cast<int>(a) % static_cast<int>(b);
    };

    while (true) {
        showMenu();
        std::string choice;
        std::cin >> choice;

        if (choice == "6") {
            std::cout << "Exiting program. Goodbye!\n";
            break;
        }

        if (operations.find(choice) == operations.end()) {
            std::cerr << "Invalid choice. Please try again.\n";
            continue;
        }

        double num1, num2;
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        try {
            double result = operations[choice](num1, num2);
            std::cout << "Result: " << result << "\n";
        } catch (const std::exception &e) {
            std::cerr << "An error occurred: " << e.what() << "\n";
        }
    }

    return 0;
}