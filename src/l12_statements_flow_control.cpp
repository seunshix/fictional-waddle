#include <iostream>
using namespace std;

int main(){
    // if-statements

    int x = 100;
    if (x == 10){
        cout << "x is " << x << endl;
    }

    if (x == 100) {cout << "x is " << x << endl;}

    //if-else statements

    if (x > 0){
        cout << "x is positive\n";
    }
    else if (x < 0){
        cout << "x is negative\n";
    }
    else{
        cout << "x is 0\n";
    }

    // Loops

    /*
        while (expression) statement
            The while-loop simply repeats statement while expression is true. 
            If, after any execution of statement, expression is no longer true, the loop ends, and the program continues right after the loop.
    
    */
   int n = 5;
   while (n > 0){
    cout << n << ", ";
    -- n;
   }
   cout << "\nWe have a liftoff!\n";

   /*
   
        do statement while (condition)
            It behaves like a while-loop, except that condition is evaluated after the execution of statement instead of before, 
            guaranteeing at least one execution of statement, even if condition is never fulfilled.
    
   */

   string str;
   do {
    cout << "Enter text: ";
    getline(cin, str);
    cout << "You entered: " << str << '\n';
    cout << "Clue : 'bye'\n";
   } while(str != "bye");


   /*
   
        for (initialization; condition; increase) statement;
            Like the while-loop, this loop repeats statement while condition is true. 
            But, in addition, the for loop provides specific locations to contain an initialization and an increase expression, 
            executed before the loop begins the first time, and after each iteration, respectively. Therefore, it is especially useful to use counter variables as condition.


            The three fields in a for-loop are optional. They can be left empty, but in all cases the semicolon signs between them are required. 
            For example, for (;n<10;) is a loop without initialization or increase (equivalent to a while-loop); 
            and for (;n<10;++n) is a loop with increase, but no initialization (maybe because the variable was already initialized before the loop). 
            A loop with no condition is equivalent to a loop with true as condition (i.e., an infinite loop).


            Range-based for loops
            for(declaration : range) statement;


   */
   
   for (int i = 10; i > 0; i--){
    cout << i << ", ";
   }
   cout << "\nWe have liftoff!\n";


   for (int a = 0, b = 50; a != b; ++a, --b){
    cout << "We meet here, a = " << a << " b = " << b << endl; 
   }

   string mystr("Hello!");

   for (char c : mystr){
    cout << "[" << c << "]";
   }
   cout << "\n";

   for (auto c : mystr){
    cout << "[" << c << "]";
   }

   cout << "\n";

   // break leaves a loop, even if the condition is not fulfilled
   for (int n=10; n>0; n--) {
    cout << n << ", ";
    if (n==3)
    {
      cout << "\ncountdown aborted!\n";
      break;
    }
   }

   // continue statement causes the program to skip the rest of the loop in the current iteration, 
   // as if the end of the statement block had been reached, causing it to jump to the start of the following iteration.

   // let's skip 5 in our countdown

   for (int n=10; n>0; n--) {
    if (n==5) continue;
    cout << n << ", ";
    }
    
    cout << "We have a liftoff!\n";

    // switch...case

    int num;

    switch (x) {
        case 1:
        case 2:
        case 3:
            cout << "x is 1, 2 or 3";
            break;
        default:
            cout << "x is not 1, 2 nor 3";
  }





}