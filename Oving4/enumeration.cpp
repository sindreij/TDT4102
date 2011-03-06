#include <iostream>
#include <cassert>
#include "enumeration.h"

using namespace std;

/**
 * isAlive returnerer true hvis den får en beatle som er
 * i live. Det vil si at den returnerer true hvis den
 * får inn PAUL eller RINGO
 */
bool isAlive(Beatle beatle) {
  switch (beatle) {
    case JOHN:
      return false;
    case PAUL:
      return true;
    case GEORGE:
      return false;
    case RINGO:
      return true;
  }
  /* Kunne også vært gjort enklere med
   * return (beatle == PAUL) || (beatle == RINGO);
   */
}

void checkBeatlesEnumeration() {
  cout << "Sjekker enumeration: ";
  assert(!isAlive(JOHN));
  assert(isAlive(RINGO));
  assert(!isAlive(GEORGE));
  assert(isAlive(RINGO));
  cout << "OK" << endl;
}