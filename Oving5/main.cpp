#include <iostream>
#include "rational.h"
#include <cassert>
using namespace std;

int main(int argc, char **argv) {
  cout << "Tester rational..." << endl;
  cout << "------------------" << endl;
  Rational a = Rational(1,2);
  Rational b = Rational(1,4);
  Rational c = Rational(4,8);
  Rational d = Rational(1,1);
  Rational e = Rational(0,1);
  cout << "Tester Del 2:";

  assert(a>b);
  assert(a>=b);
  assert(b<a);
  assert(b<=a);

  assert(c>b);
  assert(c>=b);
  assert(b<c);
  assert(b<=c);

  assert(a==a);
  assert(a>=a);
  assert(b==b);
  assert(c==c);

  assert(a==c);
  assert(a<=c);
  assert(c>=a);

  cout << " .. OK" << endl;
  
  cout << "Tester Del 3:" << flush;
  flush(cout);
  
  assert(a+a==d);
  assert(a*a==b);
  assert(a-b-b==e);
  
  for (int num1 = 1; num1<=30; num1++) {
    for (int den1 = 1; den1<=30; den1++) {
      for (int num2 = 1; num2<=30; num2++) {
	for (int den2 = 1; den2<=30; den2++) {
	  Rational r1 = Rational(num1, den1);
	  Rational r2 = Rational(num2, den2);
	  assert(r1+r2-r1 == r2);
	  assert(r1+r2 == r2+r1);
	  
	  assert(r1*r2 == r2*r1);
	  assert(r1*r2/r1 == r2);
	}
      }   
    }
  }
  cout << " .. OK" << endl;
  {
    cout << "Tester Del 4:";
    
    Rational var = Rational(1,2);
    Rational check = Rational(3,2);
    
    assert(var++ == a);
    assert(var == check);
    var = Rational(1,2);
    assert(++var == check);
    
    cout << " .. OK" << endl;
  }
  
  {
    cout << "Tester Del 5:";
    
    Rational var = Rational(1,2);
    Rational en = Rational(1,1);
    Rational check = Rational(3,2);
    
    var += en;
    assert(var == check);
    
    var = Rational(1,1);
    Rational to = en + en;
    var /= to;
    assert(var == Rational(1,2));
    
    var *= to;
    
    assert(var == en);
    
    var -= to;
    
    assert(var == Rational(-1,1));
    
    cout << " .. OK" << endl;
  }
  
  {
    cout << "Del 6.." << endl;
    Rational a = Rational(1,2);
    Rational b = Rational(3,2);
    Rational c = Rational(24,30);
    cout << a << " " << b << " " << c << endl;
    
    cout << "Skriv en brøk som a/b: ";
    Rational inn;
    cin >> inn;
    Rational pluss = Rational(1,1);
    Rational sum = inn + pluss;
    cout << inn << "+" << pluss << "=" << sum << endl;
  } 

}
