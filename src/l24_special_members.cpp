#include <iostream>

using namespace std;

/*
    Special members
    ===============
     special memeber functions are member functions that are implicitly defined as member of classes under certain
     circumstances. There are six

            Member function	            typical form for class C: 
            -------------------------------------------------------
            Default constructor	        C::C();
            Destructor	                C::~C();
            Copy constructor	        C::C (const C&);
            Copy assignment	            C& operator= (const C&);
            Move constructor	        C::C (C&&);
            Move assignment	               C& operator= (C&&);
*/

// Default constructor is the constructor called when objects of a class are declared, but are not initialized with any arguments
// If a class definition has not constructors, the compiler assumes the class to have an implicitly defined default constructor
// Objects of classes with a default constructor can be constructed simply declaring them without any arguments

class Example{
    public:
        int total;
        void accumulate (int x) {total += x;}
};

// Once a class has some constructor taking any number of parameters explicitly declared, the compiler no longer provides an implicit
// default constructor, and no longer allows the declaration of new objects of that class without arguments. Example

class Example2{
    public:
    int total;
    Example2 (int initial_value) : total(initial_value){ };
    void accumulate (int x) { total += x;}
};

// Therefore, if objects of a class need to be constructed without arguments, the proper default constructor shall also be declared 
// in the class. Example

class Example3{
    string data;
    public:
        Example3 (const string& str) : data (str) {}                //explicit declared constructot
        Example3 () {}                                              // implicit default constructor
        const string& content() const {return data;}
};

// Destructors fulfill the opposite functionality of constructors. They are responsible for necessary cleanup needed by a class when 
// its lifetime ends. If a class allocates dynamic memory to store the string it had as a data member, it would be very useful to have 
// a function called automatically at the end of the object's life in vharge of releasing this memory - destructor. A destructor is a 
// member function similar to a default constructor, it takes no arguments and returns nothing, not even void. It also uses the class
// name as its own name, but preceeded with the tilde(~) sign

class Example4{
    string* ptr;
    public:
        // constructors
        Example4() : ptr (new string) {}
        Example4 (const string& str) : ptr(new string(str)) {}
        // destructor
        ~Example4 () {delete ptr;}
        // access content
        const string& content() const {return *ptr;}

};

// Copy constructor is a special constructor used to create a new object as a copy of an existing object. It defines how an object is 
// copied when 1. passing an object by value 2. returning an object from a function 3. initialiizing an object with another object of same class
// Syntax: for a class named MyClass, a typical copy constructor is MyClass(const MyClass& other);
// const MyClass& other: A reference to another object of the same class, usually const to prevent modification
// Default copy constructor: if you do not define a copy constructor, the compiler provides one automatically. this implicit copy constructor perorms shallow copy,
// copying all member variables as they are

// copy constructor: shallow copy
class MyClass{
    public:
        int a, b;
        string c;
};
// An implicit constructor is automatically defined. The definition assumed for this function perform shallow copy roughly equivalent to:
// MyClass:: MyClass(const MyClass& x) : a(x.a), b(x.b), c(x.c) {}

/*
This default copy constructor may suit the needs of many classes. But shallow copies only copy the members of the class themselves, and this is probably 
not what we expect for classes like class Example4 we defined above, because it contains pointers of which it handles its storage. For that class, performing 
a shallow copy means that the pointer value is copied, but not the content itself; This means that both objects (the copy and the original) would be sharing 
a single string object (they would both be pointing to the same object), and at some point (on destruction) both objects would try to delete the same block 
of memory, probably causing the program to crash on runtime. This can be solved by defining the following custom copy constructor that performs a deep copy:
*/

// copy constructor: deep copy
class Example5{
    string* ptr;
    public: 
        Example5 (const string& str) : ptr(new string (str)) {}                     // constructor
        ~Example5 () {delete ptr;}                                                  // destructor
        Example5 (const Example5& x) : ptr(new string(x.content())) {}              // copy constructor (deep copy)
        const string& content() const {return *ptr;}                                // accessor: access content
        
        // Copy Assignment Operator
        Example5& operator=(const Example5& other) {
            if (this != &other) {                                                   // Self-assignment check
                delete ptr;                                                         // Clean up existing resource
                ptr = new std::string(*other.ptr);                                  // Deep copy
            }
            return *this;
        }

};

/*
The deep copy performed by this copy constructor allocates storage for a new string, which is initialized to contain a copy of the original object. 
In this way, both objects (copy and original) have distinct copies of the content stored in different locations.
*/


// Copy assignment is an overload of operator= which takes a value or reference of the class itself as parameter. The return value is generally 
// a reference to *this(although this is not required). The copy assignment operator is a special function and is also defined implicitly if a 
// class has no custom copy or move assignment(nor move constructor) defined. implicit version does a shallow copy


