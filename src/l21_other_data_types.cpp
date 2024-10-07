#include <iostream>

using namespace std;
/* 
        Type Aliases
        ============
        In c++, any valid type can be aliased so that it can be referred to with a  different identifier.

        There are two syntaxes , 
            the typedef keyword inherited from C language
            or the using command

        Unions
        ======
        Unions allow one portion of memory to be accessed as different data types. Union is a special data type that allows storing different
        data types in the same memory location. Only one member of a union can contain a value at any given time, The size of a union is determined by its
        largest member. All members of a union share the same memory address. Unions provide an efficient way to use the same memory location for multiple purposes.

        Syntax for declaring a union:
            union union_name {
            data_type member1;
            data_type member2;
            // ...
            };

        Accessing union members:
            union_name.member_name

        Initializing union members:
            union_variable.member_name = value;

        Enumerated Types 
        ================
        Enumerated types allow you to create a new type with a fixed set of named constants.
            enum EnumName {
                Value1,
                Value2,
                Value3,
                // ...
            };
        
            By default, enums are assigned integer values starting from 0.
            You can explicitly assign values to enum constants.
            Enums are implicitly convertible to integers.

        Enum Class
        ==========
        Enum classes provide stronger type safety and scoping
            enum class EnumName {
                Value1,
                Value2,
                Value3,
                // ...
            };


        Enum class values are scoped within the enum.
        Enum classes are not implicitly convertible to integers.
        You can specify the underlying type of an enum class.
        
        Benefits of Enum Classes
            Avoid name conflicts
            Stronger type checking
            More control over the underlying type


        When to Use

            Regular enums: When you need implicit integer conversion and global scope is acceptable.
            Enum classes: When you want stricter type safety and scoped enumerators.

        Best Practices
            Use enum classes for new code in C++11 and later.
            Choose meaningful names for enum types and values.
            Consider using all caps for enum values (convention, not required).
            Be consistent with your enum style throughout your codebase.




        
*/
int main(){
    // using typedef
    typedef char C;
    typedef unsigned int WORD;
    typedef char *pchar;
    typedef char field [50];

    C mychar, anotherchar, *ptc1;
    WORD myword;
    pchar *ptc2;
    field name;

    // using 'using'

    using C = char;
    using WORD = unsigned int;
    using pchar = char *;
    using field = char[50];

    // Unions
    union Data {
        int i; 
        float f;
        char str[20];
    };
    union Data data;

    data.i = 10;    // Now data.i is valid, data.f and data.str are not
    data.f = 3.14;  // Now data.f is valid, data.i and data.str are not
    strcpy(data.str, "Hello"); // Now data.str is valid, data.i and data.f are not

    // Enumerated Types
    enum Colors {
        RED,    // 0
        GREEN,  // 1
        BLUE,   //2
        YELLOW = 10,
        PURPLE  // 11
    };
    Colors myColor = BLUE;
    int colorValue = myColor;  // colorValue is 2

    // Enum class
    enum class TrafficLight : char {
        RED,
        YELLOW,
        GREEN
    };

    TrafficLight light = TrafficLight::GREEN;
    // int value = light;  // Error: no implicit conversion
    int value = static_cast<int>(light);  // Explicit conversion


}