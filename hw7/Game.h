#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Game{

public: 
    Game()=default;//default construction
    Game(const Game&g);//copy constructor
    Game& operator = (const Game&)= default; //assignment operator 
    ~Game(); // destructor
    void set_length(size_t);// set_length(size_t)
    // void set_length(size_t l = 5); //defalut length of 5

    void add_dict(const std::string& path);//add_dict(string path)
    void set_good(const std::string& gd);//set_good(string)
    void set_wrong(const std::string& wrg);//set_wrong(string)
    void set_bad(const std::string& bd);//.set_bad(string)
    const std::string& select_target(); //jia qian jia hou const ??? const select_target()
    [[nodiscard]] bool contains(const std::string& word)const; //contains(string word)
    [[nodiscard]] std::string feedback(const std::string& guess)const;//feedback(string guess)

    void set_wanted(bool (*w)(std::string str));   // Game::set_wanted(wanted)
    class iterator;
    iterator begin() const; // Game::begin()
    iterator end() const; //Game::end()


private: 
    std::vector<std::string> v;
    std::string target = "";
    size_t word_length = 5;
    std::string good  = "=";
    std::string wrong = "-";
    std::string bad = " ";
    static bool all_wanted (std::string);
    bool (*wanted)(std::string) = all_wanted;
};

class Game::iterator{
public:
    iterator()=default;
    iterator(const Game *,size_t);
    iterator& operator ++();
    [[nodiscard]] iterator operator ++(int);
    [[nodiscard]] std::string operator *()const;
    [[nodiscard]] bool operator ==(const iterator &)const;
    [[nodiscard]] bool operator !=(const iterator &)const;

private:
    const Game *git;
    size_t index;
};


#endif /* GAME_INCLUDED */