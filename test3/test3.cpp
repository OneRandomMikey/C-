#include <iostream>
using std::cout; using std::endl;using std::fixed;using std::cin;
#include <iomanip>
using std::setprecision;
#include <cmath>
using std::abs;

double fn(double x){
    double fn_value;
    fn_value=-6*pow(x,2)+5*x+3;
    return fn_value;
}
int main(){
    double x;
    double fn_value;
    cin>>x;
    fn_value=fn(x);
    cout<<fn_value<<endl;
}
