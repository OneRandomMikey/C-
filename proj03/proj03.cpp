#include<iostream>
using std::cout; using std::cin; using std::endl;
using std::boolalpha;
// you may need other includes

// functions here, before main
long sum_divisors(long num){
    long divisors = 1, sum=0;
    while(divisors <= num){
        if (num%divisors != 0){
            divisors++;
            continue;
        }
        else{
            sum+=divisors;
            divisors++;
        }
    }
    return sum;
}

bool is_k_perfect(int k , long num){
    bool k_perfect;
    if (k * num == sum_divisors( num )){
        k_perfect = true;
    }
    else{
        k_perfect = false;
    }
    return k_perfect;
}

void check_range(int k , int first , int last){
    long num;

    for (num = first ; num <= last ; num++ ){
        if ( is_k_perfect( k, num) == true & num != 0){
            cout << num << " ";
        }
    }
    return;
}

int main (){
  cout << boolalpha;
  long first, last, num, k;
  cin >> num;
  cout << sum_divisors(num) << endl;
  cin >> k;
  cout << is_k_perfect(k,num) << endl;
  cin >> first >> last;
  check_range(k,first,last);
  cout << endl;
}
