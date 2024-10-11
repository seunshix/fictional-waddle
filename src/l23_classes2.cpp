#include <iostream>

using namespace std;
/*
    Overloading Operators
    =====================
    1. Operator overloading allows you to define custom behavior for operators when used with objects of user-defined classes.
    2. It's implemented by defining special operator functions, either as member functions or non-member functions.
    3. The syntax for an operator overload function is:
            return_type operator symbol(parameters)
    4. Most operators can be overloaded, with some exceptions like ::, ., ?:, etc.
    5. Overloaded operators should generally maintain the expected behavior of that operator. For example, + should typically perform some kind of addition.
    6. Binary operators overloaded as member functions take one parameter (the right-hand operand), while as non-member functions they take two parameters.
    7. Unary operators take no parameters when overloaded as member functions, or one parameter as non-member functions.
    8. The assignment operator (=) and subscript operator ([]) must be overloaded as member functions.
    9. Some operators like ++, -- have both prefix and postfix versions that can be overloaded.
    10. Overloading allows objects of custom classes to be used with operators in intuitive ways, similar to built-in types.
    11. It's important to consider const-correctness when overloading operators.
    12. Operator overloading can improve code readability when used appropriately, but can also be confusing if misused.
    '

            Operator Overloading Quick Reference

            +-------------------+------------------------+---------------------------+
            | Expression        | Member Function        | Non-member Function       |
            +-------------------+------------------------+---------------------------+
            | @a (prefix)       | A::operator@()         | operator@(A)              |
            | a@ (postfix)      | A::operator@(int)      | operator@(A,int)          |
            | a@b (binary)      | A::operator@(B)        | operator@(A,B)            |
            | a@b (assignment)  | A::operator@(B)        | -                         |
            | a[b]              | A::operator[](B)       | -                         |
            | a(b,c,...)        | A::operator()(B,C,...) | -                         |
            | a->b              | A::operator->()        | -                         |
            | (TYPE) a          | A::operator TYPE()     | -                         |
            +-------------------+------------------------+---------------------------+

            @ represents the operator being overloaded
            A, B, C are class types
            TYPE is any type (for type conversion operators)

            Note: 
            - Assignment (=) and subscript ([]) operators must be member functions
            - Most binary operators can be either member or non-member functions
            - Unary operators are typically overloaded as member functions

        this Operator
        =============
        The 'this' pointer is a special pointer that points to the current object instance of a class. It is an implicit parameter to all non-static member functions

        Key Points About this:
            1. It's only available within non-static member functions.
            2. It's a const pointer (you can't change what it points to).
            3. Its type is ClassName* const for non-const member functions, and const ClassName* const for const member functions.

        Static member functions
        =======================
      
        Static data members, also known as class variables, are shared among all objects of a class.
        Characteristics:
        ---------------
            1. Only one copy exists for the entire class, regardless of how many objects are created.
            2. Must be defined outside the class declaration.
            3. Can be accessed using the class name, without creating an object.

        Static member functions are associated with the class itself, not with any specific object.
        Characteristics:

            1. Can be called using the class name, without creating an object.
            2. Cannot access non-static members directly.
            3. Do not have a this pointer.


        Const member functions
        ======================
        In C++, you can qualify a class object as const, which means that you cannot modify its data members 
        after it's been created. To interact with such objects, you need to use const member functions. These 
        are functions that guarantee not to modify the object's state.

        To declare a member function as const, you add the const keyword after the function's parameter list:
            ReturnType FunctionName(ParameterList) const;
        
        Inside a const member function, you cannot modify non-static data members or call other non-const member functions.

        You can have two versions of a member function: one const and one non-const. This is called const overloading.

        Functions often take class objects by const reference to avoid unnecessary copying and to ensure the function doesn't modify the object.


        Key Points to Remember

            1. Const Objects: Can only call const member functions.
            2. Non-Const Objects: Can call both const and non-const member functions.
            3. onst Member Functions: Cannot modify the object's state.
            4. Overloading on Constness: Allows different behavior based on whether the object is const.

        Analogy

            1. Immutable vs. Mutable Objects: Think of const objects as read-only copies of a book—you can read but not write notes in them. 
               Non-const objects are like notebooks—you can both read and write in them.
            C2. onst Member Functions: Are like librarians who only provide information without altering any books.

        Why Is This Important?

            Safety: Helps prevent accidental modification of objects that should remain unchanged.
            Efficiency: Allows functions to accept objects by reference without copying, while still ensuring they don't modify them.
            Interface Contracts: Communicates to users of your class which functions are safe to call on const objects.


        Class Templates
        ===============
        Using templates, classes can have members that use template parameters as types
        Confused by so many T's? There are three T's in this declaration: The first one is the template parameter. 
        The second T refers to the type returned by the function. And the third T (the one between angle brackets) is also a requirement: 
        It specifies that this function's template parameter is also the class template parameter.

        Template Specialization
        =======================
        It is possible to define a different specialization for a template when a specific tyoe is passed as template argument. This is known as
        template specialization.

        Syntax for template specialization      template <> class mycontainer <char> { ... };

*/

