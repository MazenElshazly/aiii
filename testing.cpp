#include <iostream>
#include <vector>
#include "Polynomial.h"
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T> & v)
{
    os << '[';
    for (int i = 0; i < v.size(); ++i)
    {
        if (i != v.size() - 1)
        {
            os << v[i] << ", ";
        }else
        {
            os << v[i];
        }
    }
    os << ']' << endl;
    return os;
}
void inputCoefficients(Polynomial& poly) {
    int degree;
    cin >> degree;

    vector<double> coeffs(degree + 1);

    for (int i = 0; i <= degree; ++i)
    {
        cin >> coeffs[i];
    }

    poly.setCoefficients(coeffs);
}
int main()
{
    Polynomial p1, p2;
    inputCoefficients(p1);
    inputCoefficients(p2);
    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;
    cout << "Sum: " << p1 + p2 << endl;
    cout << "Subtraction: " <<  p1 - p2 << endl;
    cout << "Product: " << p1 * p2 << endl;
    cout << "Degree of Polynomial 1: " << p1.degree() << endl;
    cout << "Evaluation of P1 at x = 2: " << p1.evaluate(2) << endl;
    cout << "Derivative of P1: " << p1.derivative() << endl;
    cout << "Integral of P1: " << p1.integral() << endl;
    cout << "Integral of P1 from 0 to 1: " << p1.integral(0,1) << endl;
    cout << "Real roots of P1: " << p1.getRoots() << endl;

}