#include <iostream>
using namespace std;

double callByValue(double a);
void callByReference(double& a);

int main() {
  double a = 10;
  cout << "a = " << a << endl;
  cout << "Call by value: " << callByValue(a) << endl;
  cout << "a = " << a << endl;
  callByReference(a);
  cout << "Call by reference: " << a << endl;
  cout << "a = " << a << endl;
}


double callByValue(double a) {
  return ((a*a+10)*2);
}

void callByReference(double& a) {
  a = (a*a+10)*2;
}
