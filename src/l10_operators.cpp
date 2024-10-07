#include <iostream>
using namespace std;

int main(){

    // Assignment operator 
    int a = 5;      // assignment operator always takes place from right to left
    int b = 25;

    a = b;          // variable a is assigned value contained in variable b. value of a is lost and replaced by b at execution

    int i, j;         // a:?,  b:?
    i = 10;           // a:10, b:?
    j = 4;            // a:10, b:4
    i = b;            // a:4,  b:4
    j = 7;            // a:4,  b:7

    cout << "i:";
    cout << i;
    cout << " j:";
    cout << j;

    /* 
    
        Arithmetic operators ( +, -, *, /, % )
            The five arithmetical operations supported by C++ are:
                . +	addition
                . -	subtraction
                . *	multiplication
                . /	division
                . %	modulo

    */

   /*
        
        Compound assignment (+=, -=, *=, /=, %=, >>=, <<=, &=, ^=, |=)
            Compound assignment operators modify the current value of a variable by performing an operation on it. 
            They are equivalent to assigning the result of an operation to the first operand
                - y += x;	y = y + x;
                - x -= 5;	x = x - 5;
                - x /= y;	x = x / y;
                - price *= units + 1;	price = price * (units+1);

   */

  /*    

        Increment and decrement (++, --)
            Some expression can be shortened even more: the increase operator (++) and the decrease operator (--) 
            increase or reduce by one the value stored in a variable. T
            They are equivalent to +=1 and to -=1, respectively. Thus:
                - ++x;
                - x+=1;
                - x=x+1;

            are all equivalent in its functionality; the three of them increase by one the value of x.

            A peculiarity of this operator is that it can be used both as a prefix (++x) and as a suffix (x++).
  
  */


  /*
        Relational and comparison operators ( ==, !=, >, <, >=, <= )
            Two expressions can be compared using relational and equality operators. 
            For example, to know if two values are equal or if one is greater than the other.

            The result of such an operation is either true or false (i.e., a Boolean value).

            The relational operators in C++ are:
                . ==	Equal to
                . !=	Not equal to
                . <	Less than
                . >	Greater than
                . <=	Less than or equal to
                . >=	Greater than or equal to


  */

  /*
    
        Logical operators ( !, &&, || )
           The operator ! is the C++ operator for the Boolean operation NOT. 
           It has only one operand, to its right, and inverts it, producing false if its operand is true, and true if its operand is false. 
           Basically, it returns the opposite Boolean value of evaluating its operand. 

           The logical operators && and || are used when evaluating two expressions to obtain a single relational result. 
           The operator && corresponds to the Boolean logical operation AND, which yields true if both its operands are true, and false otherwise. 
           The operator || corresponds to the Boolean logical operation OR, which yields true if either of its operands is true, thus being false only when both operands are false. 

    */

    /*

            Conditional ternary operator ( ? )
                The conditional operator evaluates an expression, returning one value if that expression evaluates to true, 
                and a different one if the expression evaluates as false. Its syntax is:

                    condition ? result1 : result2

                If condition is true, the entire expression evaluates to result1, and otherwise to result2.

                Example
                    - 7 ==5 ? 4 :3

                
    
    
    */

   /* 
   
        Comma operator ( , )
            The comma operator (,) is used to separate two or more expressions that are included where only one expression is expected.
            When the set of expressions has to be evaluated for a value, only the right-most expression is considered.

                    Example: a = (b=3, b+2);

            This would first assign the value 3 to b, and then assign b+2 to variable a.
            At the end, variable a would contain the value 5 while variable b would contain value 3.

    */

    /* 
    
        Bitwise operators ( &, |, ^, ~, <<, >> )
            Bitwise operators modify variables considering the bit patterns that represent the values they store.
                
                &           AND               Bitwise AND
                |           OR                Bitwise inclusive OR
                ^           XOR               Bitwise exclusive OR
                ~           NOT               Unary complement (bit inversion)
                <<          SHL               Shift bits left
                >>          SHR               Shift bits right

    */

    /* 
        Explicit type casting operator
            Type casting operators allow to convert a value of a given type to another type.
            There are several ways to do this in C++.

            C-style cast:
                int i;
                float f = 3.14;
                i = (int) f;

            Functional notation:
                i = int(f);

            Both ways of casting types are valid in C++.

    */

    /* 

        sizeof
            This operator accepts one parameter, which can be either a type or a variable,
            and returns the size in bytes of that type or object:
            x = sizeof(char);  // x is assigned the value 1, because char is a type with a size of one byte.

            The value returned by sizeof is a compile-time constant, so it is always determined before program execution.

    */

/*
    Precedence of operators
        Operators are evaluated in a specific order based on their precedence.
        Parts of expressions can be enclosed in parentheses to override this precedence order.

        Examples:
            x = 5 + 7 % 2;  // x = 6 (% has higher precedence than +)
            x = 5 + (7 % 2);  // x = 6 (same as without parenthesis)
            x = (5 + 7) % 2;  // x = 0


                    Operator Precedence Table in C++
                    ================================

                    Level | Precedence Group | Operator | Description                   | Grouping
                    ------|------------------|----------|-------------------------------|----------
                    1     | Scope            | ::       | Scope qualifier               | Left-to-right
                    ------|------------------|----------|-------------------------------|----------
                    2     | Postfix (unary)  | ++ --    | Postfix increment / decrement | Left-to-right
                          |                  | ()       | Functional forms              |
                          |                  | []       | Subscript                     |
                          |                  | . ->     | Member access                 |
                    ------|------------------|----------|-------------------------------|----------
                    3     | Prefix (unary)   | ++ --    | Prefix increment / decrement  | Right-to-left
                          |                  | ~ !      | Bitwise NOT / logical NOT     |
                          |                  | + -      | Unary prefix                  |
                          |                  | & *      | Reference / dereference       |
                          |                  | new del  | Allocation / deallocation     |
                          |                  | sizeof   | Parameter pack                |
                          |                  | (type)   | C-style type-casting          |
                    ------|------------------|----------|-------------------------------|----------
                    4     | Pointer-to-member| .* ->*   | Access pointer                | Left-to-right
                    ------|------------------|----------|-------------------------------|----------
                    5     | Arithmetic:      | * / %    | Multiply, divide, modulo      | Left-to-right
                          | scaling          |          |                               |
                    ------|------------------|----------|-------------------------------|----------
                    6     | Arithmetic:      | + -      | Addition, subtraction         | Left-to-right
                          | addition         |          |                               |
                    ------|------------------|----------|-------------------------------|----------
                    7     | Bitwise shift    | << >>    | Shift left, shift right       | Left-to-right
                    ------|------------------|----------|-------------------------------|----------
                    8     | Relational       | < > <= >=| Comparison operators          | Left-to-right
                    ------|------------------|----------|-------------------------------|----------
                    9     | Equality         | == !=    | Equality / inequality         | Left-to-right
                    ------|------------------|----------|-------------------------------|----------
                    10    | And              | &        | Bitwise AND                   | Left-to-right
                    ------|------------------|----------|-------------------------------|----------
                    11    | Exclusive or     | ^        | Bitwise XOR                   | Left-to-right
                    ------|------------------|----------|-------------------------------|----------
                    12    | Inclusive or     | |        | Bitwise OR                    | Left-to-right
                    ------|------------------|----------|-------------------------------|----------
                    13    | Conjunction      | &&       | Logical AND                   | Left-to-right
                    ------|------------------|----------|-------------------------------|----------
                    14    | Disjunction      | ||       | Logical OR                    | Left-to-right
                    ------|------------------|----------|-------------------------------|----------
                    15    | Assignment-level | = *= /=  | Assignment /                  | Right-to-left
                          | expressions      | %= += -= | compound assignment           |
                          |                  | >>= <<=  |                               |
                          |                  | &= ^= |= |                               |
                          |                  | ?:       | Conditional operator          |
                    ------|------------------|----------|-------------------------------|----------
                    16    | Sequencing       | ,        | Comma separator               | Left-to-right

            Note: Operators within the same precedence level are evaluated according to their grouping,
            which is either left-to-right or right-to-left as indicated in the table.
    */
