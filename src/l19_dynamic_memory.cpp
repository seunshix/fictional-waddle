#include <iostream>

using namespace std;

/*
    Dynamic Memory
    ==============
    All memory needs are determined before program execution by defining the variables needed, but there may be cases where the memory needs of a program can only be determined 
    during runtime. For example, when the memory needed depends on user input. On these cases, programs need to dynamically allocate memory, for which the C++ language integrates 
    the operator new and delete.

    Operators new and new[]
    =======================
    Dynamic memory is allocated using operator new. new is followed by a data type specifier and, if a sequence of more than one element is required , the number of these 
    within brackets []. It returns a pointer to the beginning of the new block of memory allocated. SYntax is
        pointer = new type
        pointer = new type [number_of_elements]

    There is a substantial difference between declaring a normal array and allocating dynamic memory for a block of memory using new. The most important difference is that 
    the size of a regular array needs to be a constant expression, and thus its size has to be determined at the moment of designing the program, before it is run, whereas 
    the dynamic memory allocation performed by new allows to assign memory during runtime using any variable value as size.

    The dynamic memory requested by our program is allocated by the system from the memory heap. However, computer memory is a limited resource, and it can be exhausted. 
    Therefore, there are no guarantees that all requests to allocate memory using operator new are going to be granted by the system. '

    C++ provides two standard mechanisms to check if the allocation was successful:

    One is by handling exceptions. Using this method, an exception of type bad_alloc is thrown when the allocation fails.
    The other method is known as nothrow, and what happens when it is used is that when a memory allocation fails, instead of throwing a bad_alloc exception or terminating 
    he program, the pointer returned by new is a null pointer, and the program continues its execution normally.

    Operators delete and delete[]
    =============================
    In most cases, memory allocated dynamically is only needed during specific periods of time within a program; once it is no longer needed, it can be freed so that the 
    memory becomes available again for other requests of dynamic memory. This is the purpose of operator delete, whose syntax is:

            delete pointer;
            delete[] pointer;

    Dynamic memory in C
    ===================
    C++ integrates the operators new and delete for allocating dynamic memory. But these were not available in the C language; instead, it used a library solution, with the 
    functions malloc, calloc, realloc and free, defined in the header <cstdlib> (known as <stdlib.h> in C). The functions are also available in C++ and can also be used to 
    allocate and deallocate dynamic memory.

    Note, though, that the memory blocks allocated by these functions are not necessarily compatible with those returned by new, so they should not be mixed; each one should 
    be handled with its own set of functions or operators.

*/
int main(){
    // Allocating and deallocating a singlee integer
    int *ptr = new int;
    *ptr = 10;
    cout << *ptr << endl;
    delete ptr;

    // Allocating and deallocating an array
    int size = 5;
    int *arr = new int [size];
    for (int i = 0; i < size; i++){
        arr[i] = i * 2;
    }
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;

    // Handling allocation failures
    int * foo;
    foo = new int[5]; // if allocation fails, an exception is thrown

 
    foo = new (nothrow) int [5];
    if (foo == nullptr){
        //error assigning memory. Take measures
    }

    int i, n;
    int *p;
    cout << "How many numbers would you like to type? ";
    cin >> i;
    p = new (nothrow) int[i];
    if (p == nullptr){
        cout << "Error: memory could not be allocated";
    }
    else {
        for (n =0; n < i; n++){
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n = 0; n < i; n++){
            cout << p[n] << ", ";
        }
        delete[] p;
    }
    return 0;
}