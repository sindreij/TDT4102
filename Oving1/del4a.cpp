#include <iostream>
using namespace std;

int main () {
  double nok;
  while (true) {
    cout << "NOK: ";
    cin >> nok;
    if (nok >= 0) {
      double eur = nok/9.22;
      cout << nok << "NOK = " << eur << "EUR" << endl;
      break;
    } else {
      cout << "Negative kroner er ikke bra. Prøv igjen." << endl;
    }
  }
}
