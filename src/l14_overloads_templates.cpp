#include <iostream>
#include <cstdlib>

using namespace std;

int operate (int a, int b)
{
  return (a*b);
}

double operate (double a, double b)
{
  return (a/b);
}

int sum (int a, int b)
{
    return a + b;
}

double sum (double a, double b)
{
    return a + b;
}

// template <class SomeType>
// SomeType sum ( SomeType a, SomeType b)
// {
//     return a + b;
// }

template <class T>
T sum(T a, T b){
    T result;
    result = a + b;
    return result;
}

template <class T, class U>
bool are_equal (T a, U b)
{ 
    return a == b;
}

template <class T, int N>
T fixed_multiply ( T val)
{
    return val * N;
}

int main(){

    /*
            Overloading Functions
            =====================

            In C++, two different functions can have the same name if their parameters are different;
            either because they have a different number of parameters, or because any of their parameters
            are of a different type. 

            int operate(int a, int b)
            double operate(double a, double b)

            The compiler knows which one to call in each case by examining the types passed as arguments when the function is called.

            It is generally not a good idea for overloaded functions to have different behaviours, it is generally expected to have -at least-a similar behaviour
            but it is not entirely impossible for them not to.

            Note that a function cannot be overloaded only by its return type. At least one of its parameters must have a different type.

            Function Templates
            ==================
                Overloaded functions may have the same definition. 
                The 2 sum functions above are examples.  Here, sum is overloaded with different parameter types, but with the exact same body.
                It would make sense for sum to be overloaded with lots of types, and for them all to have same body, that is where template come in

                template <template-parameters> function-declaration
                Look above for generic sum function template

                It makes no difference whether the generic type is specified with keyword class or keyword typename in the 
                template argument list (they are 100% synonyms in template declarations).

                Instantiating a template is applying the template to create a function using particular types or values for its template parameters. 
                This is done by calling the function template, with the same syntax as calling a regular function, but specifying the template arguments enclosed in angle brackets:

                name <template-arguments> (function-arguments)


                Non-type template arguments
                ===========================

                Template parameters can not only include types introduced by class or typename, but can also include expressions of a particular type
    
    */

   int x = 5, y = 2;
   double n = 5.0, m = 2.0;
   cout << operate (x, y) << '\n';
   cout << operate (n, m) << '\n';

   cout << sum(1, 3) << endl;
   cout << sum(0.1, 0.5) << endl;
   
   x = sum<int>(10, 20);

   cout << x << endl;

   int i = 5, j = 6, k;
   double f = 2.0, g = 0.5, h;

   k = sum<int>(i, j);
   h = sum<double>(f, g);

   // OR

   k = sum(i, j);
   h = sum(f, g);

   cout << k << endl;
   cout << h << endl;

   if (are_equal(10, 10.0)){
    cout << "x and y are equal\n";
   }
   else{
    cout << "x and y are not equal\n";
   }

   // OR

   cout << are_equal(10, 10.0) << endl;

   // OR

   cout << are_equal<int, double>(10, 10.0);

   cout << fixed_multiply<int,2>(10) << '\n';
   cout << fixed_multiply<int,3>(10) << '\n';
   
   return 0;
}