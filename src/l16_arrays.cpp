#include <iostream>
#include <array>

# define WIDTH 5
# define HEIGHT 3

using namespace std;

int foo [] = {16, 2, 77, 40, 12071};
int n, result=0;

int arr_jim[HEIGHT][WIDTH];
int m;

int array_jim[HEIGHT * WIDTH];

void print_array(int arg[], int length){
    for (int n = 0; n < length; ++n)
        cout << arg[n] << ' ';
    cout << '\n';
}

int main(){
    /*
        Arrays
        ======

        An array is a series of elements of the same type placed in contiguous mempry locations that can be individually referenced by adding an index to a unique identifier.
        Arrays are blocks of static memory whose size must be determined at compile time, before program runs.

        It is important to be able to clearly distinguish between the two uses that brackets [] have related to arrays. 
        They perform two different tasks: 
            one is to specify the size of arrays when they are declared; 
            and the second one is to specify indices for concrete array elements when they are accessed. 
        Do not confuse these two possible uses of brackets [] with arrays.

            int foo[5];         // declaration of a new array
            foo[2] = 75;        // access to an element of the array.  


        The main difference is that the declaration is preceded by the type of the elements, while the access is not.

        Some other valid operations with arrays:
            foo[0] = a;
            foo[a] = 75;
            b = foo [a+2];
            foo[foo[a]] = foo[2] + 5;
    */

   int foofoo[] = {10, 20, 30};
   // int bar[] { 10, 20, 30}; // universal initialization


   for ( n=0 ; n<5 ; ++n )
  {
    result += foo[n];
  }
  cout << result << '\n';


    /*
        Multi-dimensional Arrays
        ========================

        multi-dimensional arrays can be described as "arrays of arrays". for example, a bideimensional array can be imagined as a two-dimensional
        table made of elements, all of them of a same uniform data type.

        multi-dimensional arrays are an abstraction for programmers, since the same results can be achieved with a simple array, by multiplying its indices
        with the only difference that with multidimensional arrays, the compiler automatically remembers the depth of each imaginary dimension.
    
    */

   int jimmy[3][5];
   // int jimmy [3 * 5] ; //pseudo-multi-dimensional array

   for (n = 0; n < HEIGHT; n++){
        for (m = 0; m < WIDTH; m++){
            arr_jim[n][m] = (n + 1) * (m + 1);
        }
   }

   for (n = 0; n < HEIGHT; n++){
        for (m = 0; m < WIDTH; m++){
            array_jim[n* WIDTH * m] = (n + 1) * (m + 1);
        }
   }




   /* 
        Arrays as parameters
        ====================

            To accept an array as parameter for a function, the parameters can be declared as the array type, but with empty brackets, omitting the actual size of the array.
   
   */ 

  int first_array[] = {5, 10, 15};
  int second_array[] = {2, 4, 6, 8, 10};

  print_array(first_array, 3);
  print_array(second_array, 5);

  /*
        Library arrays
        ==============
        The arrays explained above are directly implemented as a language feature, inherited from the C language. They are a great feature, 
        but by restricting its copy and easily decay into pointers, they probably suffer from an excess of optimization.
        To overcome some of these issues with language built-in arrays, C++ provides an alternative array type as a standard container. 
        It is a type template (a class template, in fact) defined in header <array>.
        Containers are a library feature that falls out of the scope of this tutorial, and thus the class will not be explained in detail here. 
        Suffice it to say that they operate in a similar way to built-in arrays, except that they allow being copied (an actually expensive operation that copies 
        the entire block of memory, and thus to use with care) and decay into pointers only when explicitly told to do so (by means of its member data).

  
  */

  array<int, 3> my_array = {10, 20, 30};
  for (int i = 0; i < my_array.size(); ++i){
     ++my_array[i];
  } 

  for (int elem : my_array){
    cout << elem << '\n';
  }




  return 0;


}