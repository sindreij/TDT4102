#include <iostream>
#include "pointers.h"
#include <cassert>

using namespace std;

void mySwap(int *x, int *y);

void pointers() {
  int a = 1;
  int b = 2;


  mySwap(&a, &b);

  cout << "a = " << a << endl; //a should now be 2
  cout << "b = " << b << endl; //b should now be 1
  assert(a == 2);
  assert(b == 1);
  
  int *c = new int(3);
  int *d = new int(4);


  mySwap(c,d); 

  cout << "*c = " << *c << endl; //*c should now be 4
  cout << "*d = " << *d << endl; //*d should now be 3
  assert(*c == 4);
  assert(*d == 3);
  delete c;
  delete d;
}

void mySwap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}