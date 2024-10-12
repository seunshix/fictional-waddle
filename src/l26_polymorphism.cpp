#include <iostream>

using namespace std;


/*
    Pointers to base class
    ======================
    One of the powerful features of C++ inheritance is that a pointer to a derived class object can be assigned to a pointer of its base class type.
    This is because the derived class is a specialized version of the base class, and, therefore, compatible.

    Virtual Functions
    =================
    To enable calling derived class methods through base class pointers, we use virtual functions. A virtual function is a member function 
    that you expect to be redefined in derived classes. Declaring a function as virtual in the base class allows derived classes to override 
    it and ensures that the correct function is called based on the object type, even when using a base class pointer.
    A class that declares or inherits a virtual function is called a polymorphic class.

    Abstract Base Class
    ===================
    An abstract base class is a class that cannot be instantiated and is designed to be a base class for other classes. It contains at least one pure 
    virtual function, which is a virtual function declared by assigning = 0 in its declaration.

    The Polygon function below is an abstract base class 

*/

// Example
class Polygon {
    protected:
        int width, height;
    public:
        Polygon (int a, int b) : width(a), height(b) {}
        // void set_values(int a, int b){
        //     width = a;
        //     height = b;
        // }
        // virtual int area (){
        //      return 0; 
        // }

        virtual int area() = 0;
        void printarea(){ 
            cout << this->area() << '\n'; 
            }
};
class Rectangle : public Polygon{
    public:
        Rectangle(int a,int b) : Polygon(a,b) {}
        int area(){
            return width * height;
        }
};

class Triangle: public Polygon {
    public:
        Triangle(int a,int b) : Polygon(a,b) {}
        int area(){
            return width*height/2; 
        }
};


int main(){
    // Rectangle rect;
    // Triangle trgl;
    // // Polygon poly;                                           // error because class Polygon is now and abstract base class
    // Polygon * ppoly1 = &rect;
    // Polygon * ppoly2 = &trgl;
    // // Polygon * ppoly3 = &poly;
    // ppoly1->set_values (4,5);
    // ppoly2->set_values (4,5);
    // // ppoly3->set_values (4,5);
    
    // cout << rect.area() << endl;
    // cout << trgl.area() << endl;

    // cout << ppoly1->area() << endl;
    // cout << ppoly2->area() << endl;
    // // cout << ppoly3->area() << endl;

    /*
        Pointers ppoly1 and ppoly2 are declared as pointers to Polygon, but assigned the addresses of rect and trgl, which are Rectangle 
        and Triangle objects, respectively. This is valid because Rectangle and Triangle are derived from Polygon.
        
        Through ppoly1 and ppoly2, we can access Polygon's members like set_values. We cannot access area() through these pointers because 
        area() is not a member of Polygon.
        
        To call area(), we use the objects rect and trgl directly because area() is defined in the derived classes. 

        Virtual Functions 
        When area() is called through a Polygon* pointer, the program determines at runtime which area() function to invoke based on the actual 
        object type (this is called dynamic binding).
    */

   // Because Polygon is an abstract base class does not mean it is completely useless, It can be used to create pointers to it,
   // and take advantage of all its polymorphic abilities. Example  is Polygon *ppoly1 and Polygon *ppoly2 declared in the body of this function
   // You see that both pointer declarations can also be dereferenced.

    Polygon * ppoly1 = new Rectangle (4,5);
    Polygon * ppoly2 = new Triangle (4,5);
    ppoly1->printarea();
    ppoly2->printarea();
    delete ppoly1;
    delete ppoly2;
    return 0;
}