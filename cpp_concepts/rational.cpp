#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class rational {
	int _n = 0;
	int _d = 1;
public:
	rational(int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator) {};
	~rational();
	int numerator() const { return _n; };
	int denominator() const { return _d; };
	rational & operator = ( const rational &);
	//rational operator + (const rational &) const;
	rational operator - (const rational &) const;
	rational operator * (const rational &) const;
	rational operator / (const rational &) const;
	operator std::string () const;
};

rational & rational::operator = (const rational & rhs) {
	if (this != &rhs) {
		_n = rhs.numerator();
		_d = rhs.denominator();
	}
	return *this;
}

rational rational::operator - ( const rational & rhs) const {
	return rational(((_n * rhs._d)- (_d *rhs._n)), (_d * rhs._d));
}
//rational rational::operator + ( const rational & rhs) const {
//	return rational(((_n * rhs._d) + (_d *rhs._n)), (_d * rhs._d));
//}

rational rational::operator * ( const rational & rhs) const {
	return rational(((_n * rhs._n)), (_d * rhs._d));
}
rational rational::operator / ( const rational & rhs) const {
	return rational(((_n * rhs._d)), (_d * rhs._n));
}

rational::~rational() {
    _n = 0; _d = 1;
}

std::ostream & operator << (std::ostream &o, const rational &r) {
	if(r.denominator() == 1) return o << r.numerator();
	else return o << '(' << r.numerator() << ")/(" << r.denominator() << ')';
}

rational operator + ( const rational & lhs, const rational & rhs) {
	return rational(( (lhs.numerator() * rhs.denominator()) + (lhs.denominator() *rhs.numerator())),
		       	(lhs.denominator() * rhs.numerator()));
}

//conversion operator, overloading cast operator
rational::operator std::string () const {
	if(_d == 1) return std::to_string(_n);
	else return std::to_string(_n) + '/' + std::to_string(_d);
}

int main() {
    
    rational a = 3;
    std::cout << "a is: " << a << std::endl;
    rational b(7, 2);
    std::cout << "b is: " << b << std::endl;
    rational c = b;
    std::cout << "c is: " << c << std::endl;
    rational d;
    std::cout << "d is: " << d << std::endl;
    d = c;
    std::cout << "d is: " << d << std::endl;
    rational & e = d;
    d = e;
    cout << "e is: " << e << endl;
    
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << 14 << " + " << b << " = " <<  14 + b << std::endl;
    std::string s = "my string:";
    s += b;
    std::cout << s << endl;
    return 0;
}
