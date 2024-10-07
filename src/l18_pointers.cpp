#include <iostream>

using namespace std;
// using namespace first;

void increment_all (int* start, int* stop){
    int* current = start;
    while(current != stop){
        ++ (*current); // increment value pointer
        ++current;      // increment pointer
    }
}

void print_all (const int* start, const int* stop){
    const int* current = start;
    while(current != stop){
        cout << *current << "\n";
        ++current;
    }
    /*
        Note that print_all uses pointers that point to constant elements. These pointers point to constant content they cannot modify, 
        but they are not constant themselves: i.e., the pointers can still be incremented or assigned different addresses, although 
        they cannot modify the content they point to.
    */

}


void increase (void* data, int psize){
    if (psize == sizeof(char)){
        char * pchar;
        pchar = (char*) data;
        ++(*pchar);
    }
    else if (psize == sizeof(int)){
        int* pint;
        pint = (int*) data;
        ++(*pint);
    }
}

int addition(int a , int b){
    return (a + b);
}

int subtraction (int a , int b){
    return (a - b);
}

int operation (int x, int y, int (*functocall)(int, int)){
    int g;
    g = (*functocall)(x, y);
    return (g);
}

int main(){
    /*
        Pointers
        ========

        For a C++ program, the memory of a computer is like a succession of memory cells, each one byte in size, and each with a unique address. 
        These single-byte memory cells are ordered in a way that allows data representations larger than one byte to occupy memory cells that have consecutive addresses.

        This way, each cell can be easily located in the memory by means of its unique address. For example, the memory cell with the address 1776 always follows 
        immediately after the cell with address 1775 and precedes the one with 1777, and is exactly one thousand cells after 776 and exactly one thousand cells before 2776.


        When a variable is declared, the memory needed to store its value is assigned a specific location in memory (its memory address). Generally, C++ programs do not 
        actively decide the exact memory addresses where its variables are stored. Fortunately, that task is left to the environment where the program is run - generally, 
        an operating system that decides the particular memory locations on runtime. However, it may be useful for a program to be able to obtain the address of a variable 
        during runtime in order to access data cells that are at a certain position relative to it.

        Address-of operator (&)
        =======================
        The address of a variable can be obtained by preceding the name of a variable with the ampersand sign (&)
            foo = &myvar;
        This would assign the address of variable myvar to foo; by preceding the name of the variable myvar with the 
        address-of operator (&), we are no longer assigning the content of the variable itself to foo, but its address.

        Deference Operator(*)
        =====================
        Pointers are said to "point to" the variable whose address they store. An interesting property of pointer is that they can be used to access 
        the variable they point to directly. This is done by preceding the pointer name with the deference operator (*). This operator can be read as "value pointed to by".

        The reference and dereference operators are complementary:
            & is the address-of operator and can simply be read as "address of"
            * is the dereference operator, and can be read as "value pointed to by"
        They sort of have opposite meanings

        Declaring Pointers
        ==================
        Due to the ability of a pointer to directly refer to the value that it points to, a pointer has different properties when it points to a char 
        than when it points to an int or a float. Once dereferenced, the type needs to be known. And fotr that, the declaration of a pointer needs to include the 
        data type the pointer is going to point ti.

            type * name
                int * number
                char * character
                double * decimal

        Note that the asterisk (*) used when declaring a pointer only means that it is a pointer (it is part of its type compound specifier), 
        and should not be confused with the dereference operator seen a bit earlier, but which is also written with an asterisk (*). 
        They are simply two different things represented with the same sign.

        Pointers and Arrays
        ===================
        The concept of arrays is related to that of pointers. In fact, arrays work very much like pointers to their first elemenst, and actually,
        an array can always be implicitly converted to the pointer of proper type.
        Pointers and arrays support the same set of operations, with the same meaning for both. The main difference being that pointers can be assigned new addresses,
        while arrays cannot.
        In the chapter about arrays, brackets ([]) were explained as specifying the index of an element of the array. Well, in fact these brackets are a dereferencing 
        operator known as offset operator. They dereference the variable they follow just as * does, but they also add the number between brackets to the address being 
        dereferenced. For example:
            a[5] = 0;       // a [offset of 5] = 0
            *(a+5) = 0;     // pointed to by (a+5) = 0  


        These two expressions are equivalent and valid, not only if a is a pointer, but also if a is an array. Remember that if an array, its name can be used just like a 
        pointer to its first element.

        Pointer Arithmetics
        ===================
        To conduct arithmetical operations on pointers is a little different than to conduct them on regular integer types. To begin with, only addition and subtraction 
        operations are allowed; the others make no sense in the world of pointers. But both addition and subtraction have a slightly different behavior with pointers, 
        according to the size of the data type to which they point.

        Pointers and const
        ==================

        Pointers can be used to access a variable by its address, and this access may include modifying the value pointed. But it ia slao possible to declare pointers
        that can access the pointed value to read it, but not to modify it. For this, it is enjoying with qualifying the type pointed to by the pointer as const. 
        A pointer to non-const can be implicitly converted to a pointer to const. But not the other way around!

        One of the use cases of pointers to const elements is as function parameters: a function that takes a pointer to non-const as parameter can modify the value 
        passed as argument, while a function that takes a pointer to const as parameter cannot.

        Pointers and String Literals
        ============================
        String literals are arrays containing null-terminated character sequences. String literals can be accessed directly. String literals are arrays of the proper 
        array type to contain all its characters plus the terminating null-character, with each of the elements being of type const char (as literals, they can never be modified).

        Pointers to Pointers
        ====================
        C++ allows the use of pointers that point to pointers, that these, in its turn, point to data (or even to other pointers). The syntax simply requires an asterisk (*) 
        for each level of indirection in the declaration of the pointer:

        void Pointers
        =============
        void pointers are pointers that point to a value that has no type ( thus an undetermined length and undetermined dereferencing properties).
        This gives void pointers a great flexibility, by being able to point to any data type, from an integer value or a float to a string of characters. 
        In exchange, they have a great limitation: the data pointed to by them cannot be directly dereferenced (which is logical, since we have no type to dereference to), 
        and for that reason, any address in a void pointer needs to be transformed into some other pointer type that points to a concrete data type before being dereferenced.

        Invalid pointers and null pointers
        ==================================
        In principle, pointers are meant to point to valid addresses, such as the address of a variable or the address of an element in an array. But pointers can actually 
        point to any address, including addresses that do not refer to any valid element. Typical examples of this are uninitialized pointers and pointers to nonexistent 
        elements of an array:
        But, sometimes, a pointer really needs to explicitly point to nowhere, and not just an invalid address. For such cases, there exists a special value that any pointer 
        type can take: the null pointer value. This value can be expressed in C++ in two ways: either with an integer value of zero, or with the nullptr keyword:

        Pointers to functions
        =====================
        C++ allows operations with pointers to functions. The typical use of this is for passing a function as an argument to another function. Pointers to functions are 
        declared with the same syntax as a regular function declaration, except that the name of the function is enclosed between parentheses () and an asterisk (*) is inserted before the name:

            
    */

   int myvar, bar, baz;
   int * foo;    // pointer
   myvar = 25;
   foo = &myvar;
   bar = myvar;
   baz = *foo;

   
   cout << endl;
   cout << "Assigned address of myvar: " << foo << endl;
   cout << "Actual value of myvar: " << bar << endl;
   cout << "Value pointed to by foo: " << baz << endl;
   cout << endl;
   cout << "Let's test some statements." << endl;
   cout << (myvar == 25) << endl;
   cout << (&myvar == foo) << endl;
   cout << (*foo == myvar) << endl;
   cout << endl;


   int firstvalue, secondvalue;
   int * mypointer;

   mypointer = &firstvalue;
   *mypointer = 10;
   mypointer = &secondvalue;
   *mypointer = 20;

   cout << "firstvalue is " << firstvalue << endl;
   cout << "secondvalue is " << secondvalue << endl;

   /*
        Notice that even though neither firstvalue nor secondvalue are directly set any value in the program, both end up with a value set indirectly through t
        he use of mypointer. This is how it happens:
            First, mypointer is assigned the address of firstvalue using the address-of operator (&). Then, the value pointed to by mypointer is assigned a value 
            of 10. Because, at this moment, mypointer is pointing to the memory location of firstvalue, this in fact modifies the value of firstvalue.
            In order to demonstrate that a pointer may point to different variables during its lifetime in a program, the example repeats the process with secondvalue 
            and that same pointer, mypointer.
   */

  int thirdvalue = 5, fourthvalue = 15;
  int * p1, * p2;

  p1 = &thirdvalue;     // p1 = address of thirdvalue
  p2 = &fourthvalue;    // p2 = address of fourthvalue

  *p1 = 10;      // value pointed to by p1 = 10
  *p2 = *p1;    // value pointed to by p2 = value pointed to by p1
  p1 = p2;      // p1 = p2 (value of pointer is copied)
  *p1 = 20;     // value pointed to by p1 = 20

   cout << "thirdvalue is " << thirdvalue << endl;
   cout << "fourthvalue is " << fourthvalue << endl;
   cout << endl;

   // Pointers and Arrays

   int numbers[5];
   int * p; 
   p = numbers; *p = 10;
   p++; *p = 20;
   p = &numbers[2]; *p = 30;
   p = numbers + 3; *p = 40;
   p = numbers; *(p + 4) = 50;

   for (int i = 0; i < 5; i++){
    cout << numbers[i] << ", ";
   }

   cout << endl;
   cout << endl;

   // pointers can be initialized to point to specific locations at the very moment they are defined
   int var;
   int * myptr = &var;

   // Pointer Arithmetics
   char a = 'a'; short b = 'b'; long c = 'c';
   char * mychar = &a; short * myshort = &b; long * mylong = &c;

   cout << mychar << "  Increment:  " << (++mychar) << endl;
   cout << myshort << "  Increment:  " << (++myshort) << endl;
   cout << mylong << "  Increment:  " << (++mylong) << endl;
   cout << endl;

   int i, j = 10;
   const int * point = &j;
   i = *p;                  // ok: reading p
   *p = i;                  // error: modifying p, which const-qualified

   // int numbers1[] = {10, 20, 30};
   increment_all(numbers, numbers + 5);
   print_all(numbers, numbers+5);
   cout << endl;

   // Pointers themselves can also be const, and this is specified by appending const to the pointed type ( after the asterisk)

   int x, y;

   // Non-const pointer to non-const int
   int *p3 = &x; // this is a regular pointer, you can change what p3 points to and modify value of 'x' through 'p3'
   p3 = &y; // Valid
   *p3 = 10; // Valid

   // Non-const pointer to const int
   const int *p4 = &x; // here, p4 is a pointer to a const int, you can change what p4 points to but cannot modify value it points to through p4
   p4 = &y; // valid
  // *p4 = 20; // Invalid - compiler error

  // Const pointer to non-const int
  int * const p5 = &x; // p5 is a const pointer to an int, you cannot change what p3 points to, but can modify value it points to
  // p5 = &y; // Invalid - compiler error
  *p5 = 20; // Valid

  // Const pointer to const int
  const int * const p6 = &x; // most restrictive. you cannot change what p6 points to or modify the value it points through p6
  // p6 = &y; // Invalid - compiler error
  // *p6 = 20; // Invalid - compiler error

  /*
    Remember, const to the left of * makes the pointed-to value constant, while const to the right of * makes the pointer itself constant. 
    This combination allows for different levels of immutability, providing flexibility in how pointers and their values can be used and modified in your code.
    The const qualifier can either precede or follow the pointed type, with the same exact meaning

            const int * p2a = &x;  //      non-const pointer to const int
            int const * p2b = &x;  // also non-const pointer to const int 


  */

 // Pointers to String Literals

 const char * hello = "hello";
 cout << (*(hello)) << endl;
 cout << (*(hello + 4)) << endl;
 cout << hello << endl;
 cout << endl;

 // Pointers to Pointers
 char d; char * e; char ** f;
 d = 'z'; e = &d; f = &e;
 cout << "d is " << d << endl;
 cout << "e is pointed to d in address " << e << endl;
 cout << "f is a pointer to pointer e in address " << f << endl;
 cout << endl;

 // void Pointer (void increase function)
 char g = 'x';
 int h = 1602;
 increase (&g, sizeof(g));
 increase (&h, sizeof(h));

 cout << g << ", " << h << endl;
 cout << endl;

 // invalid pointer and null pointers

 int * uninitialized_p;     // uninitialized pointer (local variable)
 int myarray[10];
 int * q = myarray + 20; // element out of bounds

 int * null_p = 0;    // Null pointer using 0
 int * null_q = nullptr; // Null pointer using keyword

 // Pointers to Functions
 int m, n;
 int (*minus)(int, int) = subtraction;

 m = operation(7, 5, addition);
 n = operation( 20, m, minus);

cout << m << endl;
cout << n << endl;

return 0;




}
