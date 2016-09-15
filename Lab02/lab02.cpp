/*
Zehua Li lizehua3@bulldog
2016-09-14
lab02.cpp

Your Comments
*/

#include <iostream>
using std::cout; using std::endl; using std::cin;
int main(){
	long one_integer, sum_digits, first_digit, front_digit, persistence_count, count;
	cout<<"Please give me an in(negative num to quit): ";cin>>one_integer;
	while (one_integer>=0){
		persistence_count=0;
		front_digit=-1;
		sum_digits=10;
		count=0;
		if(one_integer<10){
			cout<<"Single digit"<<endl<<"Additive Persistence is: "<<persistence_count<<endl<<"Additive root is: "<<one_integer<<endl;
		}
		else {
			cout<<"Additive root"<<endl;
			while(sum_digits >9){
				if (count==0){
					sum_digits-=10;
					count+=1;
				}
				sum_digits=0;
				front_digit=one_integer/10;
				while(front_digit!=0){
					first_digit=one_integer%10;
					front_digit=one_integer/10;
					sum_digits+=first_digit;
					one_integer=front_digit;
				}
				persistence_count++;
				cout<<"sum: "<<sum_digits<<", pass: "<<persistence_count<<endl;
				one_integer=sum_digits;
			}
			cout<<"Additive persistence is: "<<persistence_count<<", root is: "<<sum_digits<<endl;
		}
		cout<<"Please give me an int(negative num to quit): ";cin>>one_integer;
	}
	cout<<"Thanks for p;aying"<<endl;
}
