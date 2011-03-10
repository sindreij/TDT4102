#include "integerset.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

void testIntegerSet() {
    cout << "hola" << endl;
    IntegerSet *s1 = new IntegerSet;
    IntegerSet *s2 = new IntegerSet;
    s1->insertElement(5);
    s1->insertElement(1);    
    s1->insertElement(30);
    s1->insertElement(8);
    s1->insertElement(9);
    s1->insertElement(1);
    
    s2->insertElement(4);
    s2->insertElement(1);
    s2->insertElement(7);
    s2->insertElement(9);
    s2->insertElement(30);
    
    IntegerSet *u = s1->unionOfSets(s2);
    IntegerSet *i = s1->intersectionOfSets(s2);
    
    
    cout << "Set 1: " << *s1 << endl;
    cout << "Set 2: " << *s2 << endl;
    cout << "Union: " << *u << endl;
    cout << "Inter: " << *i << endl;

    delete s1;
    delete s2;
    delete u;
    delete i;
    cout << "ferdig" << endl;
}

IntegerSet::IntegerSet(int initialSize) {
    elements_size = initialSize;
    size = 0;
    elements = 0;
    if (elements_size > 0) {
        elements = new int[elements_size];
    }
}

IntegerSet::~IntegerSet() {
    delete [] elements;
    elements = 0;
}

void IntegerSet::getMoreMemory(int newMemory) {
    int *old = elements;
    int old_size = elements_size;
    elements_size = elements_size + newMemory;
    elements = new int[elements_size];
    
    for (int i = 0; i < old_size; i++) {
        elements[i] = old[i];
    }
    
    delete [] old;
    old = 0;
    
}

void IntegerSet::insertElement(int inn) {
    
    if (size + 1 > elements_size) {
        getMoreMemory(ceil(size/2.0));
    }
    int min = 0;
    int max = size -1;
    int index;
    do {
        index = min + (max-min)/2;
        if (inn > elements[index]) {
            min = index + 1;
        } else {
            max = index - 1;
        }
    } while (elements[index] != inn && min <= max);
    if (size > 0 && elements[index] < inn) {
        index++;
    }
    if (index < size && elements[index] == inn) {
        //Elementet er her allerede. Stopp
        return;
    }
    //Vi skal putte inn et element
    for (int i = size-1; i>=index; i--) {
        elements[i+1] = elements[i];
    }
    size++;
    elements[index] = inn;
}

IntegerSet* IntegerSet::intersectionOfSets(IntegerSet* s2) {
    IntegerSet *s1 = this;
    int newElementsSize = s1->size + s2->size;
    int *newElements = new int[newElementsSize];
    
    
    int i1 = 0;
    int i2 = 0;
    int i = 0;
    int size = 0;
    while (i1<s1->size || i2<s2->size) {
        if (i1 == s1->size || ((i2 < s2->size) && s1->elements[i1] > s2->elements[i2])) {
            i2++;
        } else if (i2 == s2->size || s1->elements[i1] < s2->elements[i2]) {
            i1++;
        }else if (s1->elements[i1] == s2->elements[i2]) {
            newElements[i] = s1->elements[i1];
            size++;
            i++;
            i1++;
            i2++;
        } 
    }
    
    IntegerSet *newSet = new IntegerSet(0);
    
    newSet->size = size;
    newSet->elements = newElements;
    newSet->elements_size = newElementsSize;
    
    return newSet;
}

IntegerSet* IntegerSet::unionOfSets(IntegerSet *s2) {
    IntegerSet *s1 = this;
    int newElementsSize = s1->size + s2->size;
    int *newElements = new int[newElementsSize];
    
    
    int i1 = 0;
    int i2 = 0;
    int i = 0;
    int size = 0;
    while (i1<s1->size || i2<s2->size) {
        if (i1 == s1->size || ((i2 < s2->size) && s1->elements[i1] > s2->elements[i2])) {
            newElements[i] = s2->elements[i2];
            size++;
            i++;
            i2++;
        } else if (i2 == s2->size || s1->elements[i1] < s2->elements[i2]) {
            newElements[i] = s1->elements[i1];
            size++;
            i++;
            i1++;
        }else if (s1->elements[i1] == s2->elements[i2]) {
            newElements[i] = s1->elements[i1];
            size++;
            i++;
            i1++;
            i2++;
        } 
    }
    
    IntegerSet *newSet = new IntegerSet(0);
    
    newSet->size = size;
    newSet->elements = newElements;
    newSet->elements_size = newElementsSize;
    
    return newSet;
}

int IntegerSet::getElement(int i) {
    if (i >= 0 && i < size) {
        return elements[i];
    }
}


ostream& operator<<(ostream& out, IntegerSet& r1) {
    for (int i = 0; i<r1.getSize(); i++) {
        out << r1.getElement(i) << " ";
    }
    return out;
}
