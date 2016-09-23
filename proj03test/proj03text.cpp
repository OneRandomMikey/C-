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
