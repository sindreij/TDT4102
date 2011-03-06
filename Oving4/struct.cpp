#include <iostream>
#include <cassert>

#include "struct.h"

using namespace std;

/** 
 * totalBeardLength returnerer -1 hvis bandet ikke er et rokkeband
 * hvis ikke retunerer den summen av skjegglengden til alle
 * i bandet
 */
int totalBeardLength(Band bandet) {
  if (!bandet.rockBand) {
    return -1;
  }
  int sum = 0;
  for (int i=0; i<4; i++) {
    sum += bandet.musicans[i].beardLenght;
  }
  return sum;
}

void testStruct() {
  //Først setup
  Band band1;
  Band band2;
  
  Musican member1;
  Musican member2;
  Musican member3;
  Musican member4;
  
  member1.beardLenght = 10;
  member2.beardLenght = 20;
  member3.beardLenght = 0;
  member4.beardLenght = 8;
  
  band1.musicans[0] = member1;
  band1.musicans[1] = member2;
  band1.musicans[2] = member3;
  band1.musicans[3] = member4;
  
  band2.musicans[0] = member1;
  band2.musicans[1] = member2;
  band2.musicans[2] = member3;
  band2.musicans[3] = member4;
  
  band1.rockBand = true;
  band2.rockBand = false;
  
  cout << "Sjekker band: ";
  assert(totalBeardLength(band2) == -1);
  assert(totalBeardLength(band1) == 38);
  cout << "OK" << endl;
}