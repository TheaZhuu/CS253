#include <iostream>
#include <unistd.h>
#include <stdlib.h> 
#include <random>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <filesystem>
#include <sstream>
#include "Game.h"

using namespace std;
Game::Game(const Game& g){
    //copy all information from the object 
    v = std::vector<std::string>(g.v);
    target = g.target;
    word_length = g.word_length;
    good = g.good;
    wrong = g.wrong;
    bad = g.bad;
    wanted = g.wanted;
}
Game::~Game(){}

void Game::set_length(size_t l){//set_length(size_t)
    word_length = l;
}

void Game::add_dict(const std::string& path){//add_dict(string path)
    ifstream file(path);
    string str;
        if(file.fail()){
            //Throw a descriptive invalid_argument containing the path
            std::stringstream ss;
            ss<<" the file cannot be opened for reading from "<< path <<"."<<'\n';
            throw std::invalid_argument(ss.str());
        }
        while(getline(file,str)){
            if(str.length() == word_length){
                v.push_back(str);
            }
        }
        // for (auto s : v)
        // cout << "all: " << s << "\n";

}

void Game::set_good(const std::string& gd){//set_good(string)
    good = gd; 
}
void Game::set_wrong(const std::string& wrg){//set_wrong(string)
    wrong = wrg;
}
void Game::set_bad(const std::string& bd){ //.set_bad(string)
    bad = bd;
}
const string& Game::select_target(){ //select_target()
    //select length of word
    random_device rd;
    if (v.empty()){
        std::stringstream ss;
        ss<<" No words of the desired length are present in the accumulated dictionaries. The desired length is "<< word_length <<"."<<'\n';
        throw std::length_error (ss.str());
    }
    target = v[rd() % v.size()];
    return target;
}

bool Game::contains(const string& word)const{//contains(string word)
    return std::find(v.begin(),v.end(), word) != v.end();
}
string Game::feedback(const std::string& guess)const{ //feedback(string guess)
    string result;

    const int MAX_CHAR = 26;
    vector<bool> v1(MAX_CHAR,0);
    for(int i = 0; i<int(word_length);i++){
        v1[target[i]-'a'] = true; 
    }
    for(int i =0; i<int(word_length);i++){
      if(v1[guess[i]-'a']==true){
        if(guess[i]==target[i]){
            result += good;
        }
        else{
            result += wrong;
        }
      }
      else{
          result += bad;
      }
   }
   return result;
}

void Game::set_wanted(bool (*w)(std::string str)){
    wanted = w;
}
bool Game::all_wanted(std::string str){
    str = str;
    return true;
}

Game::iterator Game::begin() const{
    size_t i;
    for(i = 0;i<v.size();i++){
        if((*(wanted))(v[i]) == true){
            break;
        }
    }
    return {this, i};    
}

Game::iterator Game::end()const{
    return{this, v.size()};
}

Game::iterator::iterator(const Game *g, size_t s):git(g),index(s){}

Game::iterator& Game::iterator::operator ++(){

    if(index < git->v.size()){
        index++;
    }
    while((index<git->v.size()) && ((*(git->wanted))(git->v[index]) != true)){
        index++;
    }
    return *this;
    
    // for(;index<git->v.size();index++){
    //     if((*(git->wanted))(git->v[index]) == true){
    //         break;
    //     }
    // }
    // return *this;
}
Game::iterator Game::iterator::operator ++(int){
    auto temp = *this;
    ++*this;
    return temp;
}
string Game::iterator::operator *()const{
    return git->v[index];

}
bool Game::iterator::operator ==(const iterator &rhs)const{
    return index == rhs.index;

}
bool Game::iterator::operator !=(const iterator &rhs)const{
    return index != rhs.index; 
}











