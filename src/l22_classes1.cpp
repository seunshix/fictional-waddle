#include <iostream>

using namespace std;
/*
    Classes
    =======

    An object is an instantiation of a class. In terms of variables, a class would be the type, and an object would be the variable
    Classes are defined using either keyword classs or keyword struct with the following syntax:
        class class_name{
        access_specifier_1:
            member1;
        access_specifier_2:
            member2;
        ...
        } object_names;

        Where class_name is a valid identifier for the class, object_names is an optional list of names for objects of this class. 
        The body of the declaration can contain members, which can either be data or function declarations, and optionally access specifiers.

        Classes have the same format as plain data structures, except that they can also include functions and have these new things called access specifiers. 
        An access specifier is one of the following three keywords: private, public or protected. These specifiers modify the access rights for the members that follow them:

        private members of a class are accessible only from within other members of the same class (or from their "friends").
        protected members are accessible from other members of the same class (or from their "friends"), but also from members of their derived classes.
        Finally, public members are accessible from anywhere where the object is visible.


        By default, all members of a class declared with the class keyword have private access for all its members. 
        Therefore, any member that is declared before any other access specifier has private access automatically. 
    
    Constructors
    ============
    Used to initialize member variables or allocate storage whenever a new object of a class is called so we do not have scenarios of undetermined results


*/

class Rectangle{
        int width, height;  // member: height, width with private access (default access level)
    public:
        // void set_values (int, int); // member with public access level
        Rectangle();
        Rectangle (int, int);
        int area() {return width * height;}           // member with public access level
}; 
// Rectangle is the class name and rect is the class name where rect is an object of type Rectangle

// void Rectangle::set_values (int x, int y){
//     width = x;
//     height = y;
// }

// Constructor that automatically allocates memory and assigns values to an object of Rectangle class
Rectangle::Rectangle(){
    width = 0;
    height = 0;
}
Rectangle::Rectangle (int a, int b){
    width = a;
    height = b;
}

class Circle{
    double radius;
    public:
        Circle(double r){radius = r;}
        double circumference() { return 2*radius*3.14159265;}
};

int main() {
    Rectangle rect(3, 4), rectb(76, 75); // default constructor not called
    Rectangle rectc; // default constructor called
    // rect(3, 4);
    // rectb(76, 75);
    cout << "area: " << rect.area() << endl;
    cout << "area: " << rectb.area() << endl;
    cout << "area: " << rectc.area() << endl;

    // Four ways to constructs objects of a class whose constructor takes a single parameter
    Circle foo(10.0);       // functional form
    Circle bar = 20.0;      // assignment init
    Circle baz{30.0};       // uniform init
    Circle qux = {40.0};    //POD-like

    cout << '\n';
    cout << "foo's circumference: " << foo.circumference() << '\n';
    cout << "bar's circumference: " << bar.circumference() << '\n';
    cout << "baz's circumference: " << baz.circumference() << '\n';
    cout << "qux's circumference: " << qux.circumference() << '\n';
    cout << '\n';

    return 0;
}