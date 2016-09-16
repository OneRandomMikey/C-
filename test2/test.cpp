#include <iostream>
using std::cin; using std::cout; using std::endl;
long count_digit(long interger){
    long count=0;
    do
        count++;
    while(interger/=10);
    return count;
}
int main(){
    long integer;
    cin>>integer;
    cout<<integer<<" "<<count_digit(integer)<<endl;
}
