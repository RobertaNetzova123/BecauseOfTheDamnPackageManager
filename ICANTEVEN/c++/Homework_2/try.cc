#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

long gcd(long number1, long number2) {
	long dividor;
	if(number1 < number2) {
		dividor = number1;
	}
	else {
		dividor = number2;
	}

	if(dividor < 0) {
		dividor = dividor * -1;
	}

	while (number1 % dividor != 0 || number2 % dividor != 0) {
		dividor--;
    	}	
    
    return dividor;
}

class Exception {
	string error;
	public:

	Exception(string msg) : error(msg) {}
	string get_error() {
		return error;
	}
};

class Rational {
	long numerator_;
	long denominator_;

public:
	
	Rational(long numerator = 1, long denominator = 1) 
	: numerator_(numerator), denominator_(denominator) {}

	
	void retrenchment() {
		long dividor = gcd(numerator_, denominator_);
		numerator_ = numerator_ / dividor;
		denominator_ = denominator_ / dividor; 
	}

	long get_numerator() const{
		return numerator_;
	}

	long get_denominator() const{
		return denominator_;
	}

	Rational& set_numerator(long numerator) {
		numerator_ = numerator;
		return *this;
	}

	Rational& set_denominator(long denominator) {
		denominator_ = denominator;
		return *this;
	}

	Rational& add(const Rational& another) {
		numerator_ = numerator_ * another.denominator_ + denominator_ * another.numerator_;
		denominator_ = denominator_ * another.denominator_;
		return *this;
	}

	Rational& subtract(const Rational& another) {
		numerator_ = numerator_ * another.denominator_ - denominator_ * another.numerator_;
		denominator_ = denominator_ * another.denominator_;
		return *this;
	}

	Rational& multiply(const Rational& another) {
		numerator_ = numerator_ * another.numerator_;
		denominator_ = denominator_ * another.denominator_;
		return *this;
	}
	
	Rational& divide(const Rational& another) {
		numerator_ = numerator_ * another.denominator_;
		denominator_ = denominator_ * another.numerator_;
		return *this;
	}
};


Rational operator+(const Rational& n1, const Rational& n2) {
	Rational result(n1.get_numerator(), n1.get_denominator());
	result.add(n2);
	return result;
}

Rational operator-(const Rational& n1, const Rational& n2) {
	Rational result(n1.get_numerator(), n1.get_denominator());
	result.subtract(n2);
	return result;
}

Rational operator*(const Rational& n1, const Rational& n2) {
	Rational result(n1.get_numerator(), n1.get_denominator());
	result.multiply(n2);
	return result;
}

Rational operator/(const Rational& n1, const Rational& n2) {
	Rational result(n1.get_numerator(), n1.get_denominator());
	result.divide(n2);
	return result;
}

ostream& operator<<(ostream& out, const Rational& n) {
	out << "(" << n.get_numerator() << "/" << n.get_denominator() << ")";
	return out;
}

istream& operator>>(istream& in, Rational& n) {
	long numerator;
	long denominator;
	char symbol;

	in >> symbol;
	if(symbol != '(') {
		in.clear(ios_base::badbit);
		return in;
	} 

	in >> numerator >> symbol;

	if(symbol != '/') {
		in.clear(ios_base::badbit);
		return in;
	}

	in >> denominator >> symbol;

	if(symbol != ')') {
		in.clear(ios_base::badbit);
		return in;
	}

	if(in.good()) {
		n.set_numerator(numerator);
		n.set_denominator(denominator);
	}

	return in;
}

int main() {

	string input;
	while(input != "q") {

		char symbol;
		cout << "> ";
		getline(cin, input);
	
		istringstream in(input);
		Rational answer;
		in >> answer;
		if(in.fail()) {
			throw Exception("That is not correct. Please, input a rational number");
		}

		in >> symbol;
		while(symbol != '=') { 

			Rational number;
			in >> number;
			if(in.fail()) {
				throw Exception("That is not correct. Please, input a rational number");	
			}

			if(symbol == '+') {
				answer = answer + number;
			}
		        if(symbol == '-') {
				answer = answer - number;
			}
			if(symbol == '*') {
				answer = answer * number;
			}
			if(symbol == '/') {
				answer = answer / number;
			}

			in >> symbol;	
		}

		if(answer.get_numerator() != 0 && answer.get_denominator() != 0) {
			answer.retrenchment();
		} 
		else {	
			answer.set_numerator(0);
			answer.set_denominator(1);
		}

		cout << answer << endl;
	}	
	return 0;
}













