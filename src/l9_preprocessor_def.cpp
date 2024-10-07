#include <iostream>
using namespace std;

/*
    Another mechanism to name constant values is to use preprocessor definitions. 
    Form: # define identifier replacement

    After this directive, any occurrence of identifier in the code is interpreted as replacement, 
    where replacement is any sequence of characters (until the end of the line). 
    This replacement is performed by the preprocessor, and happens before the program is compiled, 
    thus causing a sort of blind replacement: the validity of the types or syntax involved is not checked in any way.

*/ 

#define PI 3.14159
#define NEWLINE '\n'
#define SQUARE(x) ((x) * (x))
#define MAX_SIZE  100

int main(){

    double r=5.0;               // radius
    double circle;

    circle = 2 * PI * r;
    cout << circle;
    cout << NEWLINE;

    int x = 25;
    int square = SQUARE(x);
    cout << square;
    cout << NEWLINE;

   
    int numbers[MAX_SIZE];

    
    for (int i = 0; i < MAX_SIZE; i++) {
        numbers[i] = i * 2;  // Initialize the array elements
    }

    cout << numbers[0];
    cout << NEWLINE;
    cout << numbers[MAX_SIZE-1];
    cout << NEWLINE;

    cout << "BYE BYE";
    cout << NEWLINE;

    



}