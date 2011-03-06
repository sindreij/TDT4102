/* telefonnr.cpp har implementert funksjoner for å forandre på en liste med
 * telefonnumre og en liste med hvor mange ganger de er ringt på
 * forskjellige dager i en uke. 
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

//Funksjonen testTelefonNr blir deklarert i telefonnr.h
#include "telefonnr.h"

using namespace std;

/*For å bare ha ett sted hvor lang en uke er. Dette kommer sannsynligvis ikke
 * til å endre seg med det første, men det er mer logisk å skrive ringt[LENGTH_WEEK-1] enn ringt[6]
 * Siden man av den første får info om context.
 * Dette er globalt siden antall dager i en uke er rimelig konstant.
 */
const int LENGHT_WEEK = 7;

/*Disse funksjonene brukes bare her, og blir derfor ikke deklarert
 * i header-fila
 */
void printArray(int array[], int length);
void printRingtArray(int ringt[][LENGHT_WEEK],
    int phoneNumbers[],
    int phoneNumbersLenght);
void randomizeList(int antall,
    int ringt[][LENGHT_WEEK], int lenght);

/* testTelefonNr blir kalt av main.cpp og tester
 * alle funksjonene i denne filen
 */
void testTelefonNr() {
  /*Når LENGTH_PHONE_NUMBERS blir deklarert her, så 
   * er det bare ett sted å endre hvis vi skal ha flere
   * telefonnumre. Dette er ikke globalt, siden vi kan
   * tenkes å ha flere lister med forskjellig antall
   * telefonnummre
   */
  const int LENGHT_PHONE_NUMBERS = 5;
  //Random må seedes
  srand(time(0));

  /*Vi setter de forskjellige telefonnumrene. Kunne også gjort det tilfeldig, 
   * men det står ikke noe om det i beskrivelsen.
   */
  int phoneNumbers[LENGHT_PHONE_NUMBERS] = {
    66765432,
    76528391,
    90907822,
    89786756,
    66775544};
  //Så skriver vi ut alle telefonnumrene.
  cout << "Telefonnummerne: ";
  printArray(phoneNumbers, LENGHT_PHONE_NUMBERS);

  //ringt lagrer antall telefonsamtaler pr dag pr telefonnr
  int ringt[LENGHT_PHONE_NUMBERS][LENGHT_WEEK];
  //Vi må resette antall ringt alle dager alle telefonnumre til 0
  for (int number = 0; number < LENGHT_PHONE_NUMBERS; number++) {
    for (int day = 0; day < LENGHT_WEEK; day++) {
      ringt[number][day] = 0;
    }
  }
  //Så legger vi på litt tilfeldighet
  randomizeList(100, ringt, LENGHT_PHONE_NUMBERS);
  //Og til slutt printer vi ut hele sullmitten
  printRingtArray(ringt, phoneNumbers, LENGHT_PHONE_NUMBERS);
}

/* randomizeList øker et tilfeldig telefonnummer en tilfeldig dag antall ring
 * med 1. Dette gjøres antall ganger.
 * Pga minneting må vi ha med lengde på dimensjon 2 av arrayet, men det er greit
 * siden LENGHT_WEEK er en global konstant. Antall telefonnummre tar vi inn via
 * length.
 */
void randomizeList(int antall,
    int ringt[][LENGHT_WEEK], int lenght)
{
  //Det under skal kjøres antall ganger
  for (int i=0; i<antall; i++){
    /*Finner et tilfeldig nummer og en tilfeldig dag og øker
     * antall ringte med en.
     */
    int number = rand() % lenght;
    int day = rand() % LENGHT_WEEK;
    ringt[number][day]++;
  }
}

/* printArray printer ut en hvilken som helst endimensjonal array.
 * den printer medlemmene adskilt med linjeskift.
 */
void printArray(int array[], int length){
  for (int i = 0; i<length; i++){
    cout << "- " << array[i] << endl;
  }
}

/* printRingtArray er en spesialfunksjon som skriver ut en liste over dager og telefonnummer og
 * hvor mange ganger det telefonnummeret er ringt den dagen. ringt er en todimensjonal liste over
 * phoneNumbersLength antall telefonnumre med LENGTH_WEEK dager. phoneNumbers er en liste over
 * phoneNumbersLength telefonnumre. Dette for å skrive de ut for å få litt context.
 */
void printRingtArray ( int ringt[][LENGHT_WEEK], int phoneNumbers[], int phoneNumbersLenght ) {
  //Pent formatert overskrift
  cout << "Nummer\t\tMa\tTi\tOn\tTo\tFr\tLo\tSo" << endl;
  cout << "------\t\t--\t--\t--\t--\t--\t--\t--" << endl;
  //Skriver ut en pent formatert liste
  for (int i=0; i<phoneNumbersLenght; i++) {
    cout << phoneNumbers[i] << "\t";
    for (int j=0; j<LENGHT_WEEK; j++) {
      cout << ringt[i][j] << "\t";
    }
    //Linjeskift etter alle dagene og når vi skal skrive ut nytt telefonnummer
    cout << endl;
  }
}
