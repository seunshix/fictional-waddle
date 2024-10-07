#include <iostream>
#include <cstdlib>

using namespace std;

/*
        1. Scopes
        =========
            Named entities, such as variables, functions, and compound types need to be declared before being used in C++. T
            he point in the program where this declaration happens influences its visibility:
            
            An entity declared outside any block has global scope, meaning that its name is valid anywhere in the code. 
            While an entity declared within a block, such as a function or a selective statement, has block scope, and is only
            visible within the specific block in which it is declared, but not outside it.
            
            Variables with block scope are known as local variables
            In each scope, a name can only represent one entity. For example, there cannot be two variables with the same name in the same scope:

            The visibility of an entity with block scope extends until the end of the block, including inner blocks. 
            Nevertheless, an inner block, because it is a different block, can re-utilize a name existing in an outer scope to refer to a different entity; 
            in this case, the name will refer to a different entity only within the inner block, hiding the entity it names outside. 
            While outside it, it will still refer to the original entity.

        2. Namespaces
        =============
        Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes, giving them namespace scope. 
        This allows organizing the elements of programs into different logical scopes referred to by names.

        Only one entity can exist with aparticular name with a particular scope. Not much a problem for local names but could be for non-local names

        Syntax to declare a namespace is

            namespace identifier
            {
            named_entities
            }
        Where identifier is any valid identifier and named_entities is the set of variables, types and functions that are included within the namespace. 

        Example:
            namespace myNamespace
            {
                int a, b;
            }
            
        In this case, the variables a and b are normal variables declared within a namespace called myNamespace.
        These variables can be accessed from within their namespace normally, with their identifier (either a or b), 
        but if accessed from outside the myNamespace namespace they have to be properly qualified with the scope operator ::. F
        or example, to access the previous variables from outside myNamespace they should be qualified like:

                myNamespace::a
                myNamespace::b

        3. using
        ========
        The keyword using introduces a name into the current declarative region (such as a block), thus avoiding the need to qualify the name.

        4. Namespace aliasing
        =====================
        Existing namespaces can be aliased with new names, with the following syntax:

                namespace new_name = current_name;

        5. Storage classes
        ==================
        The storage for variables with global or namespace scope is allocated for the entire duration of the program. 
        This is known as static storage, and it contrasts with the storage for local variables (those declared within a block). 
        These use what is known as automatic storage. The storage for local variables is only available during the block in which they are declared; after that, 
        that same storage may be used for a local variable of some other function, or used otherwise.

        But there is another substantial difference between variables with static storage and variables with automatic storage:
            - Variables with static storage (such as global variables) that are not explicitly initialized are automatically initialized to zeroes.
            - Variables with automatic storage (such as local variables) that are not explicitly initialized are left uninitialized, and thus have an undetermined value.

*/

// int foo;                             // global variable
int i;
int some_function(){
    int bar;                        //local variable  
    bar = 0;

    int x;
    x = 0;
    // double x;                    // wrong : name already used in scope
    // x = 0.0
    return 0;
}

int other_function(){
    // foo = 1;                        //ok: foo is a global variable
    // bar = 2;                    //wrong: bar is not visible from this function
    return 0;
}

namespace MyNamespace{
    int a, b;
}

namespace foo 
{
    int value() {return 5;}
}

namespace bar
{
    const double pi = 3.1416;
    double value() {return 2 * pi;}
}

namespace first 
{
    int a = 5;
    int b = 10;
}

namespace second
{
    double a = 3.1416;
    double b = 2.7183;
}
/*

    In this case, there are two functions with the same name: value. One is defined within the namespace foo, and the other one in bar. 
    No redefinition errors happen thanks to namespaces. Notice also how pi is accessed in an unqualified manner from within namespace bar (just as pi), 
    while it is again accessed in main, but here it needs to be qualified as bar::pi.

    Namespaces can be split: Two segments of a code can be declared in the same namespace:

        namespace foo { int a; }
        namespace bar { int b; }
        namespace foo { int c; }


    This declares three variables: a and c are in namespace foo, while b is in namespace bar. 
    Namespaces can even extend across different translation units (i.e., across different files of source code).


*/

int main(){

    int x = 10;
    int y = 20;
    {
        int x;                   // ok, inner scope.
        x = 50;                 // sets value to inner x
        y = 50;                // sets value to (outer) y

        cout << "inner block:\n";
        cout << "x: " << x << '\n';
        cout << "y: " << y << '\n'; 
    }

    cout << "outer block: \n";
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';

    cout << foo::value() << '\n';
    cout << bar::value() << '\n';
    cout << bar::pi << '\n';
    cout << endl;

    // using

    cout << "Using Namespace" << endl;
    using first::a;
    using second::b;

    cout << a << '\n';
    cout << b << '\n';
    cout << first::b << '\n';
    cout << second::a << '\n';
    cout << endl;

    /* this next using namespace is overriden by one ontop*/
    // the keyword using can also be used as a directive to introduce an entire namespace
    using namespace first;
    cout << a << '\n';
    cout << b << '\n';
    cout << second::a << '\n';
    cout << second::b << '\n';

    {
    using namespace first;
    cout << x << '\n';
    }
    {
    using namespace second;
    cout << x << '\n';
    }

    // Storage classes

    int j;
    cout << i << '\n';
    cout << j << '\n';

    return 0;
}