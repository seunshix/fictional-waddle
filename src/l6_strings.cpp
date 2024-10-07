#include <iostream>

using namespace std;

int main() {
    // Introduction to strings

	// The string class is a compound type
    string mystring;
    mystring = "This is a string";
    cout << mystring  << endl;

    // All initialization formats are valid with strings
    string mystring1 = "This is a string";
    string mystring2 ("This is a string");
    // string mystring3 {"This is a string"};

    // Strings can also perform all the basic other operations that fundamental data types can
    mystring = "This is the initial string content";
    cout << mystring << endl;
    mystring = "This is a different string content";
    cout << mystring << endl;

    return 0;


}