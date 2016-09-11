/*
Zehua Li lizehua3@bulldog
2016-09-01
proj01.cpp

Your Comments
* input the number for side am, Angle A and side c.
* output  the result for side a, Anlge B and Angle C.
*/

#include <iostream>
using std::cout; using std::endl; using std::cin;

#include <iomanip>
using std::setprecision;using std::fixed;

#include <cmath>
using std::sqrt; using std::sin; using std::cos;

int main(){
	double pi=3.1415926535897;
	double side_b,Angle_A, side_c,side_a,Angle_B,Angle_C;
	cin>> side_b  >> Angle_A >> side_c;
	side_a=sqrt(pow(side_b,2)+pow(side_c,2)-(2*side_b*side_c*cos(Angle_A*pi/180)));
	Angle_B=asin(sin(Angle_A*pi/180)/side_a*side_b)*180/pi;
	Angle_C=180-Angle_A-Angle_B;
	cout<<fixed<<setprecision(2)<<side_a<<endl
		<<fixed<<setprecision(2)<<Angle_B<<endl
		<<fixed<<setprecision(2)<<Angle_C<<endl;
	
	return 0;
}

