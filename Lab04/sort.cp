#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<string>
using std::string;
// note you need algorithm and sort
#include<algorithm>
using std::sort;
#include<cmath>

long loc_to_dec(string loc){
    long total=0;
    for (char c:loc){
        total+=pow(2,c-'a');
    }
    return total;
}
string abbreviate(string loc){
    string origin_string = loc;
    sort(loc.begin(),loc.end());
    for (long c = 1; c <= (loc.size());){
        char current_char = loc [c-1];
        char next_char = loc [c];

        if (current_char == next_char){
            if (c > 1){
                loc=loc.substr(0,c-1)+static_cast <char> (current_char+1)+loc.substr(c+1);
            }
            else{
                loc= static_cast<char>(current_char+1)+loc.substr(c+1);
            }
            sort(loc.begin(),loc.end());
        }
        else{
            c++;
        }
    }
    return loc;
}

string dec_to_loc(long dec){
    char a = 'a';
    string new_string = string (dec , a);
    return abbreviate(new_string);
}

long add_loc (string loc1 , string loc2){
    string new_string = abbreviate ((loc1 + loc2));
    return loc_to_dec (new_string);
}
int main (){
    string loc;
    long dec;
    cout<<"Please enter a location string: ";
    cin>>loc;
    cout<<"Please enter an integer: ";
    cin>>dec;
    cout<<"Location string is: "<<loc<<". "<<"Its resulting integer is: "<<loc_to_dec (loc)<<endl;
    cout<<"Location string is: "<<loc<<". "<<"Its reduced form is: "<<abbreviate(loc)<<endl;
    cout<<"Integer is: "<<dec<<" "<<"Its location string is: "<<dec_to_loc(dec)<<endl;
    cout<<"Result: "<<add_loc(loc,loc)<<endl;
    return 0;
}
