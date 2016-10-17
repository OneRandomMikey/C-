#include<iostream>
using std::cin; using std::cout; using std::endl; using std::boolalpha;
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
    if ( c = ' '){
        index = "27";
    }
    else{
        index = c - 'a';
    }
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
    long i, s, count_original = 0, count_secret = 0;
    bool statement;
    for ( i = 0; i < original_text.length(); i++){
        if (isalpha(original_text[i])){
            count_original ++;
        }
    }
    for ( s = 0; s < secret_message.length(); s ++){
        if (isalpha(secret_message[s])){
            count_secret ++;
        }
    }
    if (count_original >= (count_secret * 5)){
        statement = true;
    }
    else{
        statement = false;
    }
    return statement;
}

string encode(string original_text, string secret_message){
    string lower_original, lower_secret, message, binary, five_letter = "";
    long i , index;
    char c;
    lower_original = lower_case(original_text);
    lower_secret = lower_case(secret_message);
    if (check_message(lower_original , lower_secret) == false){
        message = "error";
    }
    else{
        for ( i = 0; i < lower_original; i++){
            c = lower_original[i];
            if (isalpha(c)){
                five_letter += c;
            }
        }
        for ( i = 0 ; i < lower_secret.length(); i++){
            if ( isalpha(lower_secret[i])){
                binary = to_binary(lower_secret[i]);
                for (index = 0 ; index < binary.length(); index++){
                    for (h = 0 ;)
                }
            }
        }
    }
    return message;
}


int main(){
    string s, bit_str, original_text, secret_message;
    char c;
    cin >> s;
    cin >> c;
    cin >>bit_str;
    cin >> original_text;
    cin >> secret_message;
    cout << boolalpha;
    cout << lower_case(s)<<endl;
    cout << to_binary(c) << endl;
    cout << from_binary(bit_str)<<endl;
    cout << check_message(original_text, secret_message)<<endl;
}
