/*
Zehua Li
Project 8
section 03
2016-11-6
proj08.cpp

commit: Given the initial dem of grid, and the position of the goal.
Given the input the positon and the direction of the initial bot, and the
commend the bot should follow.Based on the commend, caculate the final position
of the bot and print it out.
*/
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

// Class grid
class Grid{
private:
    size_t dim_;   // data member of the grid
    size_t goal_x_;   // data member of the grid
    size_t goal_y_;    // data member of the grid
public:
    Grid()=default; //set the default of the class Grid
    Grid(size_t, size_t, size_t);
    friend class Bot;
};
//Constructors of the Grid class
Grid::Grid(size_t dim, size_t x, size_t y){
    dim_ = dim;
    goal_x_ = x;
    goal_y_ = y;
}

//Class bot
class Bot{
private:
    size_t x_;   //data member of the Bot class
    size_t y_;      //data member of the Bot class
    char dir_;      //data member of the Bot class
    string commend_;        //data member of the Bot class
    Grid grid_;     //data member of the Bot class
    long index_ = 0;        //data member of the Bot class

public:
    Bot()=default; //set te default of the Bot class
    Bot(size_t, size_t, char, string , Grid&);
    void forward();
    void back();
    void left();
    void right();
    void execute_command();
    bool at_goal();
    friend ostream& operator<<(ostream&,Bot&);
};
//Constructors of the Bot class
Bot::Bot(size_t x, size_t y, char dir, string commend, Grid& g){
    x_ = x;
    y_ = y;
    dir_ = dir;
    commend_ = commend;
    grid_ = g;
}

// let the bot go forward
void Bot::forward(){
    if ( dir_ == 'n'){ //check the direction of the bot
        if (y_ < (grid_.dim_ - 1)){ //check if the bot is hitting the wall
            y_ +=1;
        }
    }
    if ( dir_ == 's'){
        if (y_ > 0){
            y_ -=1;
        }
    }
    if ( dir_ == 'w'){
        if (x_ > 0){
            x_ -=1;
        }
    }
    if ( dir_ == 'e'){
        if ( x_ < (grid_.dim_ - 1)){
            x_ += 1;
        }
    }
}

//let the bot go backward no turning the direction
void Bot::back(){
    if ( dir_ == 'n'){ //check the direction of the bot
        if ( y_ > 0){  // check if the bot is hitting the wall
            y_ -=1;
        }
    }
    if ( dir_ == 's'){
        if ( y_ < (grid_.dim_ - 1)){
            y_ += 1;
        }
    }
    if ( dir_ == 'w'){
        if ( x_ > 0){
            x_ +=1;
        }
    }
    if ( dir_ == 'e'){
        if (x_ < (grid_.dim_ -1 )){
            x_ -= 1;
        }
    }
}

//let the bot turning the direction
void Bot::left(){
    if ( dir_ == 'n'){ //check the direction of the bot
        dir_ = 'w';
    }
    else if ( dir_ == 's'){
        dir_ = 'e';
    }
    else if ( dir_ == 'w'){
        dir_ = 's';
    }
    else {
        dir_ = 'n';
    }
}

//let the bot turning the right
void Bot::right(){
    if ( dir_ == 'n'){  //check the direction of the bot
        dir_ = 'e'; //change the direction of the bot
    }
    else if ( dir_ == 's'){
        dir_ = 'w';
    }
    else if ( dir_ == 'w'){
        dir_ = 'n';
    }
    else {
        dir_ = 's';
    }
}

//execute the command
void Bot::execute_command(){
    if ( index_ < commend_.length()){ //check if the we run out of command
        if (commend_[index_] == 'f'){
            this -> forward();
        }
        else if ( commend_[index_] == 'b'){
            this -> back();
        }
        else if ( commend_[index_] == 'l'){
            this -> left();
        }
        else {
            this -> right();
        }
        index_ ++;
    }
    else{
        index_ = 0; //if we run out of command, strat the command at the beginning
        if (commend_[index_] == 'f'){
            this -> forward();
        }
        else if ( commend_[index_] == 'b'){
            this -> back();
        }
        else if ( commend_[index_] == 'l'){
            this -> left();
        }
        else {
            this -> right();
        }
        index_ ++;
    }
}

//check if the bot find the goal
bool Bot::at_goal(){
//if the bot's position is equal to the goal's position return true
    if ( x_ == grid_.goal_x_ && y_ == grid_.goal_y_){
        return true;
    }
    else{
        return false;
    }
}

//cout the b
ostream& operator<<(ostream& out, Bot& bot){
    //put all output into the out and return the out
    out <<'('<< bot.x_ <<','<<bot.y_<<')'<<" facing:"<<bot.dir_;
        return out;
}


int main(){
    cout << boolalpha;
    size_t dim, goal_x, goal_y;
    cin >> dim >> goal_x >> goal_y;

    size_t bot_x, bot_y;
    char bot_dir;
    string command_str;
    cin >> bot_x >> bot_y >> bot_dir >> command_str;

    long limit;
    cin >> limit; // if the command hit the limit, the program stop

    Grid g(dim, goal_x, goal_y);
    Bot b(bot_x, bot_y, bot_dir, command_str ,g);
    int cnt=0;
    // check if the bot find the goal or it hit the limit step
    while(!b.at_goal() && cnt < limit){
    //cout << b << endl;
        b.execute_command();
        ++cnt;
    }
    cout << b << endl;
    cout << b.at_goal();
}
