#include <iostream>

class Complex {
	private:
		double _real;
		double _imag;

	public:
		Complex ();
		Complex (double &real);
		Complex (double real, double imag);
		Complex (const Complex &value);
		~Complex ();

		double real() const; //Different name
		double imag() const;

		void print();

		Complex add(Complex);
		Complex sub(Complex);
		Complex mult(Complex);
		Complex div(Complex);

		double magnitude();
		double phase();

		Complex operator+ (Complex value);
		Complex operator- (Complex value);
		Complex operator* (Complex value);
		Complex operator/ (Complex value);
		Complex operator= (Complex value);

		std::ostream& operator << (std::ostream &out, const Complex &c1);
		std::istream& operator >> (std::istream &in, Complex &c1);

};
