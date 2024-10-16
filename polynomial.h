#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>
using namespace std;

class Polynomial {
private:
    vector<double> coefficients;  // Coefficients of the polynomial

public:
    // Constructors
    Polynomial();  // Default constructor
    Polynomial(const vector<double>& coeffs);  // Parameterized constructor

    // Display function to print the polynomial
    void display() const;

    // Operations on polynomials
    Polynomial differentiate() const;  // Differentiate the polynomial
    Polynomial integrate() const;      // Indefinite integration
    double integrate(double a, double b) const;  // Definite integration between limits a and b
    double evaluate(double x) const;   // Evaluate polynomial at a given x

    // Find roots (only for linear and quadratic polynomials)
    void findRoots() const;

    // Operator overloads for +, -, and *
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
};

#endif
