#include <iomanip>	// for right, setw
#include <iostream>
#include <map>
#include <cstring>
#include <string>

using namespace std;

template <typename T>
class BarGraph {
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
// Replace .dump() 
    // void dump() const {
    friend std::ostream & operator <<(std::ostream& os, const BarGraph<T>& b){
        for (const auto &val : b.data){
            os << right << setw(10) << val.first << ' '
            << string(val.second, '*') << '\n';
        }
            os << '\n';
        return os;
    }
  private:
    map<T, unsigned> data;
};

template <>
class BarGraph<bool> {
    unsigned false_count = 0, true_count = 0;
  public:
    void operator+=(bool datum) {
	    datum ? true_count++ : false_count++;
    }
// Replace .dump() 
    // void dump() const {
    friend ostream & operator <<(ostream& os, const BarGraph<bool>& b){
        os<< "     false " << string(b.false_count, '*') << "\n"
                "      true " << string(b.true_count,  '*') << "\n\n";
     return os;
    }
};
//Add BarGraph<char>
template <>
class BarGraph<char> {
   int array[256] = {0};
  public:
    void operator+=(char datum) {
        array[(int)datum] ++;
    }
// there are two ways to += string
    void operator+=(const char* datum_str){
        for(size_t i = 0; i<strlen(datum_str); i++){
            array[int(datum_str[i])]++;
        }
    }
    // void operator +=(const string datum_str){
    //     // cout << datum_str.size()<<'\n';
    //     for (size_t i =0; i<datum_str.length();i++){
    //         array[(int)datum_str.at(i)]++; 
    //     }
    // }
// Replace .dump() 
    // void dump() const {
    friend ostream & operator <<(ostream& os, const BarGraph<char>& b){
        for (int i = 0; i <255; i++){
            if(b.array[i] != 0){
            os << right << setw(10) <<char(i) << ' '
            << string(b.array[i], '*') << '\n';
            
            }
        }
        os << '\n';
     return os;
    }
};

int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    // alpha.dump();
    cout << alpha;

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    // beta.dump();
    cout << beta;

    BarGraph<bool> gamma;
    gamma += false;
    gamma += true;
    gamma += false;
    gamma += true;
    gamma += true;
    // gamma.dump();
    cout << gamma;

    BarGraph<char> delta;
    delta += 'G';
    delta += 'e';
    delta += 'o';
    delta += 'f';
    delta += 'f';
    delta += "Colorado";
    // delta.dump();
    cout << delta;

    // BarGraph<char> str;
    // str += "Colorado";
    // cout << str;

    // BarGraph<char> foo;
    // foo += "foo";
    // cout << foo;

    return 0;
}
