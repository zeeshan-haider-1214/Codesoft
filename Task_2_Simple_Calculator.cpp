#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    cout << "******Simple Calculator******" << endl;
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero" << endl;
                return 1;
            }
            break;
        default:
            cout << "Invalid operation" << endl;
            return 1;
    }

    cout << "Result: " << result << endl;
    cout<<"*****This is the second Task2*****"<<endl;
    return 0;
}
