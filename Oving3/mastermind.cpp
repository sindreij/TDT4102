/* mastermind.cpp har funksjoner for å spille mastermind. Et spill der datamaskinen
 * lager en kode som man må prøve å gjette. Hver gang man gjetter får man vite hvor
 * mange riktige man hadde, og hvor mange av disse som også var på rett
 * plass.
 */

#include <iostream>
//Trenges for bl. a. time()
#include <ctime>
//Trenges for bl. a. srand()
#include <cstdlib>
//Trenges for min()
#include <cmath>
#include "mastermind.h"
#include <curses.h>

using namespace std;

/* Konstanter for å få ryddig og fin kode. Koden blir på SIZE bokstaver
 * fra START_LETTER til START_LETTERS + LETTERS-1
 */
const int SIZE = 4;
const int LETTERS = 6;
const char START_LETTER = 'a';

/* Prosedyredefinisjoner */
void fillCodeTable( char code[4]);
void readInput( char guess[4], char code[4]);
char randomChar();
int checkCharactersAndPosition(char guess[SIZE], char code[SIZE]);
int checkCharacters(char guess[SIZE], char code[SIZE]);
void printCode(char code[SIZE]) ;

/* PlayMastermind er hovedfunksjonen som blir kalt av main.cpp
 */
void playMastermind() {
  /* Først seeder vi random-funksjonen */
  srand(time(0));
  //Vi definerer koden og gjettingen som en tabell av char.
  char code[SIZE];
  char guess[SIZE];
  
  //fillCodeTable fyller code-tabellen med fire tilfeldige bokstaver
  fillCodeTable(code);
  //Så definerer vi variabler for å holde på antall korrekte og
  //hvor mange av de som er på korrekt posisjon
  int correctCharacters;
  int correctCharactersAndPosition;
  //tries er hvor mange forsøk vi har hatt.
  int tries = 0;
  
  /* Vi har en enkel gameloop som kjører helt til vi har like mange korrekte
   * bokstaver som det er bokstaver. Siden den uansett må kjøre en gang,
   * bruker vi en do - while - loop.
   */
  do {
    //Vi starter med å øke tries med en, siden vi nå har et nytt forsøk
    tries++;
    /*Så skriver vi ut tries, for at brukeren skal få en indikasjon på
     * hvor mange forsøk han har brukt
     */
    cout << tries << ": ";
    //readInput henter inn SIZE bokstaver fra brukeren
    readInput(guess, code);
    //correctCharacters og correctCharactersAndPosition sjekker hvor mange riktige det er.
    correctCharacters = checkCharacters(guess, code);
    correctCharactersAndPosition = checkCharactersAndPosition(guess, code);
    //Så skriver det ut
    cout << "Du hadde " << correctCharacters << " riktige bokstaver." << endl
      << "Av de var " << correctCharactersAndPosition << " på riktig plass." << endl << endl;
    //Vi hopper ut av løkken hvis SIZE = correctCharactersAndPosition
  } while (correctCharactersAndPosition < SIZE);
  /* Så gir vi brukeren en liten tilbakemelding når han har klart det. Han får også vite antall
   * forsøk
   */
  cout << "YAY. Du vant. Gratulerer. Du klarte det på " << tries << " forsøk." << endl;
}

/* randomChar returnerer enkelt og greit en bokstav mellom START_LETTER
 * og START_LETTER + LETTERS-1
 */
char randomChar() {
  return START_LETTER + (rand() % LETTERS);
}

/* fillCodeTable bruker randomChar SIZE antall ganger for å fylle en tabell
 * over koden brukeren skal gjette. 
 */
void fillCodeTable(char code[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    code[i] = randomChar();
  }
}

/* readInput leser inn input fra brukeren i en tabell, validerer den 
 * og spør på nytt hvis den ikke blir validert (Vi tar også inn
 * code for at cheat skal fungere)
 */
