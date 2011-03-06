#include <iostream>
using namespace std;

int main() {
  int sekunder;
  cout << "Skriv antall sekunder: ";
  cin >> sekunder;

  cout << sekunder/(60*60) << " timer, "
    << (sekunder%(60*60))/60 << " minutter, "
    << sekunder%(60*60)%60 << " sekunder" << endl;
}


