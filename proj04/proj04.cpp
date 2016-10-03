/*
Zehua Li
project 4
section 03
2016-10-1
proj04.cpp

comments:
The program examine a range of integers and find, in that range, all the numbers
that are: Natural palindromes, Lychrel number and all other numbers which,
if not of the two above.
*/


#include<iostream>
using std::cin; using std::cout; using std::endl;using std::boolalpha;
#include<string>
using std::string; using std::to_string; using std::stol;
#include<algorithm>
using std::swap;using std::reverse;
// reverses the orger of the digits of n, returns that reversed number
long rev_num(long n){
    string converted_n=to_string(n);
    reverse (converted_n.begin(),converted_n.end());
    return stol(converted_n);
}
// returns true if the number is a palindrome, false otherwise
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
            break;
        }
    }
    return palindrome;
}
// if the first is greater than second, then the two numbers should be swapped
// if any of limit, first or second is less than one, return false, else return true
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
// apply the 196 algorithm for limit iterations or until the number becomes a
// palindrome
// returns true if the number of iterations exceeds the limit , false otherwise
bool check_lychrel(long n, long limit){
    long iterations = 0, n_rev, run_time=0;
    bool check = false, check_return;

    while ( check == false & run_time <= (limit+1)){
        if (is_palindrome(n) == false){
            n_rev = rev_num (n);
            n += n_rev;
            iterations ++;
            check = false;
            run_time ++;
        }
        else{
            check = true;
        }
    }
    if (iterations > (limit)){
        check_return = true;
    }
    else{
        check_return = false;
    }
    return check_return;
}
// checks each number in the range from start to finish to classify each number
// returns the count of Lychrel numbers found in the range

long check_range(long start, long end, long limit, long &natural_cnt, long &pal_cnt){
    long count = 0;

    for (start = start ; start <= end ; start ++){
        if (is_palindrome(start)){
            natural_cnt ++;
        }
        else{
            if (check_lychrel(start, limit)){
                count ++;

            }
            else{

                pal_cnt++;
            }
        }
    }
    return count;
}


int main() {
    cout << boolalpha;
    long num, limit;
    long start, end;
    long natural_cnt=0, pal_cnt=0, lychrel_cnt = 0;

    cin >> num;
    cout << rev_num(num)<<endl;
    cin >> num;
    cout << is_palindrome(num)<<endl;
    cin >> num >> limit;
    cout << check_lychrel(num,limit)<< endl;
    cin >> start >> end >> limit;
    if (check_args(limit, start, end)){
      lychrel_cnt = check_range(start, end, limit, natural_cnt, pal_cnt);
      cout << lychrel_cnt << " " << natural_cnt << " " << pal_cnt << endl;
    }
    else cout << "error" << endl;
    return 0;
}
