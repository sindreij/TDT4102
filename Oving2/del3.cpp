#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

void init () {
  srand(time(0));
}

int randomTenToFifty() {
  return (rand() % 41) + 10;
}

double checkTrigonometry(int x) {
  return abs(tan(x)-sin(x)/cos(x));
}

char changeCase(char old) {
  if (isupper(old)) {
    return tolower (old);
  } else if (islower(old)) {
    return toupper(old);
  } else {
    return old;
  }
}

int main() {
  cout << "Initialization...." << endl;
  init();
  cout << endl << "Testing randomTenToFifty:" << endl;
  for (int i = 0; i<10; i++) {
    cout << randomTenToFifty() << endl;
  }
  cout << endl;
  cout << "Tester om tan(x) = sin(x)/cos(x) for noen tall:" << endl;
  int array[5];
  array[0] = 0.12;
  array[1] = 3.14;
  array[2] = 1.8;
  
  for (int i = 0; i<3;i++) {
    cout << array[i] << ": " << checkTrigonometry(array[i]) << endl;
  }
  cout << endl << "Testing changeCase" << endl;
  string str = "tO uPPER";
  
  cout << "Before: " << str << endl;
  for (int i = 0; i<str.length(); i++) {
    str[i] = changeCase(str[i]);
  }
  cout << "After: " << str << endl << endl;

  cout << "Finito" << endl << endl;
  
}
