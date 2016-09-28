#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<string>
using std::string;
// note you need algorithm and sort
#include<algorithm>
using std::sort;
#include<cmath>

/*
  sort individual characters of a string
*/
long loc_to_dec(string s){
    long total=0;
    for (char c:s){
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
int main (){
  // string my_str = "aebcd";
  // cout << "String was:"<<my_str;
  // sort(my_str.begin(), my_str.end());
  // cout << ", and sorted is:"<< my_str<<endl;
  string loc;
  cin>>loc;

  cout<<endl;
  cout<<abbreviate(loc)<<endl;
}
