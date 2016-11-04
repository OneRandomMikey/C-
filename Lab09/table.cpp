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
    for ( long i = 0; i < height; i++){
        for (long h = 0; i < width; h++){
            w.push_back(width);
        }
        t_.push_back(w);
    }
}

void Table::fill_random(long lo, long hi, unsigned int seed){
    mt19937_64 reng(seed);
    uniform_int_distribution<long> dist(lo,hi);
    vector <long> w;
    for(long i = 0; i <= height_; i++){
        for(long h = 0; h < width_; h++){
            w.push_back(dist(reng));
        }
        t_.push_back(w);
    }
}

bool Table::set_value(unsigned int row_num, unsigned int col_num, long val){
    if (col_num < height_ && row_num < width_){
        t_[col_num][row_num] = val;
        return true;
    }
    else{
        return false;
    }
}

long Table::get_value (unsigned int row_num, unsigned int col_num) const{
    if (row_num < height_ && col_num < width_){
        return t_[col_num][row_num];
    }
    else{
        return std::numeric_limits<long>::lowest();
    }
}

ostream& operator<<(ostream& out, Table t){
    for(auto element : t.t_){
        for (auto el : element){
            out << el <<',';
        }
        out <<'\n';
    }
    return out;
}
