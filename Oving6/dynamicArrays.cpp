#include "dynamicArrays.h"
#include <iostream>
using namespace std;

int* createNewTable(int *table, int *input, int size, int incr_size);
void printTable(int *table, int size);

void dynamicArrays() {
    int incr_size = 5;
    int size = 0;
    int *table = new int[size];
    int *input = new int[incr_size];
    char c = 'y';
    while (toupper(c) == 'Y') {
        cout << "Write a sequence of " << incr_size << " integer values: ";
        for (int i = 0; i < incr_size; i++) {
            cin >> input[i];
        }
        table = createNewTable(table, input, size, incr_size);
        size += incr_size;
        printTable(table, size);
        cout << "Continue (y/n): ";
        cin >> c;
    }
    delete [] table;
    delete [] input;
}

int* createNewTable(int *oldTable, int *input, int size, int incr_size) {
  int *table = new int[size+incr_size];
  for (int i = 0; i<size; i++) {
    table[i] = oldTable[i];
  }
  for (int i = size; i<incr_size+size; i++) {
    table[i] = input[i-size];
  }
  delete [] oldTable;
  oldTable = 0;
  return table;
}

void printTable(int *table, int size) {
  cout << "Table now contains " << size << " elements: ";
  for (int i = 0; i<size; i++) {
    cout << table[i] << " ";
  }
  cout << endl;
}