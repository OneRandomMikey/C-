#include <limits>
#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <random>
using std::mt19937_64; using std::uniform_int_distribution;
#include <string>
using std::string;
#include "table.h"

Table::Table (long width, long height, long val){
    vector<long> w;
    width_ = width;
    height_ = height;
    for ( long i = 1; i <= height; i++){
        for (long h = 1; i <= width; h++){
            w.push_back(width);
        }
        t_.push_back(height);
    }
}

void fill_random(long lo, long hi, unsigned int seed){
    mt19937_64 reng(seed);
    uniform_int_distribution<long> dist(lo,hi);
    vector <long> w;
    for(long i = 1; i <= height_; i++){
        for(long h = 1; h <= width_; h++){
            w.push_back(dist(reng))[]
        }
        t_.push_back(w);
    }
}

bool set_value(unsigned int row_num, unsigned int col_num, long val){
    if (row_num < height_ && col_num < width_){
        t_[rol_num][col_num] = val;
        return true;
    }
    else{
        return false;
    }
}

long get_value (unsigned int row_num, unsigned int col_num) const{
    if (row_num < height_ && col_num < width_){
        return t_[rol_num][col_num];
    }
    else{
        return std::numeric_limits<long>::lowest();
    }
}
//
// ostream& operator<<(ostream& out, Table t){
//
// }
//
// string helper( const vector<long> &){
//
// }
//
// void print_table(ostream&){
//
// }
