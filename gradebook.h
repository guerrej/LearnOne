#include <string>
using namespace std;

class Gradebook
{
public:
    Gradebook( string);
    void setcoursename(string );
    string getcoursename();
    void displaymessage();

private:
    string coursename;
};