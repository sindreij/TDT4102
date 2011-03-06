#include <string>

/**
 * To structer som definerer en musiker og ett
 * band
 */
struct Musican {
  std::string name;
  int weight;
  int height;
  int beardLenght;
};

struct Band {
  std::string name;
  bool rockBand;
  int releases;
  Musican musicans[4];
};

/**
 * Tester de overnevnte structene
 */
void testStruct();