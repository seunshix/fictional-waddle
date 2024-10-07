#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
/* 
    Data Structures
    ===============
    A data structure is a group of data elements grouped together under one name. These data elements, known as members,
    can have different type and different lengths. Data structures can be declared in C++ using the following syntax
        struct type_name{
            member_type1 member_name1;
            member_type2 member_name2;
            .
            .
            } object_names;
    
    Where type_name is a name for the structure type, object_name can be a set of valid identifiers for objects that have 
    the type of this structure. Within braces {}, there is a list with the data members, each one is specified with a type 
    and a valid identifier as its name.

    This declares a structure type, called product, and defines it having two members: weight and price, each of a different fundamental type. 
    This declaration creates a new type (product), which is then used to declare three objects (variables) of this type: apple, banana, and melon. 
    Note how once product is declared, it is used just like any other type.

    Because structures are types, they can also be used as the type of arrays to construct tables or databases of them

    Pointers to Structures
    ======================
    The arrow operator (->) is a dereference operator that is used exclusively with pointers to objects that have members. This operator serves to access 
    the member of an object directly from its address. For example, in the example below in the code:
        pmovie->
    is, for all purposes, equivalent to:
        (*pmovie).

    Both expressions, pmovie->title and (*pmovie).title are valid, and both access the member title of the data structure pointed by a pointer called pmovie. 
    It is definitely something different than:
        *pmovie.
    which is rather equivalent to:
        *(pmovie.title)


    This would access the value pointed by a hypothetical pointer member called title of the structure object pmovie (which is not the case, since 
    title is not a pointer type). The following panel summarizes possible combinations of the operators for pointers and for structure members:
            |----------------------------------------------------------------------|
            | Expression |	            What is evaluated           |	Equivalent |
            |----------------------------------------------------------------------|
            |   a.b	     | Member b of object a	                    |              |
            |   a->b	 | Member b of object pointed to by a	    |    (*a).b    |
            |   *a.b	 | Value pointed to by member b of object a |    *(a.b)    |
            |----------------------------------------------------------------------|

    Nesting Structures
    ==================
    Structures can also be nested in such a way that an element of a structure is itself another structure
*/


struct product {
    int weight;
    double price;
};

product apple;
product banana, melon;

    // OR
    // struct product{
    //     int weight;
    //     double price;
    // } apple, banana, melon;

    // Example

struct movies_t{
    string title; 
    int year;
}mine, yours, films[3];

void printmovie( movies_t movie){
    cout << movie.title;
    cout << " (" << movie.year << ")\n";
}

// Nested structure
struct friends_t {
  string name;
  string email;
  movies_t favorite_movie;
} charlie, maria;




int main(){
    
    string mystr;

    mine.title = "2001 A Space Oddysey";
    mine.year = 1968;

    cout << "Enter title: ";
    getline(cin, yours.title);
   
    cout << "Enter year: ";
    getline (cin, mystr);
    stringstream(mystr) >> yours.year;


    cout << "My favorite movie is:\n";
    printmovie(mine);
    cout << "And yours is:\n";
    printmovie(yours);

    // array of structures
    for (int n = 0; n <3; n++){
        cout << "Enter title: ";
        getline(cin, films[n].title);
        cout << "Enter year: ";
        getline(cin, mystr);
        stringstream(mystr) >> films[n].year;
    }
    cout << "\nYou have entered these movies:\n";
    for (int n = 0; n < 3; n++){
        printmovie (films[n]);
    }

    // Pointers to Structures
    movies_t amovie;
    movies_t * pmovie;
    pmovie = &amovie;

    cout << "Enter title: ";
    getline (cin, pmovie->title);
    cout << "Enter year: ";
    getline (cin, mystr);
    (stringstream) mystr >> pmovie->year;

    cout << "\nYou have entered:\n";
    cout << pmovie->title;
    cout << " (" << pmovie->year << ")\n";

    // Nested structure
    friends_t * pfriends = &charlie;

    return 0; 
}