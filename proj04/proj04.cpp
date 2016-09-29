#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string; using std::to_string;
#include<algorithm>
using std::reverse;
string rev_num(long n){
    string converted_n=to_string(n);
    //long y = x.size();
    string reversed_n = reverse (converted_n.begin(),converted_n.end());
    // long cover_time = n.length();
    // return cover_time;
    // n=ltos(n);
    // return reverse(n.begin(),n.end())

    return reversed_n;
}

int main(){
    long n;
    cin>>n;
    cout<<rev_num(n)<<endl;
}
