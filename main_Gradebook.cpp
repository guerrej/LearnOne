#include <iostream>
#include "gradebook.h"
using namespace std;




int main() {
    string nameofcourse;
    Gradebook mygradebook1( "Engineering for Professionals");
    Gradebook mygradebook2 ("Calculus for the Awesome");

    cout << "please enter the name of the course "<< endl;
    getline(cin, nameofcourse);
    cout << endl;

    mygradebook1.setcoursename(nameofcourse);

    mygradebook1.displaymessage();

    cout << "The two courses I am registered in are " << mygradebook1.getcoursename() << " and " << mygradebook2.getcoursename() << endl;
    return 0;
}