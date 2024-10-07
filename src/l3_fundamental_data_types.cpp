#include <iostream>
#include <uchar.h>
using namespace std;

int main() {
    // Fundamental Data Types

	// Character Types
	char c = 'S'; // Exactly one byte in size. At least 8 bits
	char16_t d = 'V'; // Not smaller than char. At least 16 bits; u -UTF-16 literal
	char32_t e = 'T'; // Not smaller than char16_t. At least 32 bits; U - UTF-32 literal
	wchar_t f = 'O'; // Can represent the largest supported character set; L - wide string literal

	// Integer Types

	// signed
	signed char g = 'M'; // Same size as char. At least 8 bits; represents ASCII value of 'M'
	signed short int h = 2; // Not smaller than char. At least 16 bits
	signed int i = 3; // Not smaller than short. At least 16 bits
	signed long int j = 31 ; // Not smaller than int. At least 32 bits
	signed long long int k = 25; //Not smaller than long. At least 64 bits

	// unsigned (same as their signed counterparts)
	unsigned char l = 'M'; // Same size as char. At least 8 bits; represents ASCII value of 'M'
	unsigned short int m = 12; // Not smaller than char. At least 16 bits
	unsigned int n = 53; // Not smaller than short. At least 16 bits
	unsigned long int o = 1 ; // Not smaller than int. At least 32 bits
	unsigned long long int p = 5; //Not smaller than long. At least 64 bits
	
	// Floating-point Types
	float q = 0.5; 
	double r = 0.25; // Precision not less than float
	long double s = 0.0025; // Precision not less than double

	// Boolean Type
	bool t = true;
	bool u = false;

	// Null Pointer
	decltype(nullptr) np = nullptr;


	/*
		The more bits a type has, the more distinct values it can represent, but at the same time, also consumes more space in memory.
	*/
}