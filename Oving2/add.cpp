int add(int a, int b) {
  return a + b;
}

double add(double a, double b) {
  return a + b;
}

void add(int& a, int& b, int& c, int& d) {
  b = a+b;
  c = b+c;
  d = c+d;
}
