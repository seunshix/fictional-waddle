#include <iostream>

using namespace std;

class Square;
/*
    Friend functions and classes
    ============================
    In principle, private and protected members of a class cannot be accessed from outside the same class in which they are declared.
    However, this rule does not apply to 'friends'

    Friends are functions or classes declared with the friend keyword

    A non-member function can access the private and protected member s of a class if it is declared a friend of that class. That is done by including
    a declaration of this external function within the class, and preceeding it with the keyword friend

    Similar to friend functions, a friend class is a class whose members have access to the private or protected members of another class:

    Inheritance between classes
    ===========================
    Classes in C++ can be extended, creating new classes which retain characteristics of the base class. This process is known as inheritance and 
    involves a base class and a derived class: The derived class inherits the members of the base class, on top of which it can add its own members.

    For example, let's imagine a seies of classes to describe two kinds of polygons: rectangles and triangles. These two polygons have certain common 
    properties, such as the values needed to calculate their areas: they both can be described simply with a height and a width(or base).
    This could be represented in the world of classes with a class Polygon from which we would derived the two other ones: Recangle and Triangle

    The Polygon class would contain members that are common for both types of polygon. In our cas: width and height. And Rectangle and Triangle would 
    be its derived class, with specific features that are different from one type of Polygon to the other

    Classes that are derived from others inherit all the accessible members of the base clase. That means if a base class includes a member A and we 
    derive a class from it with another member B, the derived class will contain both member A and member B.

    The inheritance relationship of two classes is declared in the derived class. Derived classes definitions use the following syntax:
        class derived_class_name: public base_class_name {...};

        The public access specifier may be replaced by either the private or protected specifier
    
*/

// friend function
class Rectangle{
    int width, height;
    public:
        Rectangle() {}
        Rectangle (int x, int y) : width(x), height(y) {}
        int area() {return width * height;}
        friend Rectangle duplicate (const Rectangle&);

        void convert (Square a);
};

Rectangle duplicate (const Rectangle& param){
    Rectangle res;
    res.width = param.width * 2;
    res.height = param.height * 2;
    return res;
}

// friend classes

class Square{
    friend class Rectangle;
    private:
        int side;
    public:
    Square (int a) : side(a){}
};


void Rectangle::convert (Square a){
    width = a.side;
    height = a.side;
}

/* 
    Friendship are never corresponded unless specified. In our example, Rectangle is considered a friend class by Square, but Square is not considered 
    a friend by Rectangle. Therefore, the member functions of Rectangle can access the protected and private members of Square but not the other way 
    around. Of course, Square could also be declared friend of Rectangle, if needed, granting such an access.

    Another property of friendships is that they are not transitive: The friend of a friend is not considered a friend unless explicitly specified.
*/

// how members are inherited
// Base Class
class Base{
    public: 
        int A;      // Member A
        void showA(){
            cout << "A = " << A << endl;
        }
};

class Derived : public Base{
    public:
        int B;          // Member B
        void showB(){
            cout << "B = " << endl;
        }
};

// Access Specifiers and Inheritance

/*
Summary of Member Accessibility:
+-------------------------+--------------------+------------------------+---------------------+
| Base Class Member Access| Public Inheritance | Protected Inheritance  | Private Inheritance |
+-------------------------+--------------------+------------------------+---------------------+
| Public                  | Public             | Protected              | Private             |
| Protected               | Protected          | Protected              | Private             |
| Private                 | Not Accessible     | Not Accessible         | Not Accessible      |
+-------------------------+--------------------+------------------------+---------------------+

*/


/*
Access Specifiers Summary:
We can summarize the different access types according to which functions can access them in the following way
Where "not members" represents any access from outside the class, such as from main, from another class or from a function.
+-----------------------------+----------+------------+-----------+
| Access                      | public   | protected  | private   |
+-----------------------------+----------+------------+-----------+
| members of the same class   | yes      | yes        | yes       |
| members of derived class    | yes      | yes        | no        |
| not members                 | yes      | no         | no        |
+-----------------------------+----------+------------+-----------+
If no access level is specified for the inheritance, the compiler assumes private for classes declared with keyword class and 
public for those declared with struct.

*/


class Base2{
    public: 
        int publicMember;                                       // Accessible from outside the class.
    protected:
        int protectedMember;                                    // Accessible within the class and its derived classes.
    private:
        int privateMember;                                      // Accessible only within the class.
};

class DerivedPublic : public Base2 {
    // publicMember remains public
    // protectedMember remains protected
    // privateMember is not accessible
    public:
        void accessMembers(){
            publicMember = 1;               // Accessible
            protectedMember = 2;            // Accessible
            // privateMember = 3;           // Not Accessible (Error)
        }

    /*
        Inside DerivedPublic class:
            publicMember is accessible and remains public.
            protectedMember is accessible and remains protected.
            privateMember is not accessible.
    */
};

class DerivedProtected : protected Base2 {
    // publicMember becomes protected
    // protectedMember remains protected
    // privateMember is not accessible
    public:
        void accessMembers() {
            publicMember = 1;        // Accessible
            protectedMember = 2;     // Accessible
            // privateMember = 3;    // Not Accessible (Error)
        }
    /*
        Inside Derived class:
            publicMember is accessible and becomes protected.
            protectedMember is accessible and remains protected.
            privateMember is not accessible.
    */
};

