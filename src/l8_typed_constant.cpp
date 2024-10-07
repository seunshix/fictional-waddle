#include <iostream>

using namespace std;

// Sometimes, it is just convenient to give a name to a constant value
const double pi = 3.1415926;
const char tab = '\t';
const char newline = '\n';


int main(){

    // We can now use these names instead of the literals they were defined to
    double r = 5.0;     // radius
    double circle;

    circle = 2 * pi * r;
    cout << circle;
    cout << newline;



}