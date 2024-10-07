#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    /*

        Basic Input/Output in C++
        =========================
            Stream Objects
            --------------
            Stream     | Description
            -----------|---------------------------
            cin        | Standard input stream
            cout       | Standard output stream
            cerr       | Standard error output stream
            clog       | Standard logging output stream
    */

   int age = 40;

   // Standard Output (cout)
   cout << "This is an output sentence";                            // basic output
   cout << "\n";
   cout << 35; 
   cout << "\n";                                                     
   cout << "This " << "is a " << "single C++ " << "statement.";     // chaining output
   cout << "\n";
   cout << "I am " << age << " years old";                          // mixing literals and variables
   cout << "\n";
   cout << "First line. \nSecond Line" ;                           // adding line breaks
   cout << "\n";
   cout << "Third line." << endl;

   // Standard Input (cin)

   int height;
   cout << "What is your height? : ";
   cin >> height;
   cout << "Your height is " << height << endl;
   
//    int a, b, price, quantity;
//    cin >> a >> b;                                               // chaining inputs

//    string mystring;                                             // Single word
//    cin >> mystring;                                             // String input

   string mystr;                                                // Full line
   getline(cin, mystr);                                         // String input

   int price, quantity;
   cout << "Enter price: ";
   getline (cin,mystr);
   stringstream(mystr) >> price;
   cout << "Enter quantity: ";
   getline (cin,mystr);
   stringstream(mystr) >> quantity;
   cout << "Total price: " << price*quantity << endl;
   
   
   return 0;

}