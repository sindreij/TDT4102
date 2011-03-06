#ifndef CARDDECK_H
#define CARDDECK_H

#include "card.h"

class CardDeck {
  private:
    Card cards[52];    
    int numberDealt;
    void buildDeck();
    void swapCards(int index1, int index2);
  public:
    CardDeck();
    CardDeck(bool shouldShuffle);
    void dealHand(Card out[], int numberOfCards);
    void shuffle();
    Card getCard( int index);
};

#endif // CARDDECK_H
