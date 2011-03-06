#include "carddeck.h"
#include "card.h"
#include <cstdlib>

CardDeck::CardDeck() {
  buildDeck();
  numberDealt = 0;
}

CardDeck::CardDeck(bool shouldShuffle) {
  buildDeck();
  numberDealt = 0;
  if (shouldShuffle) {
    shuffle();
  }
}

void CardDeck::buildDeck() {
  char suits[4] = {'S', 'H', 'D', 'C'};
  for (int suit = 0; suit < 4; suit++) {
    for (int value = 0; value < 13; value++) {
      cards[suit*13+value] = Card(suits[suit], value+1);
    }
  }
}

void CardDeck::swapCards(int index1, int index2) {
    Card tmp = cards[index1];
    cards[index1] = cards[index2];
    cards[index2] = tmp;
}

void CardDeck::shuffle() {
  for (int i = 0; i<100; i++) {
    swapCards(rand()%52, rand()%52);
  }
}

void CardDeck::dealHand ( Card out[], int numberOfCards ) {
  if ((52 - numberDealt) < numberOfCards) {
    return;
  }
  for (int i=0; i<numberOfCards; i++) {
    out[i] = cards[i+numberDealt];
  }
  numberDealt += numberOfCards;#include "carddeck.h"
}

Card CardDeck::getCard(int index) {
  return cards[index];
}