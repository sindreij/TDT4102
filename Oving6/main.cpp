#include <iostream>
#include "pointers.h"
#include "cstrings.h"
#include "dynamicArrays.h"
#include "minesweeper.h"
#include "integerset.h"
#include "student.h"
using namespace std;

int main(int argc, char **argv) {
    cout << "-- Øving 6 --" << endl;
    cout << "-------------" << endl;
    testIntegerSet();
    
    bool done = false;
    while (!done)
    {
        int choice;

        cout << "1) Pointers" << endl;
        cout << "2) CStrings" << endl;
        cout << "3) Dynamic Arrays" << endl;
        cout << "4) Minesweeper" << endl;
        cout << "5) IntegerSet" << endl;
        cout << "6) Students and Courses" << endl;

        cout << "Pick 1-6, 0 to exit, then press enter: ";
        cin >> choice;

        // make sure system does not crash if given output other than 0 to 5
        cin.clear();
        cin.ignore(256, '\n');

        switch (choice)
        {
        case 1:
            cout << "\nDel 1, Pointers" << endl;
            cout << "-----" << endl;
            pointers();
            break;
        case 2:
            cout << "\nDel 2, CStrings" << endl;
            cout << "-----" << endl;
            cstrings();
            break;

        case 3:
            cout << "\nDel 3, Dynamic arrays" << endl;
            cout << "-----" << endl;
            dynamicArrays();;
            break;

        case 4:
            cout << "\nDel 4, Minesweeper" << endl;
            cout << "-----" << endl;
            Minesweeper m;
	    m.play();
            break;


        case 5:
            cout << "\nDel 5, Integer Set" << endl;
            cout << "-----" << endl;
            testIntegerSet();
            break;

        case 6:
            cout << "\nDel 6, Student and courses" << endl;
            cout << "-----" << endl;
            testStudent();
            break;
        case 0:
            done = true;
            break;
        }
    }
cout << "\n-----\n-- Ferdig --" << endl;
}
