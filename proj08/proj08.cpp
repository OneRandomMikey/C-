#include<iostream>
using std::cout; using std::endl; using std::cin; using std::ostream;
using std::boolalpha;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<cassert>
#include<utility>
using std::pair;
#include<algorithm>
using std::find;
#include<map>
using std::map;
// if you need other includes, feel free

class Grid{
private:
    size_t dim_;
    size_t goal_x_;
    size_t goal_y_;
public:
    Grid()=default;
    Grid(size_t, size_t, size_t);
    size_t x() const{return goal_x_;}
    size_t y() const{return goal_y_;}
    size_t dim() const{return dim_;}
    friend class Bot;
};


// any Grid methods here

class Bot{
private:
    size_t x_;
    size_t y_;
    char dir_;
    string commend_;


public:
    Bot()=default;
    Bot(size_t, size_t, char, string, Grid&);
    void forward();
    void back();
    void left();
    void right();
    void execute_command();
    bool at_goal();
    friend ostream& operator<<(ostream&,Bot&);
};

void Bot::forward(){
    if ( dir_ == 'n'){
        y_ += 1;
    }
    if ( dir_ == 's'){
        y_ -= 1;
    }
    if ( dir_ == 'w'){
        x_ -= 1;
    }
    if ( dir_ == 'e'){
        x_ += 1;
    }
}

void Bot::back(){
    if ( dir_ == 'n'){
        y_ -= 1;
    }
    if ( dir_ == 's'){
        y_ += 1;
    }
    if ( dir_ == 'w'){
        x_ += 1;
    }
    if ( dir_ == 'e'){
        x_ -= 1;
    }
}

void Bot::left(){
    if ( dir_ == 'n'){
        dir_ = 'w';
    }
    if ( dir_ == 's'){
        dir_ = 'e';
    }
    if ( dir_ == 'w'){
        dir_ = 's';
    }
    if ( dir_ == 'e'){
        dir_ = 'n';
    }
}

void Bot::right(){
    if ( dir_ == 'n'){
        dir_ = 'e';
    }
    if ( dir_ == 's'){
        dir_ = 'w';
    }
    if ( dir_ == 'w'){
        dir_ = 'n';
    }
    if ( dir_ == 'e'){
        dir_ = 's';
    }
}

void Bot::execute_command(){
    if (commend_[0] == 'f'){
        this -> forward();
    }
    if ( commend_[0] == 'b'){
        this -> back();
    }
    if ( commend_[0] == '1'){
        this -> left();
    }
    if ( commend_[0] == 'r'){
        this -> right();
    }
    commend_.erase( 0 , 1);
}

bool Bot::at_goal(){
    size_t dim, x,y;
    Grid p(dim , x , y);
    if ( x_ == p.goal_x_ && y_ == p.goal_y_){
        return true;
    }
    else{
        return false;
    }
}

// any Bot methods here

int main(){
    cout << boolalpha;
    size_t dim, goal_x, goal_y;
    cin >> dim >> goal_x >> goal_y;

    size_t bot_x, bot_y;
    char bot_dir;
    string command_str;
    cin >> bot_x >> bot_y >> bot_dir >> command_str;

    long limit;
    cin >> limit;

    Grid g(dim, goal_x, goal_y);
    Bot b(bot_x, bot_y, bot_dir, command_str ,g);
    int cnt=0;

    while(!b.at_goal() && cnt < limit){
    //cout << b << endl;
        b.execute_command();
        ++cnt;
    }
    cout << b << endl;
    cout << b.at_goal();
}
