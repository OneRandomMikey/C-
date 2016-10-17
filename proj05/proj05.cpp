#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string; using std::tolower; using std::to_string; using std::stol;


string lower_case( string s ){
    string lower = "";
    char to_lower;
    int i;
    for ( i = 0 ; i < s.length() ; i++ ){
        char c = s[i];
        to_lower = tolower(c);
        lower += to_lower;
    }
    return lower;
}

string to_binary (char c){
    long index, remider;
    string binary = "", convert_remider;
    index = c - 'a';
    while ( index != 0){
        remider = index % 2;
        index = index / 2;
        convert_remider = to_string(remider);
        binary = convert_remider + binary;
    }
    while (binary.length() < 5){
        binary ='0' + binary;
    }
    return binary;
}

int from_binary(string bit_str){
    long i, index = -1, times = 1, new_c;
    char letter;
    int inter;
    string c;
    while ( letter != '1'){
        index++ ;
        letter = bit_str[index];
    }
    for ( i = index; i < bit_str.length(); i++){
        c = bit_str[i];
        if (times == 1){
            inter = 1;
            times ++;
        }
        else{
            new_c = stol(c);
            inter = inter * 2 +new_c;
        }

    }
    return inter;
}
bool check_message(string original_text, string secret_message){
    for ()
}

int main(){
    string s, bit_str;
    char c;
    cin >> s;
    cin >> c;
    cin >>bit_str;
    cout << lower_case(s)<<endl;
    cout << to_binary(c) << endl;
    cout << from_binary(bit_str)<<endl;
}
