#include <iostream>
#include <uchar.h>
using namespace std;

int main() {
	// Declaration of variables

	/*
		C++ is a strongly-typed language, and requires every variable to be declared with its type before its first use. 
		This informs the compiler the size to reserve in memory for the variable and how to interpret its value.
	*/

	int v;
	float mynumber;

	// Initialization of variables

	// c-like initialization
	int x = 0;

	
	// constructor initialization (introduced by the C++ language)
	int ab(0);

	// uniform initialization
	int ac{0};

	// all three ways of initializing variables are valid and equivalent in C++
	int w = 5;
	int y(3);
	int z{2};
	int output;

	w = w + y;
	output = w - z;
	cout << output;

	
	return 0;

}