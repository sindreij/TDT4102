#include <iostream>
using namespace std;

int main() {
  double tall1;
  double tall2;
  cout << "Skriv inn et tall: ";
  cin >> tall1;
  cout << "Skriv inn enda et tall: ";
  cin >> tall2;
  if (tall1 > tall2) {
    cout << tall1 << " er størst" << endl;
  } else {
    cout << tall2 << " er størst" << endl;
  }
}

