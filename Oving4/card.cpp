#include <string>
#include <sstream>
using namespace std;

#include "card.h"

void Card::init() {
  value = 1;
  suit = 'S';
}

Card::Card() {
  init();
}

Card::Card ( char suit, int value ) {
  init();
  setValue(value);
  setSuit(suit);
}

int Card::getValue() {
  return value;
}

char Card::getSuit() {
  return suit;
}

string Card::getFace() {
  //Stringstream er flott til å sette sammen strenger.
  stringstream ss;
  ss << getSuit() << getValue();
  return ss.str();
}

void Card::setSuit ( char suit ) {
  string suits = "SHCD";
  //string.find returnerer string::npos hvis strengen ikke
  //inneholder charen den får inn
  if (suits.find(suit) != string::npos) {
    this->suit = suit;
  }
}

void Card::setValue ( int value ) {
  if ((value >= 1) && (value <=13)) {
    this->value = value;
  }
}


