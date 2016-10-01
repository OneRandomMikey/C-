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
        //cout<<"front: "<< front<<endl;
       // cout<<"back: "<<back<<endl;
        if (front == back){
            palindrome = true;
        }
        else{
            palindrome = false;
            break;
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
    long iterations = 0, n_rev, run_time=0;
    bool check = false, check_return;

    while ( check == false & run_time <= (limit+1)){
        if (is_palindrome(n) == false){
            n_rev = rev_num (n);
            n += n_rev;
            iterations ++;
            check = false;
            //cout<< "something n: "<<n<<endl;
           // cout<< "if iterations: "<<iterations <<endl;
            run_time ++;
        }
        else{
            check = true;
           // cout<< " else iterations: "<<iterations <<endl;
        }
    }
    if (iterations > (limit)){
       // cout<<"something iterations: "<<iterations<<endl;
        check_return = true;
    }
    else{
        check_return = false;
    }
    return check_return;
}

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
}
