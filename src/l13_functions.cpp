# include <iostream>
#include <cstdlib>
using namespace std;

void odd (int x);
void even (int x);
long factorial(long n);


/*


    Functions allow to structure programs in segments of code to perform individual tasks.

        In C++, a function is a group of statements that is given a name, and which can be called from some point of the program. 
        The most common syntax to define a function is:

            type name ( parameter1, parameter2, ...) { statements }

        Where:
            - type is the type of the value returned by the function.
            - name is the identifier by which the function can be called.
            - parameters (as many as needed): Each parameter consists of a type followed by an identifier, 
               with each parameter being separated from the next by a comma. Each parameter looks very much like a regular variable declaration 
               (for example: int x), and in fact acts within the function as a regular variable which is local to the function. 
               The purpose of parameters is to allow passing arguments to the function from the location where it is called from.
            - statements is the function's body. It is a block of statements surrounded by braces { } that specify what the function actually does.

        Function with no type. The use of 'void'

        type name ( argument1, argument2 ...) {statements}

        Requires the declaration to begin with a type. This is the type of the value returned by the function. 
        But what if the function does not need to return a value? In this case, the type to be used is void, which is a special type to represent the absence of value. 
        For example, a function that simply prints a message may not need to return any value:

        void can also be used in the function's parameter list to explicitly specify that the function takes no actual parameters when called. 
        For example, printmessage could have been declared as:


*/

/*
        
        The Return Value of main() in C++
        

            1. Return Type of main():
                - The return type of main() is int.
                - Many examples don't explicitly return a value from main().

            2. Implicit Return:
                - If main() ends without a return statement, the compiler adds an implicit:
                    return 0;
                - This only applies to main(), not to other functions.

            3. Return Values:
                - Returning 0 (implicitly or explicitly) indicates successful program execution.
                - Other return values may be used, but interpretation can vary between platforms.

            4. Standard Return Values:
                value         | description
                --------------|--------------------------------------------------
                0             | The program was successful
                EXIT_SUCCESS  | The program was successful (same as 0)
                EXIT_FAILURE  | The program failed

                Note: EXIT_SUCCESS and EXIT_FAILURE are defined in <cstdlib>

            5. Best Practice:
                - Some authors prefer to explicitly write 'return 0;' at the end of main()
                    for clarity and consistency.

*/

int addition (int a, int b)
{
    int r;
    r = a + b;
    return r;
}

int subtraction (int a, int b)
{
  int r;
  r=a-b;
  return r;
}

void printmessage ()
{
  cout << "I'm a void function!";
}

void duplicate(int& a, int& b, int& c) {
    a *= 2;
    b *= 2;
    c *= 2;
}
/*
Arguments Passed by Value and by Reference in C++
=================================================

1. Passing by Value:
   - Default method for passing arguments to functions.
   - A copy of the argument's value is passed to the function.
   - Changes to the parameter inside the function don't affect the original variable.

   Example:
   int x = 5, y = 3, z;
   z = addition(x, y);  // x and y are passed by value

2. Passing by Reference:
   - Allows a function to modify the original variable.
   - Uses the & symbol after the parameter type.
   - The parameter becomes an alias for the argument.
*/

/*
3. Efficiency Considerations:
   - Passing by value can be inefficient for large objects due to copying.
   - Passing by reference avoids copying and can be more efficient.

4. Const References:
   - Used when you want efficiency of reference but don't want to modify the argument.
   - Syntax: const Type& paramName

   Example:
*/

string concatenate(const string& a, const string& b) {
    return a + b;
}

/*
5. Inline Functions:
   - Suggests compiler to insert function code at the call site.
   - Can improve performance for small, frequently called functions.
   - Use 'inline' keyword before function declaration.

   Example:
*/

inline int square(int x) {
    return x * x;
}

/*
6. Default Arguments:
   - Allow function calls with fewer arguments than parameters.
   - Default values are specified in function declaration.

   Example:
*/

int divide(int a, int b = 2) {
    return a / b;
}

// Usage:
// divide(10);    // Uses default value for b, returns 5
// divide(10, 5); // Overrides default value, returns 2

/*
7. Function Prototypes:
   - Declare a function before its definition.
   - Allows calling the function before its full implementation.

   Syntax:
   returnType functionName(parameterTypes);
*/
int main(){
    int z;
    z = addition(5, 3);
    cout << "The result is " << z << endl;

    z = subtraction(7, 2);
    cout << "The result is " << z << endl;

    z = 25 + subtraction(8,3) * addition(9, 5);
    cout << "The result is " << z << endl;

    printmessage();

    int i;
    do {
        cout << "\nPlease, enter number (0 to exit): ";
        cin >> i;
        odd (i);
    } while (i!=0);

    int a = 1, b = 3, c = 7;
    duplicate(a, b, c);
    cout << "a=" << a << ", b=" << b << ", c=" << c << endl;  // Output: x=2, y=6, z=14


    long number = 9;
    cout << number << "! = " << factorial(number);

    
    return EXIT_SUCCESS;
    // return EXIT_FAILURE
    // return 0;
}


void odd (int x)
{
  if ((x%2)!=0) cout << "It is odd.\n";
  else even (x);
}

void even (int x)
{
  if ((x%2)==0) cout << "It is even.\n";
  else odd (x);
}

/*
8. Recursion:
   - A function that calls itself.
   - Useful for tasks like factorial calculation or tree traversal.

   Example:
*/

long factorial(long n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}
