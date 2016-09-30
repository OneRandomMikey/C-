#include<iostream>
using std::cin; using std::cout; using std::endl;using std::boolalpha;
#include<string>
using std::string; using std::to_string; using std::stol;
#include<algorithm>
using std::sort; using std::swap;
#include <iostream>
using std::reverse;

long rev_num(long n){
    string converted_n=to_string(n);
    reverse (converted_n.begin(),converted_n.end());
    return stol(converted_n);
}

bool is_palindrome(long n){
    string converted_n = to_string(n);
    bool palindrome;
    for (long compare_time = 1;compare_time <= converted_n.length()/2; compare_time++){
        char front, back;
        front = converted_n[compare_time - 1];
        back = converted_n[converted_n.length() - compare_time];
        if (front == back){
            palindrome = true;
        }
        else{
            palindrome = false;
        }
    }
    return palindrome;
    // // long compare_time = converted_n.length();
    // if (converted_n.length() == 2){
    //     if (converted_n[0] == converted_n[1]){
    //         palindrome = true;
    //     }
    //     else{
    //         palindrome = false;
    //     }
    // }
    // else {
    //     n = n + rev_num(n);
    //
    // }
}

bool check_args(long limit , long &first , long &second){
    bool x;
    if (first > second){
        swap(first,second);
    }
    if (limit < 1 || first < 1 || second < 1){
        x = false;
    }
    else{
        x = true;
    }
    return x;
}

bool check_lychrel(long n, long limit){

}

int main(){
    long n, limit, first,second;
    cin>>n>>limit>>first>>second;
    cout<<boolalpha;
    cout<<rev_num(n)<<endl;
    cout<<is_palindrome(n)<<endl;
    cout<<check_args(limit,first,second)<<endl;
}
