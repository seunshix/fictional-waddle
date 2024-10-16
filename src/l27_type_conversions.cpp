#include <iostream>

using namespace std;
/*
    Implicit Conversions
    ====================
    Implicit conversions in C++ are automatic conversions performed by the compiler when you assign a value of one type to a vriable of another
    compatible ty[e. These conversions are generally safe and occur without any explicit instruction from the programmer.
    Standard Conversions

    Standard conversions affect fundamental data types and include:
        - Numeric Conversions: Converting between integer types, floating-point types, and between integers and floating-point numbers.
        - Promotion: Converting a smaller type to a larger type (e.g., short to int, float to double).
        - Conversions to bool: Any non-zero value becomes true, and zero becomes false.
        - Pointer Conversions:
           .  Null Pointer: Can be converted to any pointer type.
           .  Pointer Upcast: Converting a pointer to a derived class to a pointer to its base class.
    
    Important Points
    1. Loss of Precision: Converting from a larger type to a smaller type (e.g., int to short) may cause data loss.
    2. Signed and Unsigned: Converting between signed and unsigned types can produce unexpected results, especially with negative values.
    3. Floating-Point to Integer: When converting from float or double to an integer type, the decimal part is truncated.


    Implicit Conversions with Classes
    =================================
    In classes, implicit conversions can be controlled using:
        1. Single-Argument Constructors: Allow implicit conversion from a specific type to the class.
        2. Assignment Operator (operator=): Allows assignment from a specific type to the class.
        3. Type-Cast Operator (operator type): Allows the class to be implicitly converted to another type.

    The explicit keyword
    ====================
    The explicit keyword is used to prevent implicit conversions for constructors and type-cast operators that can be called with a 
    single argument. This helps avoid unintended conversions that could lead to bugs.

    By marking a constructor as explicit, you require that it be calledonly when the type conversion is explicit.

    Type Casting
    ============
    C++ is a strong-typed language and provides two main syntaxes for casting 
    1. C-like cast (type) expression
    2. Functional cast type(expression)

    These casts can be applied indiscriminately, which may lead to unsafe conversion, especially with pointers and class types.

    In order to control these types of conversions between classes, we have four specific casting operators: dynamic_cast, 
    reinterpret_cast, static_cast and const_cast. Their format is to follow the new type enclosed between angle-brackets (<>) 
    and immediately after, the expression to be converted between parentheses.
        dynamic_cast <new_type> (expression)
        reinterpret_cast <new_type> (expression)
        static_cast <new_type> (expression)
        const_cast <new_type> (expression)
    The traditional type-casting equivalents to these expressions would be:
        (new_type) expression
        new_type (expression)
    ++++++++++++++++++- but each one with its own special characteristics:

    dynamic_cast
    ============
    dynamic_cast can only be used with pointers and references to classes or with void*. Its purpose is to ensure that the result 
    of the type conversion points to a valid complete object of the destination pointer type.

    This naturally includes pointer upcast(converting from pointer-derived to pointer-to-base) in the same way as allowed in an
    implicit conversion. But dynamic_cast can also downcast(convert from pointer-to-base to pointer-to-derived) polymorphic classes
    (those with virtual members) if-and only if the pointed object is a valid complete object of the target type.
*/

class A{};

class B{
    public:
        // conversion from A (constructor)
        explicit B (const A& x){
            cout << "B constructed from A" << endl;
        }

        // conversion from A (assignment)
        B& operator=(const A& x){
            cout << "B assigned from A" << endl;
            return *this;
        };

        // conversion to A (type-cast operator)
        operator A(){
            cout << "B converted to A" << endl;
            return A();
        }

        /*
        The type-cast operator uses a particular syntax: it uses the operator keyword followed by the destination type and an empty set 
        of parentheses. Notice that the return type is the destination type and thus is not specified before the operator keyword.
        */

};
void fn (B x) {}

// Unsafe Casting Example

class Dummy{
    double i, j;
};

class Addition{
    int x, y;
    public:
        Addition(int a, int b): x(a), y(b) {}
        int result(){return x +y;}
};

int main(){
    short a = 2000;
    int b;
    b = a;                      // Implicit conversion from short to int


    A foo;
    B bar(foo);
    // B bar = foo;  // Calls constructor(implicit)            // Invalid now because of explicit keyword added to constructor
    bar = foo;    // Calls assignment operator
    fn(bar);                                                    // Explict: OK
    // fn(foo);                                                    // Error: Cannot implicitly convert A to B
    foo = bar;    // Calls type-cast operator

    // Type casting examples

    double x = 10.3;
    int y;

    y = int(x);             // Functional casting
    y = (int)x;             // C-like casting

    // Unsafe Casting Example
    Dummy d;
    Addition* padd;
    padd = (Addition*) &d;
    cout << padd->result();
    cout <<endl;
    // This block of code declares a pointer to Addition (padd), but then assigns to it a reference to an object of another unrelated type
    // using explicit type casting: line 115
    // Unrestricted explicit type-casting allows to convert any pointer into any other pointer type, independently of the types they point to. 
    // The subsequent call to member result will produce either a run-time error or some other unexpected results.
    return 0;

}