#include <iostream>
#include <string>
#include "convertName.h"
#include <cassert>
using namespace std;

/**
 * nameFixer tar inn en string bestående av "Fornavn etternavn" og returner
 * en string med Etternavn, Fornavn
 */
string nameFixer(string name);

void testConvertName() {
  string name = "Sindre Johansen";
  cout << "Før: " << name << endl;
  cout << "Etter: " << "'" << nameFixer(name) << "'" << endl;
  
  cout << "Testing...";
  assert(nameFixer("Nikola Tesla") == "Tesla, Nikola");
  assert(nameFixer("Sindre Johansen") == "Johansen, Sindre");
  assert(nameFixer("Per Pål") == "Pål, Per");
  cout << ": OK" << endl;
}

string nameFixer(string name) {
  string fornavn;
  string etternavn;
  /* Substr(x, y) returnerer en string med tegnene fra name[x] til name[y].
   * Hvis y ikke er med, får vi til enden av strengen.
   * find returnerer indexen til tegnet. Sammen blir det bra. 
   */
  fornavn = name.substr(0, name.find(" "));
  etternavn = name.substr(name.find(" ")+1);
  return etternavn + ", " + fornavn;
}