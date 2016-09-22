#include<iostream>
using std::cout; using std::endl; using std::cin;
using std::boolalpha;

int main (){
    cout << boolalpha;
    long my_long_1 = 123;
    long &my_long_2 = my_long_1;
    long *my_long_3 = &my_long_1;

    cout << my_long_1 << endl;
    cout << my_long_2 << endl;
    cout << my_long_3 << endl;
    cout << *my_long_3 << endl;
    cout << (&my_long_1 == my_long_3) << endl << endl;

    my_long_2 = 456;

    cout << my_long_1 << endl;
    cout << my_long_2 << endl;
    cout << my_long_3 << endl;
    cout << *my_long_3 << endl;
    cout << (&my_long_1 == my_long_3) << endl << endl;

    *my_long_3 = 789;
    cout << my_long_1 << endl;
    cout << my_long_2 << endl;
    cout << my_long_3 << endl;
    cout << *my_long_3 << endl;
    cout << (&my_long_1 == my_long_3) << endl << endl;

    long another_long = 012;
    my_long_3 = &another_long;

    cout << my_long_1 << endl;
    cout << my_long_2 << endl;
    cout << my_long_3 << endl;
    cout << *my_long_3 << endl;
    cout << (&my_long_1 == my_long_3) << endl << endl;


}
    
