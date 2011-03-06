#include <iostream>
using namespace std;

int main() {
  double belop;
  double rente;
  cout << "Hva er lånebeløpet: ";
  cin >> belop;
  cout << "Skriv renten i prosent: ";
  cin >> rente;

  double avdrag = belop/10;

  cout << "Innbetaling\tGjenstående lån" << endl;
  cout << "-----------\t---------------" << endl;

  for (int i=0; i<10;i++) {
    double innbetaling = avdrag + (rente/100) * belop;
    belop -= avdrag;
      cout << innbetaling << "\t\t" << belop << endl;
  }
}