class DerivedPrivate : private Base2 {
    // publicMember becomes private
    // protectedMember becomes private
    // privateMember is not accessible
    public:
        void accessMembers() {
            publicMember = 1;        // Accessible
            protectedMember = 2;     // Accessible
            // privateMember = 3;    // Not Accessible (Error)
        }
    /*
        Inside Derived class:
            publicMember is accessible and becomes private.
            protectedMember is accessible and becomes private.
            privateMember is not accessible.
    */
};

class Polygon{
    protected:
        int width, height;
    public:
        void set_values(int a, int b){
            width = a;
            height = b;
        }
};

class Rectangle2 : public Polygon{
    public:
        int area(){
            return width * height;
        }
};

class Triangle: public Polygon{
    public:
        int area(){
            return width * height / 2;
        }
};

/*
    What is inherited from the base class?
    In principle, a publicly derived class inherits access to every member of a base class except:
        its constructors and its destructor
        its assignment operator members (operator=)
        its friends
        its private members

    Even though access to the constructors and destructor of the base class is not inherited as such, they are automatically called by 
    the constructors and destructor of the derived class.

    Unless otherwise specified, the constructors of a derived class calls the default constructor of its base classes (i.e., the constructor 
    taking no arguments). Calling a different constructor of a base class is possible, using the same syntax used to initialize member variables 
    in the initialization list:
                derived_constructor_name (parameters) : base_constructor_name (parameters) {...}

*/

// Example : constructors and derived classes
class Mother{
    public: 
        Mother(){
            cout << "Mother: no parameters " << endl;
        }
        Mother(int a){
            cout << "Mother: int parameter " << endl;
        }
};

class Daughter : public Mother{
    public:
        Daughter(int a){                                                    // nothing specified: call default constructor
            cout << "Daughter: int parameter \n" << endl;
        }
};

class Son : public Mother {                                                 // constructor specified: call this specific constructor 
  public:
    Son (int a) : Mother (a){ 
        cout << "Son: int parameter \n" << endl;
      }
};

/*
    Multiple Inheritance
    ====================
    A class may inherit from more than one class by simply specifying more base classes, separated by commas, in the list of a class's base class
    (i.e., after the colon). For example, if the program had a specific class to print on screen called Output, and we wanted our classes Rectangle 
    and Triangle to also inherit its members in addition to those of Polygon we could write:
        class Rectangle: public Polygon, public Output;
        class Triangle: public Polygon, public Output;
*/ 

class Polygon2 {
  protected:
    int width, height;
  public:
    Polygon2 (int a, int b) : width(a), height(b) {}
};

class Output {
  public:
    static void print (int i);
};

void Output::print (int i) {
  cout << i << '\n';
}

class Rectangle3: public Polygon2, public Output {
  public:
    Rectangle3 (int a, int b) : Polygon2(a,b) {}
    int area ()
      { return width*height; }
};

class Triangle2: public Polygon2, public Output {
  public:
    Triangle2 (int a, int b) : Polygon2(a,b) {}
    int area ()
      { return width*height/2; }
};
  


int main(){

    Rectangle foo;
    Rectangle bar (2, 3);
    foo = duplicate (bar);
    cout << foo.area() << "\n";

/*
        The duplicate function is a friend of class Rectangle. Therefore, function duplicate is able to access the members width and 
        height (which are private) of different objects of type Rectangle. Notice though that neither in the declaration of duplicate 
        nor in its later use in main, function duplicate is considered a member of class Rectangle. It isn't! It simply has access to 
        its private and protected members without being a member.

        Typical use cases of friend functions are operations that are conducted between two different classes accessing private or 
        protected members of both. 

*/
    Rectangle rect;
    Square sqr(4);
    rect.convert(sqr);
    cout << rect.area() << endl;


    // how members are inherited cont. 

    Derived obj;
    /// accessing inherited member A
    obj.A = 10;
    obj.showA();

    // accessing member B from Derived
    obj.B = 20;
    obj.showB();
    

    // access specifiers and inheritance

    DerivedPublic obj2;
    obj2.publicMember = 10;      // Accessible
    // obj2.protectedMember = 20; // Not Accessible (Error)
    // obj2.privateMember = 30;   // Not Accessible (Error)
    /*
            Outside DerivedPublic class:
                publicMember is accessible.
                protectedMember and privateMember are not accessible.
    */

   DerivedProtected obj3;
    // obj3.publicMember = 10;    // Not Accessible (Error)
    // obj3.protectedMember = 20; // Not Accessible (Error)
    /*
        Outside Derived class:
            publicMember and protectedMember are not accessible because they are protected in Derived.    
    */

   DerivedPrivate obj4;
    // obj4.publicMember = 10;    // Not Accessible (Error)
    // obj4.protectedMember = 20; // Not Accessible (Error)
    /*
        Outside Derived class:
            publicMember and protectedMember are not accessible because they are private in Derived.
    */

   // Polygon Example
   Rectangle2 rect2; 
   Triangle tri;
   
   // the objects of the classes Rectangle2 and Triangle each contain members inherited from Polygon (width, height and set_values)
   rect2.set_values(4, 5);
   tri.set_values(4, 5);

   cout << rect2.area() << endl;
   cout << tri.area() << endl;
   cout << endl;
   // constructors and derived classes

   Daughter kelly(0);
   Son bud(0);

   // Multiple Inheritance
   Rectangle3 rect3(4,5);
   Triangle2 tri2(4,5);
   rect3.print(rect.area());
   Triangle2::print(tri2.area());

   return 0;

}