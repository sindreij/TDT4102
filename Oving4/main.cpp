#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

/* Inkluderer de forskjellige .h-filene som har structene og test-prosedyrene
 * som brukes
 */
#include "enumeration.h"
#include "struct.h"
#include "convertName.h"
/* Disse headerene  deklarerer klasser
 */
#include "card.h"
#include "carddeck.h"
using namespace std;

/* Testene for Card-klassen og Card-deck klassen blir deklarer i denne
 * filen
 */
/**
 * Tester Card-klassen
 */
void testCard();
/**
 * Tester CardDeck-klassen
 */
void testCardDeck();

/**
 * I mainfunksjonen tester vi de forskjellige testfunksjonene fra de
 * forskjellige delene av øvingen
 */
int main(int argc, char **argv) {
  srand(time(0));
  
  cout << "***********" << endl;
  cout << "* Øving 4 *" << endl;
  cout << "***********" << endl;
  cout << endl << "* Del 1. Enumeration" << endl;
  
  checkBeatlesEnumeration();
  
  cout << endl << "* Del 2. Struct" << endl;
  
  testStruct();
  
  cout << endl << "* Del 3. String" << endl;
  
  testConvertName();
  
  cout << endl << "* Del 4. Kortklasse" << endl;
  
  testCard();
  
  cout << endl << "* Del 5. Kortkstokklasse" << endl;
  
  testCardDeck();

  
  cout << endl << "** Ferdig **"<<endl <<endl;
}

/**
 * Skriver ut en array med Card med lengde length
 */
void printCards(Card cards[], int lenght) {
  for (int i = 0; i<lenght; i++) {
    cout << cards[i].getFace() << endl;
  }
}

void testCardDeck() {
  CardDeck cardDeck(true);
  cout << "Trekker kort" << endl;
  
  for (int i = 0; i<3; i++) {
    cout << "Trekk nr " << i+1 << endl;
    cout << "----------" << endl;
    Card trekk[4];
    //dealHand gir length (4) kort fra stokken
    cardDeck.dealHand(trekk, 4);
    //Så printer vi de ut.
    printCards(trekk, 4);
  }
}

void testCard() {
  cout << "Testing...";
  Card kort;
  assert(kort.getValue() == 1);
  assert(kort.getSuit() == 'S');
  assert(kort.getFace() == "S1");
  
  kort.setSuit('D');
  kort.setValue(9);
  assert(kort.getSuit() == 'D');
  assert(kort.getValue() == 9);
  assert(kort.getFace() == "D9");
  
  kort.setSuit('Q');
  kort.setValue(88);
  assert(kort.getSuit() == 'D');
  assert(kort.getValue() == 9);
  assert(kort.getFace() == "D9");
  
  kort.setSuit('D');
  kort.setValue(13);
  assert(kort.getSuit() == 'D');
  assert(kort.getValue() == 13);
  assert(kort.getFace() == "D13");
  
  kort.setSuit('H');
  kort.setValue(1);
  assert(kort.getSuit() == 'H');
  assert(kort.getValue() == 1);
  assert(kort.getFace() == "H1");
  cout << ": OK";
}
