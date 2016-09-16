#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include <iomanip>
using std:: setprecision;
#include<cmath>
using std::abs;
int main(){
    double epsilon,new_gl=10,old_gl=0,new_n=10,old_n=0,series_gl=0,series_n=0;
    long count_gl=0,count_n=0,n_gl=0,n_n=0,n_gl_final=1,n_n_final=1,first_time_gl=0,first_time_n=0;
    cin>>epsilon;
    if (epsilon==0){
        new_gl-=10;
        new_n-=10;
        cout<<fixed<<setprecision(12)<<new_gl<<" "<<count_gl<<endl;
        cout<<fixed<<setprecision(12)<<new_n<<" "<<count_n<<endl;
    }
    else{
        while(abs(new_gl-old_gl)>epsilon){
            if (first_time_gl>0){
                old_gl=new_gl;
            }
            first_time_gl++;
            while(n_gl_final!=n_gl){
                series_gl+=(pow(-1,n_gl))/(2*n_gl+1);
                n_gl++;
            }
            new_gl=4*series_gl;
            count_gl++;
            n_gl_final++;
            n_gl=0;
            series_gl=0;
        }
        cout<<fixed<<setprecision(12)<<new_gl<<" "<<count_gl<<endl;
        while(abs(new_n-old_n)>epsilon){
            if (first_time_n>0){
                old_n=new_n;
            }
            first_time_n++;
            while(n_n_final!=n_n){
                series_n+=(pow(-1,n_n))/((2*n_n+2)*(2*n_n+3)*(2*n_n+4));
                n_n++;
            }
            new_n=3+4*series_n;
            count_n++;
            n_n_final++;
            n_n=0;
            series_n=0;
        }
        cout<<fixed<<setprecision(12)<<new_n<<" "<<count_n<<endl;
    }

return 0;
}
