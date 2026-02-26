#include <iostream>
#include <limits>   // for input validation
using namespace std;

void showMenu() {
    cout << "\n===== Simple Calculator =====\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    double num1, num2;

    do {
        showMenu();
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting Calculator... Goodbye!\n";
            break;
        }

        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "⚠️ Invalid input! Please enter a number.\n";
            continue;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                cout << "Result: " << num1 + num2 << endl;
                break;
            case 2:
                cout << "Result: " << num1 - num2 << endl;
                break;
            case 3:
                cout << "Result: " << num1 * num2 << endl;
                break;
            case 4:
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "⚠️ Error: Division by zero is not allowed!\n";
                break;
            default:
                cout << "⚠️ Invalid choice! Please try again.\n";
        }

    } while (true);

    return 0;
}