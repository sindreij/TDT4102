#include <iostream>
using namespace std;

int main() {
  double x;
  cout << "Hva er x: ";
  cin >> x;
  cout << "y = x^2 + (6x-2)/3" << endl;
  double y = x*x + (6*x-2)/3;
  cout << "y = " << y << endl;
}
