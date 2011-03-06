#include <iostream>
using namespace std;

int main() {
  int tall;
  cout << "Skriv inn et tall: ";
  cin >> tall;
  if (tall%2==0) {
    cout << "Tallet er et partall" << endl;
  } else {
    cout << "Tallet er et oddetall" << endl;
  }
}
