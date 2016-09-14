/*
Zehua Li lizehua3@bulldog
2016-09-14
test.cpp

Your Comments
*/

#include <iostream>
using std::cout; using std::endl;using std::cin;

int main(){
	long one_integer, sum_digits,first_digit,front_digit;
	//sum_digits=0;
	cin>>one_integer;
	front_digit=1;
	sum_digits=0;
while(front_digit!=0){
		first_digit=one_integer%10;
		cout<<"first digit"<<first_digit<<endl;
		front_digit=one_integer/10;
		cout<<"second digit"<<front_digit<<endl;
		sum_digits+=first_digit;
		
		cout<<"sum of the digit"<<sum_digits<<endl;
		one_integer=front_digit;}
		
}

