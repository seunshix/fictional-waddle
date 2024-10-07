#include <iostream>
#include <uchar.h>
using namespace std;

int main() {

    //Type deduction: auto and decltype
	int foo = 0;
	auto bar = foo; // the same as: int bar = foo

	// Variables that are not initizalized can also make use of type deduction with the decltype specifier
	int foofoo = 0;
	decltype(foofoo) barbar; // the same as: int bar

    return 0;

}