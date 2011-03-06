#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

int storstePrimtall(int tall);
void storstePrimtallReference(int& tall);

int main() {
  cout << "Tester storstePrimtall: ";
  assert(storstePrimtall(42) == 7);
  assert(storstePrimtall(9) == 3);
  int a = 42;
  storstePrimtallReference(a);
  assert(a==7);
  cout << "OK" << endl << endl;
  cout << "Skriv ett tall: ";
  int tall;
  cin >> tall;
  cout << "storste primtall = " << storstePrimtall(tall) << endl << endl;
}

int storstePrimtall(int tall) {
  int testTall = 2;
  int result = 0;
  while (tall != 1) {
    if (tall%testTall == 0) {
      tall = tall/testTall;
      result = testTall;
    } else {
      testTall++;
    }
  }
  return result;
}

void storstePrimtallReference(int& tall) {
  tall = storstePrimtall(tall);
}
