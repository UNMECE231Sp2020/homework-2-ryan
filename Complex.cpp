#include <iostream>
#include <Math.h>
#include "Complex.h"

Complex::Complex(){
	_real=0;
	_imag=0;
}

Complex::Complex (double real, double imag){
	_real = real;
	_imag = imag;
}

Complex::Complex (const Complex &c1){
	_real = c1._real;
	_imag = c1._imag;
}

Complex::~Complex(){
	std::cout << "Done" << std::endl;
}

double Complex::real() const {
	return _real;
}

double Complex::imag() const {
	return _imag;
}

void Complex::print(){
	if (imag() < 0){
		std::cout << _real << "-" << _imag*-1 << "i" << std::endl; 
		return;
	}
	std::cout << _real << "+" << _imag << "i" << std::endl;
}

Complex Complex::add(Complex c1){
	Complex temp(c1.real() + _real, c1.imag() + _imag);
	return temp;
}

Complex Complex::sub(Complex c1){
	Complex temp(_real - c1.real(), _imag - c1.imag());
	return temp;
}

Complex Complex::mult(Complex c1){
	Complex temp((_real*c1.real()) + (_imag*c1.imag()*-1), (_imag*c1.real()) + (_real*c1.imag()));
	return temp;
}

Complex Complex::div(Complex c1.magnitude){
	double denom = c1.magnitude*c1.magnitude;
	if (denom == 0){
		Complex Fun(0, 0);
		std::cout << "Division By Zero" << std::endl;

		return Fun;
	}
	Complex temp(_real, _imag*-1);
	Complex temp1(temp.mult(c1));
	temp1._real /= denom;
	temp1._imag /= denom;

	return temp1;
}

double Complex::magnitude() {
	double result = sqrt(_real*_real + _imag*_imag);
	return result;
}
double Complex::phase() {
	double ph = atan(_real/_imag) * (100/M*PI);
	return (ph<0) = -ph:ph;
}

Complex Complex::operator+(Complex c1){
	return add(c1);
}

Complex Complex::operator-(Complex c1){
	return sub(c1);
}

Complex Complex::operator*(Complex c1){
	return mult(c1);
}

Complex Complex::operator/(Complex c1){
	return div(c1);
}

Complex Complex::operator=(Complex c1){
	_real = c1.real();
	_imag = c1.imag();
	return *this;
}

std::ostream& operator << (std::ostream &out, const Complex &c1){
    if (c1.imag() < 0){
		double temp = -1*c1.imag();
 		out << c1.real() << "-" << temp << "j";
	}
	else {
		out << c1.real() << "+" << temp << "j";
		return out;
	}
}

std::istream& operator >> (std::istream &in, Complex &c1){
	in >> c1._real >> c1._imag;
	return in;
}
