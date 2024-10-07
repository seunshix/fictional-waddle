#include <iostream>
using namespace std;

int main(){
    /*
        Literals are the most obvious kinds of constants
        They are used to express particular values within the source code of a program.

        Literal constant can be classified into:
            - Integer
            - Floating-point
            - Characters
            - Strings
            - Boolean
            - Pointers
            - User-defined literals

        C++ allows use of decimal, octal(digits preceded by 0) and hexadecimal numbers(digits preceded by 0x)
    
    */

   // All these variable declaration represent the same number
   int a = 5;             // literal constant
   int b = 75;           // decimal
   int c = 0113;        // octal 
   int d = 0x4b;       // hexadecimal

   // Literal constants have a type, suffixes may be appended to integer literal to specify a different integer type

   int e = 75;      // int
   int f = 75u;     // unsigned int
   int g = 75l;     // long
   int h = 75ul;    // unsigned long
   int i = 75lu;    //unsigned long 


   /// Floating Point Numerals

   /*
        These are four valid numbers with decimals expressed in C++. 
        - The first number is PI, 
        - the second one is the number of Avogadro, 
        - the third is the electric charge of an electron (an extremely small number) -all of them approximated-, 
        - and the last one is the number three expressed as a floating-point numeric literal.
   */

  double j = 3.14159L;     // long double
  float k = 6.02e23f;     // float

  /*
        Any of the letters that can be part of a floating-point numerical constant (e, f, l) 
        can be written using either lower or uppercase letters with no difference in meaning.
  */
  
  /// Character and String Literals
  char l = 'z';                     // single quote to express a character
  string m = "How do you do?";      // double quote to express a string

  /*
    Single Character Escape codes
        \n	newline
        \r	carriage return
        \t	tab
        \v	vertical tab
        \b	backspace
        \f	form feed (page feed)
        \a	alert (beep)
        \'	single quote (')
        \"	double quote (")
        \?	question mark (?)
        \\	backslash (\)

    Internally, computers represent characters as numerical codes: most typically, they use one extension of the ASCII character encoding system. 
    Characters can also be represented in literals using its numerical code by writing a backslash character (\) followed by the code expressed 
    as an octal (base-8) or hexadecimal (base-16) number. For an octal value, the backslash is followed directly by the digits; while for hexadecimal, 
    an x character is inserted between the backslash and the hexadecimal digits themselves (for example: \x20 or \x4A).
  */


   /* Several string literals can be concatenated to form a single string literal simply by 
   separating them by one or more blank spaces, including tabs, newlines, and other valid blank characters. */
   string n = "this forms "  "a single"  " string "  "of characters";

   /// Other Literals

   bool foo = true;     
   bool bar = false;
   int *p = nullptr;


   
}