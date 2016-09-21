#include <iostream>
using std::cout; using std::endl;using std::fixed;using std::cin;
#include <iomanip>
using std::setprecision;
#include <cmath>
using std::abs;

long fn(long x){
    long fn_value;
    fn_value=-6*pow(x,2)+5*x+3;
    return fn_value;
}
double integral(long x){
    double fn_integral;
    fn_integral=-2*pow(x,3)+(5.0/2)*pow(x,2)+3*x;
    return fn_integral;
}
double trapezoid(double a,double b,double n){
    double y=1,fn_value=0;
    double  sum_area,x=0;
    for (x=0;x<=1;x+=((b-a)/n)){
        cout<<"x: "<<x<<endl;
        if ((x==0) || (x=1)){
            fn_value+=fn(x);

        }
        else{
            fn_value+=2*fn(x);
        }
    }
    cout<<"fn value: "<<fn_value<<endl;
    sum_area=((b-a)/(2*n))*fn_value;
    return sum_area;
}
int main(){


    double tolerance,trapezoid_value,integral_value;
    double n;
    cin>>tolerance;
    cin>>n;
    integral_value=integral(1);
    trapezoid_value=trapezoid(0,1,n);
    // do{
    //     trapezoid_value=trapezoid(0,1,n);
    //     n*=2;
        //cout<<abs(integral_value-trapezoid_value)<<endl;
    // }
    // while (abs(integral_value-trapezoid_value)>tolerance);
    //integral_value=integral(1);
    //trapezoid_value=trapezoid(0,1,n);
    cout<<integral_value<<endl;
    cout<<trapezoid_value<<n<<endl;
}
