#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cout.precision(2);
  cout.setf(ios::fixed,ios::floatfield);
  double price;
  cout << "Hva er prisen uten mva og tips: ";
  cin >> price;
  double mva = price * 0.0675;
  double tips = (price + mva) * 0.15;
  cout << endl
    << "Price:\t$" << price << endl
    << "Mva:\t$" << mva << endl
    << "Tips:\t$" << tips << endl
    << "Sum:\t$" << price + mva + tips << endl;
}
