//
// Created by Jose on 1/1/2018.
//
#include <iostream>
#include "gradebook.h"
using namespace std;

Gradebook::Gradebook( string name)
{
setcoursename (name);
}// end constructor

void Gradebook::setcoursename(string name) {
    if (name.length() <= 25)
        coursename = name;
    if (name.length()> 25){
        coursename  = name.substr(0,25);
        cout << "Name \"" << name << "\" exceeds maximum length (25).\n" << endl;
    }
}

string Gradebook::getcoursename() {
    return coursename;
}

void Gradebook::displaymessage() {
    cout << "Welcome to the grade book for \n "<< getcoursename() << "!" << endl;
}
