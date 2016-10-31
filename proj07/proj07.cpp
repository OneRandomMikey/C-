/*Zehua Li
Project 7
section 03
2016-10-31
proj07.cpp

commit: text processing, go throught text and find the unigrams and bigrams.
insert unigrams and bigrams into different maps and caculate values.
*/

#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string; using std::to_string; using std::tolower; using std::isalpha;
using std::getline;
#include<sstream>
using std::stringstream;
#include<vector>
using std::vector;
#include<map>
using std::map;

//Takes a single string and convert it to lower case. also remove any
// non-alphabetic character from both the beginning and end of the argument
string process_word(string s){
    string lower = "";
    char to_lower;
    int i;
    for ( i = 0 ; i < s.length() ; i++ ){ //go through a string
        char c = s[i];
        if (i == 0){
            if (isalpha(c)){ //check if the first char is alpha
                to_lower = tolower(c); //convert each char to lower case
                lower += to_lower;
            }
        }
        else if( i == s.length() - 1){
            if ( isalpha(c)){  //check if the last char is alpha
                to_lower = tolower(c); // convert each char to lower case
                lower += to_lower;
            }
        }
        else {
            to_lower = tolower(c); // convert each char to lower case
            lower += to_lower;
        }
    }
    return lower;
}

//process each word and put each word into a vector for unigrams's key
void process_line(string line, vector<string>& v){
    stringstream str(line);
    string word;
    while ( str >> word){
        word = process_word(word); // convert word to lower case
        v.push_back(word); //insert word into a vector
    }
}

//process each word and put each word into a vector for bigrams's key
void process_line_vector(string line, vector<string>& v2){
    stringstream str_1(line);
    string word , word_str, pair_string = "";
    long i = 1;
    while ( str_1 >> word){
        word = process_word(word);
        if ( i == 1){ // if it is first word of the line, word_str = word
            word_str = word;
            i++;
        }
        else{
            map<string ,long> str{{word_str , 0},{word , 0}}; //create a map for bigrams's key
            word_str = word;
            for (auto element:str){
                if (pair_string.empty()){ //check if the string is empty
                    pair_string += element.first;
                }
                else{
                    pair_string = pair_string +" "+element.first;
                }
            }
            v2.push_back(pair_string);
            pair_string = "";
        }
    }
}

// make two maps for unigrams and bigrams
void read_file(map<string,long>& bi, map<string,long>& uni){
    string line;
    vector <string> v; //vector for unigrams
    vector <string> v2; //vector for bigrams
    while(getline(cin , line)){
        process_line(line , v); //proces a line create a vector for unigram's key
        process_line_vector(line , v2);//process a line create a vector for bigram's key
    }
    for (auto element : v){
        uni[element]++; //insert each vector element into unigram map
    }
    for (auto element2 : v2){
        bi[element2]++; //insert each vector element into bigram map
    }
}

//cout 5 values whichs are required for the project
string report_counts(const map<string,long>& bi,const map<string,long>& uni,
    string word1, string word2){
    word1 = process_word(word1);
    word2 = process_word(word2);
    string bigram_key = word1 + " " + word2, bigram_key2 = word2 + " "+word1, output="";
    long count_bigram, count_word1_minus_word12, count_word2_minus_word12,
        count_bi,count_uni;
    if (bi.count(bigram_key) > bi.count(bigram_key2)){
        count_bigram = bi.find(bigram_key)->second; //caculate the count of bigrams
    }
    else if ( bi.count(bigram_key) < bi.count(bigram_key2)){
        count_bigram = bi.find(bigram_key2)->second;//caculate the count of bigrams
    }
    else{
        count_bigram = 0;
    }

    count_word1_minus_word12 = uni.find(word1)->second - count_bigram;//caculate the count of count_word1 - word12
    count_word2_minus_word12 = uni.find(word2)->second - count_bigram;//caculate the count of count_word2-word12
    for (auto element : bi){
        count_bi ++;//caculate how many unigrams in map
    }
    for (auto element2: uni){
        count_uni ++;//caculate how many bigrams in map
    }
    output = to_string(count_bigram)+' '+to_string(count_word1_minus_word12)+' '+
        to_string(count_word2_minus_word12)+' '+to_string(count_bi)+' '+
        to_string(count_uni);
    return output;
}


int main (){
    map<string,long> bigrams;
    map<string, long> unigrams;
    string word1, word2, line;
    cin >> word1 >> word2; // get the two words
    getline(cin,line); // clear the \n at end of first line
    read_file(bigrams, unigrams); // read the lines and process
    cout << report_counts(bigrams, unigrams, word1, word2)<< endl;
}
