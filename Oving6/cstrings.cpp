#include <iostream>
#include <cassert>
#include <cstring>
#include <cctype>

using namespace std;
#include "cstrings.h"

void getInput(char** input);
int countCharacters(char* s);
void reverseString(char* s);
bool checkPassword(char* s);

void cstrings() {
  char* test = "Bokstaver";
  assert(countCharacters(test) == 9);
  cout << "Yay. countCharacters virker" << endl;
  
  char* test2 = new char[7+1];
  strcpy(test2, "abcdefg");
  cout << "Før: " << test2 << endl;
  reverseString(test2);
  cout << "Etter: " << test2 << endl;
  
  char *input;
  getInput(&input);
  cout << "Du skrev " << input << endl;
  bool godtPassord = checkPassword(input);
  if (godtPassord) {
    cout << "Det er et skikkelig passord" << endl;
  } else {
    cout << "Det er ikke et skikkelig passord" << endl;
  }
}

/*
 * Vi bruker peker til peker for at resultatet skal bli at vi returnerer
 * en peker med verdi
 */
void getInput(char **input) {
  cout << "Skriv et passord > ";
  string inn = "lala"; 
  cin >> inn;
  *input = new char[inn.length()+1];
  strcpy(*input, inn.c_str());
}

int countCharacters(char* s) {
  int i = 0;
  while (true) {
    if (s[i] == '\0') {
      break;
    }
    i++;
  }
  return i;
}

void reverseString(char* s) {
  int len = countCharacters(s);
  for (int i = 0; i< len/2; i++) {
    char tmp = s[i];
    s[i] = s[len-i-1];
    s[len-i-1] = tmp;
  }
}

bool checkPassword(char* s) {
  int count = countCharacters(s);
  if (count < 6) {
    cout << "The password is to short. It should be at least 6 characters" << endl;
    return false;
  }
  bool hasUppercase = false;
  bool hasLowercase = false;
  bool hasDigit = false;
  
  for (int i = 0; i<count; i++) {
    if (s[i] == '\0') {
      break;
    }
    if (isdigit(s[i])) {
      hasDigit = true;
    }
    if (islower(s[i])) {
      hasLowercase = true;
    }
    if (isupper(s[i])) {
      hasUppercase = true;
    }
  }
  if (hasUppercase && hasLowercase && hasDigit) {
    return true;
  }
  cout << "You need at least one uppercase, lowercase and digit" << endl;
  return false;
}