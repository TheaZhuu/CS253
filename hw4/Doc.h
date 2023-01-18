#include <iostream>
#include <fstream>
#include <string>
#include <vector>
struct Line {
    size_t indent;
    std::string data;
};

class Doc{

 public:
    Doc()=default;  //default construction
    Doc(const Doc& r); //copy constructor
    Doc& operator = (const Doc&)= default; //assignment operator 
    ~Doc(); // destructor
    [[nodiscard]] size_t size() const; //.size()
    [[nodiscard]] bool empty()const; //.empty()
    Doc operator + (const Doc & d) const;  // Doc + Doc
    Doc operator + (const std :: string line) const; //Doc + string
    Doc operator += (const Doc & d) ;  // Doc += Doc
    Doc operator += (const std::string str); //Doc += string
    explicit operator bool() const;//Doc in a boolean context 
    [[nodiscard]]const Line & operator [] (size_t) const;//Doc[size_t]
    void clear();
    void addLine(Line);
    std::vector<Line> getLines()const;
    

private: 
  std::vector<Line> lines;

};
    std :: istream & operator >>(std::istream & file, Doc &);
    std :: ostream & operator <<(std::ostream &os, const Doc &d);
    Doc operator + (const std::string &, const Doc &); // stiring + Doc