void readInput(char guess[SIZE], char code[SIZE]) {
  /* vi leser inn en vanlig string via cin litt under. Her blir strengen definert
   */
  string inn;
  /* Vi kjører alt i en while-loop siden vi ikke gir oss før brukeren gir oss
   * en skikkelig streng med bokstaver.
   */
  while(true) {
    //Brukeren får et lite spørsmål
    cout << "Skriv inn " << SIZE << " bokstaver mellom " << START_LETTER << " og " << (char)(START_LETTER + LETTERS-1) << ":" << endl;
    cin >> inn;
    //Litt juksekode-kode. Flott for debugging.
    if (inn == "rosebud") {
      cout << "PST: Koden er: ";
      printCode(code);
      cout << endl;
      //Og så får brukeren prøve igjen
      continue;
    }
    //Vi har nå en streng, inn, den validerer vi
    if (inn.length() == SIZE) {
      //strengen er riktig lengde, vi må sjekke om den består av riktige bokstaver
      bool correctLetters = true;
      for (int i = 0; i< SIZE; i++) {
	if ((inn[i] < START_LETTER) || (inn[i] > START_LETTER + LETTERS-1)) {
	  correctLetters = false;
	  /* Har vi en bokstav som ikke er riktig, hopper vi ut av denne
	   * løkken, vi behøver ikke lete etter flere uriktige bokstaver
	   */
	  break; //for
	}
      }
      if (correctLetters) {
	/* Hvis bokstavene også er riktige, kan vi hoppe ut av
	 * while-løkken
	 */
	break; // while
      }
    }
    //Er vi fremdeles her, så er det noe feil. Brukeren får prøve på nytt.
    cout << "Feil i innskrivingen. Prøv igjen. ";
  }
  /* Vi er ute av while-løkken, det betyr at vi har en korrekt input.
   * Så er det bare å kopiere det over i guess
   */
  for (int i = 0; i< SIZE; i++) {
    guess[i] = inn[i];
  }
}


/* checkCharacters sjekker hvor mange bokstaver som er riktige ved å telle hvor mange
 * bokstaver det er av hver type i code og guess. Så finner vi antall korrekte ved å 
 * se hvor mange ganger de forskjellige bokstavene er i den korrekte koden og
 * gjettningen. Antall korrekte for hver bokstav blir det minste av disse to tallene.
 */
int checkCharacters(char guess[], char code[]) {
  //Først teller vi opp antall av de forskjellige bokstavene i gjettningen
  int countLettersGuess[LETTERS];
  for (int i = 0; i<LETTERS; i++) {
    countLettersGuess[i] = 0;
  }
  for (int i = 0; i<SIZE; i++) {
    //Vi lar START_LETTER være 0. START_LETTER+1 = 1 osv
    countLettersGuess[guess[i]-START_LETTER]++;
  }
  
  //Så gjør vi det samme i den korrekte koden.
  int countLettersCode[LETTERS];
  for (int i = 0; i<LETTERS; i++) {
    countLettersCode[i] = 0;
  }
  for (int i = 0; i<SIZE; i++) {
    countLettersCode[code[i]-START_LETTER]++;
  }
  
  /* Så finner vi antall korrekte ved å se hvor mange ganger de forskjellige bokstavene
   * er i den korrekte koden og gjettningen. Antall korrekte for hver bokstav blir
   * det minste av disse to tallene.
   */
  int correct = 0;
  for (int i = 0; i<LETTERS; i++) {
    correct += min(countLettersCode[i], countLettersGuess[i]);
  }
  return correct;
}

/* checkCharactersAndPosition er greiere. Den sjekker hvor mange bokstaver som er
 * riktige og på rett plass. Dette gjør den ved å sammeligne de to tabellene. For
 * hver bokstav som er lik, øker correct med 1
 */
int checkCharactersAndPosition(char guess[], char code[]) {
  int correct = 0;
  for (int i = 0; i<SIZE; i++) {
    if (guess[i] == code[i]) {
      correct++;
    }
  }
  return correct;
}

/* printCode skriver ut en tabell med SIZE chars uten mellomrom
 */
void printCode(char code[SIZE]) {
  for (int i = 0; i<SIZE; i++) {
    cout << code[i];
  }
}
    
    
    
    
    
    
    
    
    
    
    