#include <iostream>
using namespace std;

void printTime(int hour, int minute, int second) {
  cout << hour << " hours, "
    << minute << " minutes and "
    << second << " seconds." << endl;
}

void getTime(int second) {
  int hour = second/(60*60);
  int minute = (second%(60*60))/60;
  second = second%(60*60)%60;

  printTime(hour, minute, second);
}

int main() {
  getTime(10000);
}
