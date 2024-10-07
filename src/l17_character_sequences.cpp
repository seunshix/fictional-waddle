#include <iostream>

using namespace std;

int main(){

    /*
        Character Sequences
        ===================
        Strings are in fact sequences of characters and can be represented as plain array of elements of a character type

        Initialization of null-terminated character sequences
        =====================================================
        Because arrays of characters are ordinary arrays, they follow the same rules as these. For example, to initialize an array of characters 
        with some predetermined sequence of characters, we can do it just like any other array:

                char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };

        String Literals are another way of initializing string
        For example:
                char myword[] = "Hello";

        Strings and null-terminated character sequences
        ===============================================
        Plain arrays with null-terminated sequences of characters are the typical types used in the C language to represent strings 
        (that is why they are also known as C-strings). In C++, even though the standard library defines a specific type for strings (class string), 
        still, plain arrays with null-terminated sequences of characters (C-strings) are a natural way of representing strings in the language; 
        in fact, string literals still always produce null-terminated character sequences, and not string objects.

        In the standard library, both representations for strings (C-strings and library strings) coexist, and most functions requiring strings are overloaded to support both.

        In any case, null-terminated character sequences and strings are easily transformed from one another:

        Null-terminated character sequences can be transformed into strings implicitly, and strings can be transformed into null-terminated character sequences 
        by using either of string's member functions c_str or data:

                    char myntcs[] = "some text";
                    string mystring = myntcs;  // convert c-string to string
                    cout << mystring;          // printed as a library string
                    cout << mystring.c_str();  // printed as a c-string 


            (note: both c_str and data members of string are equivalent)
    */

   char foo[20];
}