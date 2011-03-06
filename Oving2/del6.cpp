#include <iostream>
#include <cassert>
#include "add.h"
using namespace std;

int main() {
  cout << "Tester add-funksjoner" << endl;
  assert(add(4,5) == 9);
  assert(add(3.5,6.25) == 9.75);
  int a = 1;
  int b = 2;
  int c = 5;
  int d = 1;
  add(a,b,c,d);
  assert(a==1 && b==3 && c==8 && d==9);
  cout << "OK" << endl << endl;
}
