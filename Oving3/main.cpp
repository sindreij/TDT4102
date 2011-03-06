#include <iostream>

//telefonnr.h deklarerer testTelefonNr
#include "telefonnr.h"
//mastermind.h deklarerer playMastermind
#include "mastermind.h"
using namespace std;

int main() {
  cout << "*** Velkommen til Oving 3 ***" << endl;
  cout << "-------------------------" << endl << endl;
  cout << "************************" << endl;
  cout << "* Del 1 og 2: Tabeller *" << endl;
  cout << "************************" << endl;
  testTelefonNr();
  
  cout << endl;
  cout << "********************" << endl;
  cout << "* Del 3 Mastermind *" << endl;
  cout << "********************" << endl;
  playMastermind();
  cout << endl << "*** The End ***";
}