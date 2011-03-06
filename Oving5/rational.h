#ifndef RATIONAL_H
#define RATIONAL_H
#include <ostream>
#include <istream>
class Rational {
  private:
    long int numerator;   //Teller
    long int denominator; //Nevner
    void setNumerator ( long int newNumerator );
    void setDenominator ( long int newDenominator );
  public:
    Rational( long int newNumerator, long int newDenominator);
    Rational();    
    long int getNumerator() const;
    long int getDenominator() const;
    long int gcd();
    void simplify();
    
    //Del 4
    const Rational operator ++ (int);
    const Rational& operator ++ ();
    const Rational operator -- (int);
    const Rational& operator -- ();
    
    //Del 5
    const Rational& operator +=(Rational& r1);
    const Rational& operator -=(Rational& r1);
    const Rational& operator /=(Rational& r1);
    const Rational& operator *=(Rational& r1);
};

// Del 2
/*
 * Bruker ikke friend siden jeg ikke trenger det, og
 * innkapsling > friend
 */
bool operator == (const Rational& r1, const Rational& r2);
bool operator != (const Rational& r1, const Rational& r2);
bool operator < (const Rational& r1, const Rational& r2);
bool operator > (const Rational& r1, const Rational& r2);
bool operator >= (const Rational& r1, const Rational& r2);
bool operator <= (const Rational& r1, const Rational& r2);

// Del 3
Rational operator + (const Rational& r1, const Rational& r2);
Rational operator - (const Rational& r1, const Rational& r2);
Rational operator * (const Rational& r1, const Rational& r2);
Rational operator / (const Rational& r1, const Rational& r2);

//Del 6
std::ostream& operator << (std::ostream& out, Rational& r1);
const std::istream& operator >> (const std::istream& in, Rational& r1);

#endif // RATIONAL_HRational(1,1)
