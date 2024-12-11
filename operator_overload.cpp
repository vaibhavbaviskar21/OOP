#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:

    Complex() : real(0.0), imag(0.0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        } else {
            os << " - " << -c.imag << "i";
        }
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        double r, i;
        is >> r >> i;
        c = Complex(r, i);
        return is;
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter two complex numbers (real and imaginary parts): ";
    cin >> c1 >> c2; 

    cout << "Complex number 1: " << c1 << endl; 
    cout << "Complex number 2: " << c2 << endl; 

    Complex sum = c1 + c2; 
    Complex product = c1 * c2; 

    cout << "Sum: " << sum << endl; 
    cout << "Product: " << product << endl;

    return 0;
}