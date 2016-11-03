#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "vector.h"
using std::cout; using std::endl;
using std::string;using std::vector; using std::to_string; using std::pow;

MathVector::MathVector(){
	x = 0;
	y = 0;
}

MathVector::MathVector(long a, long b){
	x = a;
	y = b;
}

MathVector MathVector::add(const MathVector &v)
{
	MathVector addtion(v.x+x,v.y+y);
	return addtion;
}
MathVector MathVector::mult(long n)
{
	MathVector v1(x,y);
	MathVector V(x*n, y*n);
	return V;
}

long MathVector::mult(const MathVector &v)
{
	long product = x*v.x + y*v.y;
	return product;
}


double MathVector::magnitude()
{
	double magnitude = sqrt(pow(x,2)+pow(y,2));
	return magnitude;
}

std::string vec_to_str(const MathVector &v)
{
	string tostring ="";
	tostring += to_string(v.x);
	tostring += ":";
	tostring += to_string(v.y);
	return tostring;
}
