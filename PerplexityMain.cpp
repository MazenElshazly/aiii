#include <iostream>
#include <vector>
#include "Polynomial.h"
using namespace std;

//void displayMenu() {
//    cout << "Polynomial Menu" << endl;
//    cout << "1. Enter coefficients for Polynomial 1" << endl;
//    cout << "2. Enter coefficients for Polynomial 2" << endl;
//    cout << "3. Add Polynomials" << endl;
//    cout << "4. Subtract Polynomials" << endl;
//    cout << "5. Multiply Polynomials" << endl;
//    cout << "6. Evaluate Polynomial 1" << endl;
//    cout << "7. Derivative of Polynomial 1" << endl;
//    cout << "8. Integral of Polynomial 1" << endl;
//    cout << "9. Exit" << endl;
//    cout << "Choose an option (1-9): ";
//}

void inputCoefficients(PolynomialP& poly) {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    vector<double> coeffs(degree + 1);
    cout << "Enter coefficients from constant term to highest degree (e.g., a0, a1, a2...): ";

    for (int i = 0; i <= degree; ++i) {
        cin >> coeffs[i];
    }

    poly.setCoefficients(coeffs);
}

int main() {
     PolynomialP p1, p2; // Declare two polynomial objects

    int choice;

//    while (true) {
//        displayMenu();
//        cin >> choice;
//
//        switch (choice) {
//            case 1: {
//                inputCoefficients(p1);
//                cout << "Polynomial 1 set to: " << p1 << endl;
//                break;
//            }
//            case 2: {
//                inputCoefficients(p2);
//                cout << "Polynomial 2 set to: " << p2 << endl;
//                break;
//            }
//            case 3: {
//                PolynomialP result = p1 + p2;
//                cout << "Result of P1 + P2: " << result << endl;
//                break;
//            }
//            case 4: {
//                PolynomialP result = p1 - p2;
//                cout << "Result of P1 - P2: " << result << endl;
//                break;
//            }
//            case 5: {
//                PolynomialP result = p1 * p2;
//                cout << "Result of P1 * P2: " << result << endl;
//                break;
//            }
//            case 6: {
//                double x;
//                cout << "Enter value of x to evaluate P1: ";
//                cin >> x;
//                double value = p1.evaluate(x);
//                cout << "P1 evaluated at x = " << x << ": " << value << endl;
//                break;
//            }
//            case 7: {
//                PolynomialP derivative = p1.derivative();
//                cout << "Derivative of P1: " << derivative << endl;
//                break;
//            }
//            case 8: {
//                PolynomialP integral = p1.integral();
//                cout << "Integral of P1: " << integral << endl;
//                break;
//            }
//            case 9:
//                cout << "Exiting..." << endl;
//                return 0; // Exit the program
//            default:
//                cout << "Invalid choice! Please try again." << endl;
//        }
//        cout << endl; // Print a new line for better readability
//    }

    return 0; // End of the program
}