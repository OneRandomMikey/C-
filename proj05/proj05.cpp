#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;


string lower_case( string s ){
    string lower;
    lower = tolower( s )
    return lower;
}
int main(){
    string s;
    cin >> s >>endl;
    cout << lower_case(s)<<endl;
}
