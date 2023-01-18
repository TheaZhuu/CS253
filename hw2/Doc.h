#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class Doc{
  //Access specifier 
 public:
  //default constructor
  Doc()=default;
  //copy constructor
  Doc(const Doc& r);
  //assignment operator
  Doc& operator = (const Doc&)= default;
  //Destructor
  ~Doc();
  //Doc(path)
 Doc(std::string path);
  //Doc(istream)
 Doc(std::istream &stream);
  //.read(istream)
 void read(std::istream &file);
  //.read(path) 
 void read(std::string path);
  //.write(path)
 void write(std::string path) const;
  //.write(ostream)
 void write(std::ostream &out) const;
  //.size()
  [[nodiscard]] size_t size() const;
  //add(string)
 void add(std::string line);
  //.empty() 
  [[nodiscard]] bool empty()const;
  //.indent(size_t)
  [[nodiscard]] size_t indent(size_t linenumber) const;   //return lines[linenumber].indent;
  //.data(size_t)
  [[nodiscard]]  std::string data(size_t linenumber) const;

private:
  struct Line {
    size_t indent;
    std::string data;
  };
  std::vector<Line> lines;
  
};




// read from istream
// already given istream as argument
// we can go line by line through it
// call .add


// read from path
// ifstream("/test.txt")
// now I can call read from istream
