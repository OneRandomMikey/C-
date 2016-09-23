/*
Zehua Li
section:03
2016-9-23
proj03
proj03.cpp

Comments:
calculate the sum of a number's all facators; check their k-perfect and find
numbers that is k-perfect.
input a number to find that number's all factors and sum them up.
input a k number to check if  the k*number==the sum of its all factors.
if it is true then return true otherwise return false.
also find the in the range of number that is k-perfect
*/

#include<iostream>
using std::cout; using std::cin; using std::endl;
using std::boolalpha;
#include<cmath>
// the function is sum up all the factors of the number based on input.
long sum_divisors ( long num ){
    long divisors = 2, sum = num + 1, quotient, sqrt_num = sqrt(num);
// sqrt_num to reduce the total number that I need to check in the loop ,which
// increas the speed.
// while loop to check each divisors and find the factor of the number and sum
// them up.
    while ( divisors <= sqrt_num){

// to check is divisors the factor of the number. if it is not equal to0 0,
// then it is not. so just add 1 to the divisors then check next divisor.
        if ( num % divisors != 0){
            divisors++;
        }

// if the divisors is the factor of the number run else.
// quotient * divisors = number.
// add divisors and its resulting quotient to the sum
// add 1 to the divisors, then go back to top of loop to check next divisor.
        else {
            quotient = num / divisors;
            sum += (divisors + quotient);
            divisors ++;
        }
    }
    return sum;
}

// input a k value then check is k the number's k_perfect?
bool is_k_perfect(int k , long num){
    bool k_perfect;
    // if k*num==sum, return value true
    if (k * num == sum_divisors( num )){
        k_perfect = true;
    }
    else{
        k_perfect = false;
    }
    return k_perfect;
}

// check all the numbers in the range, print out the number that is k-perfect
void check_range(int k , int first , int last){
    long num;

    for (num = first ; num <= last ; num+=2 ){
        if ( is_k_perfect( k, num) == true & num != 0){
            cout << num << " ";
        }
    }
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
    return 0;
}
