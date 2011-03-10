#include "student.h"
#include <string>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

void Student::addCourse(Course* c) {
    courses.push_back(c);
    c->students.push_back(this);
}

string Student::getName() {
    return name;
}

void Course::addStudent(Student* s) {
    s->addCourse(this);
}

string Course::getName() {
    return name;
}

ostream& operator<<(ostream& ut, Course* course) {
    ut << course->getName() << ": ";
    for (int i = 0; i<course->students.size(); i++) {
        cout << course->students.at(i)->getName() ;
        if (i < course->students.size() - 1) {
            cout << ", ";
        }
        
    }
    return ut;
}

ostream& operator<<(ostream& ut, Student* student) {
    ut << student->getName() << ": ";
    for (int i = 0; i<student->courses.size(); i++) {
        cout << student->courses.at(i)->getName();
        if (i < student->courses.size() - 1) {
            cout << ", ";
        }
    }
    return ut;
}
    
void testStudent() {
    Student *s1 = new Student("Per Person");
    Student *s2 = new Student("Tor Jenssen");
    Student *s3 = new Student("Lene Marlin");
    Course *c1 = new Course("TDT4102");
    Course *c2 = new Course("TDT4100");
    c1->addStudent(s1);
    c1->addStudent(s2);
    c1->addStudent(s3);
    c2->addStudent(s1);
    c2->addStudent(s2);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << c1 << endl;
    cout << c2 << endl;
}
