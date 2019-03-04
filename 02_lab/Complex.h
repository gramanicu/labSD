#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <iostream>
#include <math.h>

class Complex {
   public:
    double re;
    double im;

    Complex(double re, double im) {
        this->re = re;
        this->im = im;
    }

    Complex(const Complex& other) {
        this->re = other.re;
        this->im = other.im;
    }

    void operator=(const Complex& other) {
        this->re = other.re;
        this->im = other.im;
    }

    ~Complex() {}

    Complex operator+(const Complex& other) {
        return Complex(this->re + other.re, this->im + other.im);
    }

    Complex operator-(const Complex& other) {
        return Complex(this->re - other.re, this->im - other.im);
    }

    Complex operator*(const Complex& other) {
        return Complex(this->re * other.re - this->im * other.im,
                       this->re * other.im - this->im * other.re);
    }

    float modulus() {
        return std::sqrt(std::pow(this->re, 2) + std::pow(this->im, 2));
    }

    float segment(const Complex& other) {
        return std::sqrt(std::pow(other.re - this->re,
                         2) + std::pow(other.im - this->im, 2));
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& complex);
};

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if(complex.im>=0) {
        out << complex.re << " + " << complex.im << "i\n";
    } else {
        out << complex.re << " - " << std::abs(complex.im) << "i\n";
    }
    return out;
}

#endif