class CVector{
    public:
        int x, y;
        CVector () {};
        CVector (int a, int b) : x(a), y(b) {}
        CVector operator + (const CVector&);
};

// Member Overloading
CVector CVector :: operator+ (const CVector& param){
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
}

// Non-Member Overloading
CVector operator- (const CVector& lhs, const CVector& rhs) {
  CVector temp;
  temp.x = lhs.x - rhs.x;
  temp.y = lhs.y - rhs.y;
  return temp;
}

// CVector& CVector::operator= (const CVector& param)
// {
//   x=param.x;
//   y=param.y;
//   return *this;
// }


// this operator

class Dummy {
    public: 
        bool isitme (Dummy &param);
        static int n;
        Dummy () {n++;} // Constructor increments n when a new object is created
};

int Dummy::n = 0;       // Initialize the static member outside the class

bool Dummy::isitme (Dummy &param){
    if (&param == this) return true;
    else return false;
}

// Static member function example

class Counter{
  public:
    static int count;
    Counter() { count++;}  
};

int Counter::count = 0;         // Definition outside the class

// Const member function example
class MyClass{
    int x;
    public:
        MyClass (int val) : x(val) {}
        int getX() const {return x;}                // Const member function 
        // int& getX() {return x;}                  // member function returning a const&
        // const int& getX() const {return x;}        // const member function returning a const&
};

// void setX(int val) const { 
//     x = val; // Error: Cannot modify member variable in a const function
// }

// Const in Function Parameters
void printValue(const MyClass& obj){
    cout << obj.getX() << endl;
}

// Class Template
template <class T>
class mypair {
    T a, b;
    public:
        mypair (T first, T second){
            a = first;
            b = second;
        }
        T getmax();
};

// member function of class template declared above
template <class T>
T mypair<T>::getmax(){
    T retval;
    retval = a>b? a:b;
    return retval;
}


// template specialization
template <class T>
class mycontainer{
    T element;
    public:
        mycontainer (T arg) {element= arg;}
        T increase () {return ++element;}
};

//class template specialization
template <>
class mycontainer <char> {
    char element;
    public:
        mycontainer (char arg) {element = arg;}
        char uppercase(){
            if((element>='a') && (element<='z')){
                element += 'A'- 'a';
                return element;
            }
        }
};

int main (){
    CVector foo (3, 1);
    CVector bar (1, 2);
    CVector result; 
    result = foo + bar;
    cout << result.x << "," << result.y << "\n";
    result = foo - bar;
    cout << result.x << "," << result.y << "\n";

    Dummy a;
    Dummy* b = &a;

    if (b ->isitme(a)){
        cout << "yes, &a is b\n";
    }

    Dummy c;                            // Create one object
    Dummy d[5];                         // Create an array of 5 objects
    cout << c.n << "\n" ;               // Output the current value of n
    Dummy* e = new Dummy;               // Dynamically create another object
    cout << Dummy::n << "\n";           // Output the current value of n
    delete e;                           // Clean up the dynamically allocated object

    Counter c1, c2, c3;
    cout << Counter::count << "\n";


    const MyClass obj(10);  // Const object
    const MyClass constObj(20);
    // // obj.x = 20;          // Error: Cannot modify a const object
    // cout << "Value of x: " << obj.getX() << endl;   // OK

    // cout << obj.getX() << endl;             
    // cout << constObj.getX() << endl;


    // Class Templates
    mypair<int> myobject(115, 36);
    mypair<double> myfloats(3.9, 2.18);

    cout << myobject.getmax() << endl;

    // template specialization
    mycontainer<int> myint(7);
    mycontainer<char> mychar('j');

    cout << myint.increase() << endl;
    cout << mychar.uppercase() << endl;

    return 0;
}