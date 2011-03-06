#ifndef CARD_H
#define CARD_H

#include <string>
/*
 * Card er en klasse som er et kort. Den har en value og en suit
 */
class Card {
  private:
    int value;
    char suit;
    /*
     * Setter vaue og suit til standardverdier. Blir kalt av
     * begge konstruktørene
     */
    void init();
  public:
    /* Initialiserer objektet ved å kalle init
     */
    Card();
    /* Initialiserer objektet ved å kalle init
     * og så prøve å sette suit til suit og value til value.
     * Bruker setValue og setSuit slik at det blir sjekket for
     * ulovlige verdier
     */
    Card(char suit, int value);
    /* Returnerer verdien av kortet
     */
    int getValue();
    /* Returnerer suiten til kortet
     */
    char getSuit();
    /* Returnerer en streng med value og suit.
     */
    std::string getFace();
    /* Sjekker verdien og setter den hvis den er riktig. Er ikke verdien riktig
     * blir den ikke endretGjør ikke så mye annet enn å 
     */
    void setValue ( int value );
    /* Sjekker verdien og setter den hvis den er riktig. Er ikke verdien riktig
     * blir den ikke endretGjør ikke så mye annet enn å 
     */
    void setSuit ( char suit );

};

#endif // CARD_H

