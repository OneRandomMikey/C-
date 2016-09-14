/*
Zehua Li lizehua3@bulldog
2016-09-13
proj02.cpp

Your Comments
*/

#include <iostream>
using std::cout; using std::endl;using std::cin; using std::fixed;
#include <iomanip>
using std::setprecision;
#include <cmath>


int main(){
	double x,y,pi,epsilon,ans,gl_series,n_series,n;
	cin>>epsilon;
	//cin>>x;
	x=0;
	y=0;
	ans=0;
	n=0;
	pi=3.1415926535897;
	while (fabs(pi-gl_series)>epsilon && fabs(pi-n_series)>epsilon){
		x+=(-pow(1,n))/(2*n+1);
		gl_series=4*x;
		
		y+=(pow(-1,n))/((2*n+2)*(2*n+3)*(2*n+4));
		n_series=3+4*y;
		
		n++;
		}
	cout<<fixed<<setprecision(15)<<n_series<<endl<<gl_series<<endl<<n<<endl;
	return 0;
}
	//((pi-(3+4*ans)>epsilon)//{
		//ans+=(pow(-1,x))/((2*x+2)*(2*x+3)*(2*x+4));
		//x+=1;
		
		
		
//	cout<<3+4*ans<<endl<<x<<endl;
	
	//for (;x<=19;x++){
		//y+=(pow(-1,x))/((2*x+2)*(2*x+3)*(2*x+4));
		//}
	//pi=3+4*y;
	//cout<<fixed<<setprecision(15)<<pi<<endl;
	 
	//cout<<EPSILON;
	



