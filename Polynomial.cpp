#include "Polynomial.h"
#include <stdexcept>
// Default constructor
Polynomial::Polynomial() : coeffs(1, 0.0) {}

// Constructor with coefficients
Polynomial::Polynomial(const vector<double>& coefficients) : coeffs(coefficients) {
    // Remove trailing zeros to maintain the correct degree
    while (!coeffs.empty() && coeffs.back() == 0.0) {
        coeffs.pop_back();
    }
}

// Copy constructor
Polynomial::Polynomial(const Polynomial& other) : coeffs(other.coeffs) {}

// Destructor
Polynomial::~Polynomial() {}

// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        coeffs = other.coeffs;
    }
    return *this;
}

// Addition operator
Polynomial Polynomial::operator+(const Polynomial& other) const {
    vector<double> result(max(coeffs.size(), other.coeffs.size()), 0.0);

    for (size_t i = 0; i < result.size(); ++i) {
        if (i < coeffs.size()) result[i] += coeffs[i];
        if (i < other.coeffs.size()) result[i] += other.coeffs[i];
    }

    return Polynomial(result);
}

// Subtraction operator
Polynomial Polynomial::operator-(const Polynomial& other) const {
    vector<double> result(max(coeffs.size(), other.coeffs.size()), 0.0);

    for (size_t i = 0; i < result.size(); ++i) {
        if (i < coeffs.size()) result[i] += coeffs[i];
        if (i < other.coeffs.size()) result[i] -= other.coeffs[i];
    }

    return Polynomial(result);
}

// Multiplication operator
Polynomial Polynomial::operator*(const Polynomial& other) const {
    vector<double> result(coeffs.size() + other.coeffs.size() - 1, 0.0);

    for (size_t i = 0; i < coeffs.size(); ++i) {
        for (size_t j = 0; j < other.coeffs.size(); ++j) {
            result[i + j] += coeffs[i] * other.coeffs[j];
        }
    }

    return Polynomial(result);
}

// Equality operator
bool Polynomial::operator==(const Polynomial& other) const {
    return coeffs == other.coeffs;
}

// Output operator
ostream& operator<<(ostream& out, const Polynomial& poly) {
    for (int i = poly.degree(); i >= 0; --i) {
        if (poly.getCoefficient(i) != 0.0) {
            if (i < poly.degree() && poly.getCoefficient(i) > 0)
                out << "+";
            out << poly.getCoefficient(i);
            if (i > 0)
                out << "x";
            if (i > 1)
                out << "^" << i;
        }
    }

    return out;
}

// Return the degree of the polynomial
int Polynomial::degree() const {
    return coeffs.empty() ? -1 : static_cast<int>(coeffs.size() - 1);
}

// Evaluate the polynomial at x
double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = degree(); i >= 0; --i) {
        result = result * x + getCoefficient(i);
    }
    return result;
}

// Composition of two polynomials
Polynomial Polynomial::compose(const Polynomial& q) const {
    Polynomial result;
    for (int i = degree(); i >= 0; --i) {
        result = result * q + Polynomial({getCoefficient(i)});
    }
    return result;
}

// Derivative of the polynomial
Polynomial Polynomial::derivative() const {
    if (degree() <= 0)
        return Polynomial();

    vector<double> derivCoeffs(degree());
    for (int i = 1; i <= degree(); ++i) {
        derivCoeffs[i - 1] = getCoefficient(i) * i;
    }
    return Polynomial(derivCoeffs);
}

// Return a polynomial of integration
Polynomial Polynomial::integral() const {
    vector<double> integCoeffs(degree() + 2);
    integCoeffs[0] = 0; // Constant of integration set to zero by default

    for (int i = 0; i <= degree(); ++i) {
        integCoeffs[i + 1] = getCoefficient(i) / (i + 1);
    }

    return Polynomial(integCoeffs);
}

// Integrate from x1 to x2
double Polynomial::integral(double x1, double x2) const {
    return integral().evaluate(x2) - integral().evaluate(x1);
}

// Get a root using Newton's method

std::vector<double> Polynomial::getRoots(double lowerBound, double upperBound, double tolerance, int maxIter) {
    std::vector<double> roots; // Vector to store found roots
    double step = (upperBound - lowerBound) / 100; // Step for searching roots

    for (double guess = lowerBound; guess < upperBound; guess += step) {
        double currentGuess = guess;
        for (int iter = 0; iter < maxIter; ++iter) {
            double fValue = evaluate(currentGuess);
            double fDerivativeValue = derivative().evaluate(currentGuess);
            if (fabs(fValue) < tolerance) {
                // Round the root to avoid duplicates
                double roundedRoot = round(currentGuess / tolerance) * tolerance;
                // Check if this root is already found
                if (std::find_if(roots.begin(), roots.end(), [roundedRoot, tolerance](double root) {
                    return fabs(root - roundedRoot) < tolerance;
                }) == roots.end()) {
                    roots.push_back(roundedRoot); // Add root to the list
                }
                break; // Exit loop if root is found
            }
            if (fDerivativeValue == 0) {
                break; // Avoid division by zero
            }
            currentGuess -= fValue / fDerivativeValue;
        }
    }

    return roots; // Return all found roots
}
// Set coefficients
void Polynomial::setCoefficients(const vector<double>& coefficients) {
    coeffs = coefficients;

    // Remove trailing zeros to maintain the correct degree
    while (!coeffs.empty() && coeffs.back() == 0.0)
        coeffs.pop_back();
}

// Get coefficient of a specific degree
double Polynomial::getCoefficient(int degree) const {
    if (degree < 0 || degree >= static_cast<int>(coeffs.size()))
        return 0.0; // Return zero if the degree is out of bounds

    return coeffs[degree];
}