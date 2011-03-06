#include "rational.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

Rational::Rational( long newNumerator, long newDenominator) {
    numerator = 0;
    denominator = 1;
    setNumerator(newNumerator);
    setDenominator(newDenominator);
}

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

void Rational::setNumerator ( long newNumerator ) {
    numerator = newNumerator;
    simplify();
}

void Rational::setDenominator ( long newDenominator ) {
    /* Skal brøken være negativ, så vil vi at det er
     * telleren som skal ha negativt tegn.
     */
    if (newDenominator < 0) {
        newDenominator *= -1;
        numerator *= -1;
    }
    if (newDenominator != 0) {
        denominator = newDenominator;
        simplify();
    }
}

long int Rational::gcd() {
    long a = abs(numerator);
    long b = abs(denominator);
    while (b != 0) {
        long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

/*
 * Del 3
 */

const Rational Rational::operator++(int ) {
  Rational old;
  old.numerator = numerator;
  old.denominator = denominator;
  numerator += denominator;
  simplify();
  return old;
}

const Rational& Rational::operator++() {
  numerator += denominator;
  simplify();
  return *this;
}

const Rational Rational::operator--(int ) {
  Rational old;
  old.numerator = numerator;
  old.denominator = denominator;
  numerator -= denominator;
  simplify();
  return old;
}

const Rational& Rational::operator--() {
  numerator += denominator;
  simplify();
  return *this;
} 


/*
 * Del 5
 */

const Rational& Rational::operator+=(Rational& r1) {
  *this = *this + r1;
  return *this;
}

const Rational& Rational::operator*=(Rational& r1) {
  *this = *this * r1;
  return *this;
}

const Rational& Rational::operator-=(Rational& r1) {
  *this = *this - r1;
  return *this;
}

const Rational& Rational::operator/=(Rational& r1) {
  *this = *this / r1;
  return *this;
}

/* 
 * Del 6
 */

std::ostream& operator << (std::ostream& out, Rational& r1) {
  out << r1.getNumerator() << "/" << r1.getDenominator();
  return out;
}

const std::istream& operator >> (const std::istream& in, Rational& r1) {
    string line;
    cin >> line;
    stringstream det;
    stringstream num;
    bool inDeterminant = true;
    for (int i = 0; i<line.length(); i++) {
      char c = line[i];
      if (isdigit(c)) {
	if (inDeterminant) {
	  det << c;
	} else {
	  num << c;
	}
      }
      if (c == '/') {
	inDeterminant = false;
      }
    }
    int intDet;
    int intNum;
    det >> intDet;
    num >> intNum;
    r1 = Rational(intDet, intNum);
}


/*
 * Del 1
 */


void Rational::simplify() {
    long deler = gcd();
    numerator /= deler;
    denominator /= deler;
}

long int Rational::getDenominator() const {
    return denominator;
}

long int Rational::getNumerator() const {
    return numerator;
}

/*
 * Del 2
 */


bool operator == (const Rational& r1, const Rational& r2) {
    return (r1.getNumerator() * r2.getDenominator()) == (r2.getNumerator() * r1.getDenominator());
}

bool operator != (const Rational& r1, const Rational& r2) {
    return !(r1 == r2);
}

bool operator < (const Rational& r1, const Rational& r2) {
    return (r1.getNumerator() * r2.getDenominator()) < (r2.getNumerator() * r1.getDenominator());
}

bool operator > (const Rational& r1, const Rational& r2) {
    return !(r1 <= r2);
}

bool operator >= (const Rational& r1, const Rational& r2) {
    return !(r1 < r2);
}

bool operator <= (const Rational& r1, const Rational& r2) {
    return (r1 < r2) || (r1 == r2);
}

/*
 * Del 2
 */


Rational operator + (const Rational& r1, const Rational& r2) {
    long num1 = r1.getNumerator();
    long num2 = r2.getNumerator();

    long den1 = r1.getDenominator();
    long den2 = r2.getDenominator();

    num1 *= den2;
    num2 *= den1;

    return Rational(num1+num2, den1*den2);
}

Rational operator - (const Rational& r1, const Rational& r2) {
    long num1 = r1.getNumerator();
    long num2 = r2.getNumerator();

    long den1 = r1.getDenominator();
    long den2 = r2.getDenominator();

    num1 *= den2;
    num2 *= den1;

    return Rational(num1-num2, den1*den2);
}

Rational operator * (const Rational& r1, const Rational& r2) {
    return Rational(r1.getNumerator()*r2.getNumerator(),
                    r1.getDenominator()*r2.getDenominator());
}

Rational operator / (const Rational& r1, const Rational& r2) {
    return Rational(r1.getNumerator()*r2.getDenominator(),
                    r1.getDenominator()*r2.getNumerator());
}









