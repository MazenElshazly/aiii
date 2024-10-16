#include "Polynomial.h"
#include <iostream>
using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\nPolynomial Menu: " << endl;
    cout << "1. Display Polynomials" << endl;
    cout << "2. Input new Polynomials" << endl;
    cout << "3. Add two Polynomials" << endl;
    cout << "4. Subtract two Polynomials" << endl;
    cout << "5. Multiply two Polynomials" << endl;
    cout << "6. Differentiate Polynomial 1" << endl;
    cout << "7. Integrate Polynomial 1" << endl;
    cout << "8. Definite Integral of Polynomial 1" << endl;
    cout << "9. Find Roots of Polynomial 1" << endl;
    cout << "10. Evaluate Polynomial 1 at a point" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to input a polynomial from the user
Polynomial inputPolynomial() {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    vector<double> coefficients(degree + 1); // Size = degree + 1 to store all terms

    cout << "Enter the coefficients from the constant term to the highest degree:" << endl;
    for (int i = 0; i <= degree; i++) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }

    return Polynomial(coefficients);
}

int main() {
    Polynomial p1;  // Default polynomial
    Polynomial p2;  // Default polynomial
    bool hasPolynomials = false;  // To track if polynomials have been input

    int choice;
    double x, a, b;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:  // Display Polynomials
                if (hasPolynomials) {
                    cout << "Polynomial 1: ";
                    p1.display();
                    cout << "Polynomial 2: ";
                    p2.display();
                } else {
                    cout << "Please input two polynomials first." << endl;
                }
                break;

            case 2:  // Input new Polynomials
                cout << "Input Polynomial 1:" << endl;
                p1 = inputPolynomial();
                cout << "Input Polynomial 2:" << endl;
                p2 = inputPolynomial();
                hasPolynomials = true;
                cout << "Polynomials have been input successfully." << endl;
                break;

            case 3:  // Add two Polynomials
                if (hasPolynomials) {
                    Polynomial sum = p1 + p2;
                    cout << "Sum of polynomials: ";
                    sum.display();  // Display the result
                } else {
                    cout << "Please input two polynomials first." << endl;
                }
                break;

            case 4:  // Subtract two Polynomials
                if (hasPolynomials) {
                    Polynomial difference = p1 - p2;
                    cout << "Difference of polynomials: ";
                    difference.display();  // Display the result
                } else {
                    cout << "Please input two polynomials first." << endl;
                }
                break;

            case 5:  // Multiply two Polynomials
                if (hasPolynomials) {
                    Polynomial product = p1 * p2;
                    cout << "Product of polynomials: ";
                    product.display();  // Display the result
                } else {
                    cout << "Please input two polynomials first." << endl;
                }
                break;

            case 6:  // Differentiate Polynomial 1
                if (hasPolynomials) {
                    Polynomial derivative = p1.differentiate();
                    cout << "Derivative of Polynomial 1: ";
                    derivative.display();  // Display the result
                } else {
                    cout << "Please input two polynomials first." << endl;
                }
                break;

            case 7:  // Integrate Polynomial 1 (Indefinite integral)
                if (hasPolynomials) {
                    Polynomial integral = p1.integrate();
                    cout << "Indefinite integral of Polynomial 1: ";
                    integral.display();  // Display the result
                } else {
                    cout << "Please input two polynomials first." << endl;
                }
                break;

            case 8:  // Definite Integral of Polynomial 1
                if (hasPolynomials) {
                    cout << "Enter lower limit of integration (a): ";
                    cin >> a;
                    cout << "Enter upper limit of integration (b): ";
                    cin >> b;
                    double definiteIntegral = p1.integrate(a, b);
                    cout << "Definite integral of Polynomial 1 from " << a << " to " << b << ": " << definiteIntegral << endl;
                } else {
                    cout << "Please input two polynomials first." << endl;
                }
                break;

            case 9:  // Find Roots of Polynomial 1 (Only for linear and quadratic polynomials)
                if (hasPolynomials) {
                    cout << "Finding roots of Polynomial 1: " << endl;
                    p1.findRoots();  // The method will display the roots internally
                } else {
                    cout << "Please input two polynomials first." << endl;
                }
                break;

            case 10:  // Evaluate Polynomial 1 at a point
                if (hasPolynomials) {
                    cout << "Enter a value for x: ";
                    cin >> x;
                    cout << "Polynomial 1 evaluated at x = " << x << ": " << p1.evaluate(x) << endl;
                } else {
                    cout << "Please input two polynomials first." << endl;
                }
                break;

            case 0:  // Exit
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
