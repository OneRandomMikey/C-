#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl;
using std::string;using std::vector;
struct MathVector
{
	long x;
	long y;
	MathVector();
	MathVector(long, long);
	MathVector add(const MathVector&);
	MathVector mult(long n);
	long mult(const MathVector&);
	double magnitude();
};

string vec_to_str(const MathVector &v);


#endif
