#include <iostream>
using namespace std;

int main () {
  char s = '\t'; //s står for space
  cout << "N" << s << "10*N" << s << "100*N" << s <<"1000*N" << endl;
  for (int i = 1; i<=5; i++) {
    cout << i << s << i*10 << s << 100*i << s << 1000*i << endl;
  }
}
