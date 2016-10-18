/*
Zehua Li
Project 5
section 03
2016-10-17
proj05.cpp

commit: Steganography is the process of hiding a "secret
message" in another text file, image or even sound file.
*/


#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;using std::string; using std::tolower; using std::to_string; using std::stol;
#include<vector>
using std::vector;
#include<algorithm>
using std::reverse; using std::transform; using std::count_if;
#include<cmath>
using std::pow;
#include<iterator>
using std::back_inserter;

// your functions here

//returns the lower case version of the input string s, that is all alphabetic characters are
//converted to lower case.
string lower_case( string s ){
    string lower = "";
    char to_lower;
    int i;
    for ( i = 0 ; i < s.length() ; i++ ){
        char c = s[i];
        to_lower = tolower(c); // convert each char to lower case
        lower += to_lower;
    }
    return lower;
}
//returns 5 bit string that is the index of the character argument
string to_binary (char c){
    long index, remider;
    string binary = "", convert_remider;
    if ( c == ' '){
        index = 27; //set white space to be 27;
    }
    else{
        index = c - 'a'; //find the index of the char - 'a'
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
//returns the integer that the 5 bit binary string bit_str represents
int from_binary(string bit_str){
    long i, index = 0, times = 1, new_c;
    char letter = bit_str[0];
    int inter;
    string c;
    while ( letter != '1' && index <5){
        index++ ;
        letter = bit_str[index]; //to check where the 1 start in the 5_bit binary
    }
    for ( i = index; i < bit_str.length(); i++){
        c = bit_str[i];
        if (times == 1){
            inter = 1;
            times ++;
        }
        else{
            new_c = stol(c); //convert string to long
            inter = inter * 2 +new_c;
        }

    }
    return inter;
}
bool check_message(string original_text, string secret_message){
    long i, s, count_original = 0, count_secret = 0;
    bool statement;
    for ( i = 0; i < original_text.length(); i++){
        if (isalpha(original_text[i])){ //to check the original test is alpha
            count_original ++ ;
        }
    }
    for ( s = 0; s < secret_message.length(); s ++){
        if (isalpha(secret_message[s])){ //to check the secret message is alpha
            count_secret ++;
        }
    }
    if (count_original >= (count_secret * 5)){ //to check does original message has enough room
        statement = true;
    }
    else{
        statement = false;
    }
    return statement;
}

string encode(string original_text, string secret_message){
    string lower_original, lower_secret, message = "", binary,secret_binary="";
    long i , index, count_bit = 0, index_secret = 0;
    char c;
    lower_original = lower_case(original_text); //convert to lower case
    lower_secret = lower_case(secret_message);//onvert to lower case
    if (check_message(lower_original , lower_secret) == false){
        message = "error"; //if original does not have enought space, return error
    }
    else{
        for ( index = 0 ; index < lower_secret.length(); index++){
            binary = to_binary(lower_secret[index]);
            secret_binary += binary;
        }
        for ( i = 0; i < lower_original.length(); i++){
            c = lower_original[i];
            if (isalpha(c)){
                if (index_secret < secret_binary.length()){
                if (secret_binary[index_secret] == '1'){
                    message+=toupper(c);
                    index_secret ++;
                }
                else {
                    message += c;
                    index_secret ++;
                }
                }
                else{
                    message +=c;
                }
            }
            else{
                message += c;
            }
        }
    }
    return message;
}

string decode(string to_decode){
    long i, inter;
    string binary = "", message;
    string secret_message;
    for ( i = 0; i < to_decode.length(); i++){
        if (isalpha(to_decode[i])){
            if (isupper(to_decode[i])){
                binary += '1';
            }
            else{
                binary += '0';
            }
        }
        if ( binary.length() % 5 == 0 && binary != ""){
            inter = from_binary(binary);
            binary = "";
            if (inter > 27 || inter < 0){
                secret_message = "a";
            }
            if (inter == 27){
                secret_message = " ";
            }
            if (inter > 0 && inter <27 && inter != 27){
                secret_message = inter +'a';
            }

            message +=secret_message;
        }

    }
    return message;
}
int main (){
  char ch;
  string line;
  string bin_string;

  getline(cin, line);
  ch = line[0];
  bin_string = to_binary(ch);
  cout << bin_string << endl;
  cout << from_binary(bin_string) << endl;

  getline(cin,line);
  cout << lower_case(line) << endl;

  string text, message;
  string encoded, decoded;
  getline (cin, text);
  getline (cin, message);

  encoded = encode(text, message);
  cout << encoded << endl;
  if (encoded != "error"){
    decoded = decode(encoded);
    cout << decoded << endl;
  }
  else
    cout << "" << endl;

}
