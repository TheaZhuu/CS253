#include <iostream>
#include <sstream>

using namespace std;

class Number {
  public:
    Number() = default;
    Number(const Number &) = default;
    Number(int v) : value(v) {}
    Number& operator=(int n) { value = n; return *this; }
    operator int() const { return value; }
  private:
    int value = 0;			// default value unless otherwise given
};

istream& operator>>(istream &is, Number &rhs) {
    int n;
    is >> n;
    if(is.fail()){
      string str;
      is.clear();//get rid of error message
      is >> str;
      switch(str[0]){
        case 'o':
          if(str == "one"){
            rhs = 1;
            break;
          }
          else{
            break;
          }
        case 't':
          if(str == "two"){
            rhs = 2;
            break;
          }
          else if(str == "three"){
            rhs = 3;
            break;
          }
          else{
            break;
          }
        case 'f':

          if(str == "four"){
            rhs = 4;
            break;
          }
          else if(str == "five"){
            rhs = 5;
            break;
          }
          else{
            break;
          }
      }
      
    }
    else{
      rhs = n;
    }


    return is;
}


int main() {
    Number n = 666;
    istringstream ss("12 34 three 789 five");

    while (ss >> n)
	cout << n << ' ';
    cout << '\n';
}
