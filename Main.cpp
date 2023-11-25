//
// Created by Christian Winert 11/19/23.
//
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <iomanip>

class Calculator {
public:
    double performOperation(double operand1, double operand2, char op) {
        switch (op) {
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                if (operand2 != 0) {
                    return operand1 / operand2;
                } else {
                    throw std::invalid_argument("Error: Division by zero");
                }
            case '^':
                return std::pow(operand1, operand2);
            case 's':
                return std::sin(operand1);
            case 'c':
                return std::cos(operand1);
            case 't':
                return std::tan(operand1);
            case 'l':
                return std::log(operand1);
            case 'r':
                return std::sqrt(operand1);
            default:
                throw std::invalid_argument("Error: Invalid operator");
        }
    }
};

class UserInterface {
public:
    void displayInstructions() {
        std::cout << "Welcome to the Calculator!\n";
        std::cout << "Enter expressions in the form 'operand1 operator operand2'\n";
        std::cout << "Supported operators: +, -, *, /, ^, s (sin), c (cos), t (tan), l (log), r (sqrt)\n";
        std::cout << "Type 'mem' to see stored results, 'clear' to clear memory\n";
        std::cout << "Type 'exit' to quit the calculator\n";
    }

    void displayMemory(const std::vector<double>& memory) {
        std::cout << "Memory contents: ";
        for (const auto& value : memory) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    void clearMemory(std::vector<double>& memory) {
        memory.clear();
        std::cout << "Memory cleared\n";
    }

    void displayResult(double result) {
        std::cout << "Result: " << std::fixed << std::setprecision(6) << result << "\n";
    }

    void displayError(const std::string& errorMsg) {
        std::cerr << errorMsg << "\n";
    }
};

int main() {
    Calculator calculator;
    UserInterface ui;
    std::vector<double> memory;

    ui.displayInstructions();

    while (true) {
        std::cout << "Enter expression: ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        } else if (input == "mem") {
            ui.displayMemory(memory);
            continue;
        } else if (input == "clear") {
            ui.clearMemory(memory);
            continue;
        }

        std::stringstream ss(input);

        double operand1, operand2;
        char op;

        ss >> operand1 >> op >> operand2;

        if (ss.fail() || ss.peek() != EOF) {
            ui.displayError("Error: Invalid input");
            continue;
        }

        try {
            double result = calculator.performOperation(operand1, operand2, op);

            // Store result in memory
            memory.push_back(result);

            ui.displayResult(result);
        } catch (const std::exception& e) {
            ui.displayError(e.what());
        }
    }

    return 0;
}
