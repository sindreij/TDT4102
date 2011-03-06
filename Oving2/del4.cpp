#include <cctype>
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

bool sameCase(char, char);
int siffer(int tall);
double gjsnitt(double tall1, double tall2);


int main () {
  cout << "\n";
  cout << "Test1: Sjekker sameCase: ";
  assert(sameCase('a','c'));
  assert(sameCase('H','K'));
  assert(!sameCase('H','k'));
  assert(!sameCase('a','C'));
  cout << "\tOK" << endl;

  cout << "Test2: Sjekker siffer: ";
  assert(siffer(5612) == 4);
  assert(siffer(10) == 2);
  assert(siffer(1238123) == 7);
  assert(siffer(99) == 2);
  cout << "\t\tOK" << endl;

  cout << "Test3: Tester gjsnitt: ";
  assert(abs(gjsnitt(5,2)-3.5) < 0.001);
  assert(abs(gjsnitt(10,10)-10) < 0.001);
  assert(abs(gjsnitt(8,4) - 6) < 0.001);
  cout << "\t\tOK" << endl;

  cout << "\nAlle tester OK.\n" << endl;
}

bool sameCase(char a, char b) {
  return (isupper(a) && isupper(b)) || (islower(a) && islower(b));
}

int siffer(int tall) {
  return floor(log10(tall)) + 1;
}

double gjsnitt(double tall1, double tall2) {
  return (tall1+tall2)/2;
}
