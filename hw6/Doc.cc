#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <vector>
#include "Doc.h"
#include <cstring>
#include <sstream>
#include<algorithm>


using namespace std;

Doc::Doc(const Doc& r){
  this->lines = r.lines;
}
Doc::~Doc(){}

// .size()
size_t Doc::size() const{
  size_t length = 0;
  for(Line l: lines)
    length ++;
  return length;
  //return lines.size();
}
void Doc::clear(){
  lines.clear();
}

//.empty() 
bool Doc::empty()const {
  return lines.empty();
}
std::vector<Line> Doc::getLines()const{
  return lines;

}
 void Doc::addLine(Line l){
  lines.push_back(l);
 }

std::istream & operator >>(std::istream & file, Doc &d){
  d.clear();
  string str;
  while(getline(file,str)){
    for (size_t i = 0; i < str.length();i++){
      if(str[i] == '\t'){
//throw a runtime_error 
        throw std::runtime_error("A tab character is read.");
      }
    }
    while(str.back()==' ' || str.back() =='\r'){
      str.pop_back();
    }
    // cout << "str----: " << str <<'\n';
    if(!str.empty()){   
      size_t indent = 0;
      string data;
      for(size_t i = 0; i<str.length(); i++){
        // if(str[i] == ' ' && !isalpha(str[i])){
        if(str[i] == ' '){
            indent++;
        }
        else{
         break;
        }
      }
      data = str.substr(indent);
    d.addLine({indent, data});
    }
    
  }
  return file;
}
std :: ostream& operator <<(std::ostream &os, const Doc &d){
  std::vector<Line> t = d.getLines();
  for(Line l : t){
    os <<std::string(static_cast<int>(l.indent),' ')<< l.data <<'\n';
  }
  return os;
}

Doc Doc::operator + (const Doc & d) const{ // Doc + Doc
  Doc doc;
  for (Line l: this->lines){
    doc.lines.push_back(l);
  }
  for (Line l: d.lines){
    doc.lines.push_back(l);
  }
  return doc;

}
Doc Doc::operator+(const string line)const{ //Doc + string
    Doc result = *this;
    return result += line;

}

Doc Doc::operator += (const Doc & d){ // Doc += Doc
    
    Doc doc = *this;
    *this = doc + d;
    return *this;

}
Doc Doc ::operator += (const string line) { //Doc += string
    auto n = line.find_first_not_of(' ');
    if (n == line.npos){
      n = 0;
    }
    lines.push_back({n, line.substr(n)});
    return *this;
}

const Line & Doc::operator[](size_t n)const{//Doc[size_t]

  //check if out of range and return n and lines.size()
    if (n >=lines.size()){
      // throw std::out_of_range (string("The bad line number is : ")+ std::to_string(static_cast<int>(n)));
      std::stringstream ss;
      ss<<"The bad line number is: "<< n <<". The object line number: "<< lines.size() << "."<<'\n';
      throw std::out_of_range (ss.str());
    }
  return this->lines[n];
} 
Doc operator + (const std::string &line, const Doc &d){ // string + Doc
  Doc doc;
  doc +=line;
  doc = doc + d;
  return doc;
}
Doc::operator bool()const{
  if(!empty()){
    return true;
  }
  return false;
}

// the below is hw6
void Doc::erase(size_t start){
  if(lines.size()< start){
    std::stringstream ss;
    ss<< "Bad number of start " << start <<". The object line number: "<< lines.size() <<"." <<'\n';
    throw out_of_range(ss.str());
  }
  lines.erase(lines.begin()+start, lines.end());
}
// d -> [one, two, three]
// d.erase(1);
// d.erase(4);

void Doc::erase(size_t start,size_t count){
    if(lines.size()< start){
    std::stringstream ss;
    ss<< "Bad number of start " << start <<" and bad number of count "<< count <<". The object line number: "<< lines.size() <<"." <<'\n';
    throw out_of_range(ss.str());
  }
 lines.erase(lines.begin()+start,lines.begin()+start+count);

}
void Doc::append(const Doc &d){
  for(Line l: d.lines){
    lines.push_back(l);
  }
}
void Doc::insert(const Doc &d, size_t start){
    if(lines.size()< start){
    std::stringstream ss;
    ss<< "Bad number of start " << start <<". The object line number: "<< lines.size() <<"." <<'\n';
    throw out_of_range(ss.str());
  }
    lines.insert(lines.begin()+start,d.lines.begin(),d.lines.end());
}
 void Doc::replace(const Doc &d, size_t start){
    if(lines.size()< start){
    std::stringstream ss;
    ss<< "Bad number of start " << start <<". The object line number: "<< lines.size() <<"." <<'\n';
    throw out_of_range(ss.str());
  }
   lines.erase(lines.begin()+start,lines.end());
   lines.insert(lines.begin()+start,d.lines.begin(),d.lines.end());
 }


void Doc::replace(const Doc &d, size_t start,size_t count){
    if(lines.size()< start){
    std::stringstream ss;
    ss<< "Bad number of start " << start <<" and bad number of count "<< count <<". The object line number: "<< lines.size() <<"." <<'\n';
    throw out_of_range(ss.str());
  }
    lines.erase(lines.begin()+start,lines.begin()+start+count);
    lines.insert(lines.begin()+start,d.lines.begin(),d.lines.end());


}
