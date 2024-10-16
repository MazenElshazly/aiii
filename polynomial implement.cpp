#include "Polynomial.h"
#include <cmath>
#include <iostream>
using namespace std;

// Default constructor
Polynomial::Polynomial() : coefficients(1, 0) {}

// Constructor with given coefficients
Polynomial::Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {}

// Display function
void Polynomial::display() const {
    bool first = true;
    for (int i = coefficients.size() - 1; i >= 0; --i) {
        if (coefficients[i] != 0) {
            if (!first && coefficients[i] > 0) {
                cout << " + ";
            }
            if (i == 0) {
                cout << coefficients[i];
            } else if (i == 1) {
                cout << coefficients[i] << "x";
            } else {
                cout << coefficients[i] << "x^" << i;
            }
            first = false;
        }
    }
    if (first) {
        cout << 0;  // Case for zero polynomial
    }
    cout << endl;
}

// Differentiate the polynomial
Polynomial Polynomial::differentiate() const {
    if (coefficients.size() <= 1) {
        return Polynomial();  // Derivative of a constant is 0
    }
    vector<double> derivativeCoeffs(coefficients.size() - 1);
    for (int i = 1; i < coefficients.size(); ++i) {
        derivativeCoeffs[i - 1] = coefficients[i] * i;
    }
    return Polynomial(derivativeCoeffs);
}

// Integrate the polynomial (indefinite integration)
Polynomial Polynomial::integrate() const {
    vector<double> integralCoeffs(coefficients.size() + 1);
    integralCoeffs[0] = 0;  // Integration constant (indefinite integration)
    for (int i = 0; i < coefficients.size(); ++i) {
        integralCoeffs[i + 1] = coefficients[i] / (i + 1);
    }
    return Polynomial(integralCoeffs);
}

// Definite integration between limits a and b
double Polynomial::integrate(double a, double b) const {
    Polynomial indefiniteIntegral = integrate();
    return indefiniteIntegral.evaluate(b) - indefiniteIntegral.evaluate(a);
}

// Evaluate the polynomial at a given value of x
double Polynomial::evaluate(double x) const {
    double result = 0;
    for (int i = coefficients.size() - 1; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}

// Find roots (only for linear and quadratic polynomials)
void Polynomial::findRoots() const {
    int degree = coefficients.size() - 1;
    if (degree == 1) {
        // Linear equation: ax + b = 0
        double root = -coefficients[0] / coefficients[1];
        cout << "Root: " << root << endl;
    } else if (degree == 2) {
        // Quadratic equation: ax^2 + bx + c = 0
        double a = coefficients[2];
        double b = coefficients[1];
        double c = coefficients[0];
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            cout << "No real roots." << endl;
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "One real root: " << root << endl;
        } else {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Two real roots: " << root1 << " and " << root2 << endl;
        }
    } else {
        cout << "Root finding is only implemented for linear and quadratic polynomials." << endl;
    }
}

// Operator overloading for polynomial addition
Polynomial Polynomial::operator+(const Polynomial& other) const {
    int maxDegree = max(coefficients.size(), other.coefficients.size());
    vector<double> resultCoeffs(maxDegree, 0);
    for (int i = 0; i < maxDegree; ++i) {
        if (i < coefficients.size()) {
            resultCoeffs[i] += coefficients[i];
        }
        if (i < other.coefficients.size()) {
            resultCoeffs[i] += other.coefficients[i];
        }
    }
    return Polynomial(resultCoeffs);
}

// Operator overloading for polynomial subtraction
Polynomial Polynomial::operator-(const Polynomial& other) const {
    int maxDegree = max(coefficients.size(), other.coefficients.size());
    vector<double> resultCoeffs(maxDegree, 0);
    for (int i = 0; i < maxDegree; ++i) {
        if (i < coefficients.size()) {
            resultCoeffs[i] += coefficients[i];
        }
        if (i < other.coefficients.size()) {
            resultCoeffs[i] -= other.coefficients[i];
        }
    }
    return Polynomial(resultCoeffs);
}

// Operator overloading for polynomial multiplication
Polynomial Polynomial::operator*(const Polynomial& other) const {
    vector<double> resultCoeffs(coefficients.size() + other.coefficients.size() - 1, 0);
    for (int i = 0; i < coefficients.size(); ++i) {
        for (int j = 0; j < other.coefficients.size(); ++j) {
            resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    return Polynomial(resultCoeffs);
}