// Objects are not only copied on construction, when they are initialized: They can also be copied on any assignment operation. See the difference:
                // MyClass foo;
                // MyClass bar (foo);       // object initialization: copy constructor called
                // MyClass baz = foo;       // object initialization: copy constructor called
                // foo = bar;               // object already initialized: copy assignment called 
// Note that baz is initialized on construction using an equal sign, but this is not an assignment operation! (although it may look like one): 
// The declaration of an object is not an assignment operation, it is just another of the syntaxes to call single-argument constructors.

// The assignment on foo is an assignment operation. No object is being declared here, but an operation is being performed on an existing object; foo.


// Move constructor and assignment allow tge resources owned by and rvalue object(typically a temporary object) to be moved into another object, rather than being copied
// Move constructor initializes a new object by taking ownership of the resource from a temporary(rvaluee) object   MyClass(MyClass&& other);
// Move assignment operator transfers ownership of resources from one object to another cleaning up any resources the destination object was holding
    // MyClass& operator=(MyClass&& other);
// Rvalue references, denoted by &&, are used to implement move semantics. They bind to rvalues (temporary objects), allowing the resources of these temporary objects to be reused or moved.

class Example6{
    string* ptr;
    public:
        Example6 ( const string& str) : ptr(new string(str)) {}
        ~Example6 () {delete ptr;}
        Example6 (Example6&& x) : ptr(x.ptr) { x.ptr = nullptr;}                        // move constructor
        Example6& operator= (Example6&& x){                                             // move assignment
            delete ptr;
            ptr = x.ptr;
            x.ptr = nullptr;
            return *this;
        }
        const string& content() const {return *ptr;}                                    // access content
        Example6 operator+(const Example6& rhs){
            return Example6(content() + rhs.content());
        }
};

/*
Compilers already optimize many cases that formally require a move-construction call in what is known as Return Value Optimization. Most notably, 
when the value returned by a function is used to initialize an object. In these cases, the move constructor may actually never get called.

Note that even though rvalue references can be used for the type of any function parameter, it is seldom useful for uses other than the move constructor. 
Rvalue references are tricky, and unnecessary uses may be the source of errors quite difficult to track.
*/

// Implict members: C++ provides implicit declarations for some special member functions if they are not explicitly declared:: all listed above
// However, when your class manages resources(like dynamic memory), relying on implicit definitions can lead to problems like shallow copies
// or double deletions

// You can explicitly specify default behavior or prevent certain functions from being generated using = default; and = delete;
// function_declaration = default;
// function_declaration = delete;

// default and delete implicit members
class Rectangle{
    int width, height;
    public:
        Rectangle (int x, int y) : width(x), height(y){}
        Rectangle() = default;
        Rectangle (const Rectangle& other) = delete;
        int area() {return width * height;}
};

int main(){

    Example ex;                 // valid: calls default constructor
    // Example2 ex;             // not valid: no default constructor
    Example2 ex2 (100);         // valid: calls declared constructor

    Example3 foo;
    Example3 bar( "Example");

    cout << "bar's content: " << bar.content() << "\n";

    /*
        On construction, Example4 allocates storage for a string. Storage that is later released by the destructor.

        The destructor for an object is called at the end of its lifetime; in the case of foo and bar this happens at the end of function main.
    
    */

    Example4 foofoo;
    Example4 barbar("Example");
    cout << "barbar's content: " << barbar.content() << "\n";


    Example5 foofoofoo ("Example");
    Example5 barbarbar = foofoofoo;

    cout << "barbarbar's content: " << barbarbar.content() << '\n';

    Example6 foofoofoofoo ("Exam");
    Example6 barbarbarbar = Example6("ple");   // move-construction
    foofoofoofoo = foofoofoofoo + barbarbarbar;                  // move-assignment
    cout << "foofoofoofoo's content: " << foofoofoofoo.content() << '\n';


    Rectangle foofoofoofoofoo;
    Rectangle barbarbarbarbar(10,20);

    cout << "barbarbarbarbar's area: " << barbarbarbarbar.area() << "\n";

    /*
    Here, Rectangle can be constructed either with two int arguments or be default-constructed (with no arguments). It cannot however be 
    opy-constructed from another Rectangle object, because this function has been deleted. Therefore, assuming the objects of the last example, 
    the following statement would not be valid:
                    Rectangle baz (foo);
    It could, however, be made explicitly valid by defining its copy constructor as:
                    Rectangle::Rectangle (const Rectangle& other) = default;
    Which would be essentially equivalent to:
                    Rectangle::Rectangle (const Rectangle& other) : width(other.width), height(other.height) {}


    Note that, the keyword default does not define a member function equal to the default constructor (i.e., where default constructor means 
    constructor with no parameters), but equal to the constructor that would be implicitly defined if not deleted.

    In general, and for future compatibility, classes that explicitly define one copy/move constructor or one copy/move assignment but not both, 
    are encouraged to specify either delete or default on the other special member functions they don't explicitly define.   
    */

    return 0;

}