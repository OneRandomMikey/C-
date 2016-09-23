long sum_divisors( long num ){
    long  divisors = 2 , sum ,x = num, y;

    if (num != 1 ){
        sum = num +1;
    }
    else{
        sum = num;
    }
    if (num % 2 == 0){
        x=num/2;
        while (divisors <= x) {
            if ( num % divisors != 0){
                divisors++;
                continue;
            }
            else {
                y = num / divisors + divisors;
                sum += y;
                divisors ++ ;
                x/=2;
            }
        }
    }
    if ( num % 3 ==0 ){
        while ( divisors <= num/3 ){
            if (num % divisors != 0){
                divisors++;
                continue;
            }
            else{
                sum += divisors;
                divisors ++;
            }
        }
    }
    return sum;
}





// long sum_divisors(long num){
//     long divisors = 1, sum=0;
//     while(divisors <= num){
//         if (num%divisors != 0){
//             divisors++;
//             continue;
//         }
//         else{
//             sum+=divisors;
//             divisors++;
//         }
//     }
//     return sum;
// }




// long sum_divisors( long num ){
//     long  divisors = 2 , sum ;
//
//     if (num != 1 ){
//         sum = num +1;
//     }
//     else{
//         sum = num;
//     }
//     if (num % 2 == 0){
//         while (divisors <= num/2 ){
//             if ( num % divisors != 0){
//                 divisors++;
//                 continue;
//             }
//             else {
//                 sum += divisors;
//                 divisors ++ ;
//             }
//         }
//     }
//     if ( num % 3 ==0 ){
//         while ( divisors <= num/3 ){
//             if (num % divisors != 0){
//                 divisors++;
//                 continue;
//             }
//             else{
//                 sum += divisors;
//                 divisors ++;
//             }
//         }
//     }
//     return sum;
// }






#include<iostream>
using std::cout; using std::cin; using std::endl;
using std::boolalpha;

long sum_divisors ( long num ){
    long divisors = 2, sum, quotient = num;
    if ( num != 1){
        sum = num + 1;
    }
    else{
        sum = num;
    }
    //if (num % 2 == 0){
        while ( divisors < quotient){
            if ( num % divisors != 0){
                divisors++;
            }
            else {
                quotient = num / divisors;
                sum+=(divisors + quotient);
                divisors ++;
            }
            cout<<"quotient: "<<quotient<<endl;
            //cout<< "divisors: "<<divisors<<" quotent: "<< quotient<<endl;
        }
    //}
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
