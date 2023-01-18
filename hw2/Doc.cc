#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <vector>
#include "Doc.h"

using namespace std;

//constructor

//Doc::Doc(){}
//Doc::Doc() = default;
//copy constructor
Doc::Doc(const Doc& r){
  //Copy all information from another object of the same class.
  //????????
  this->lines = r.lines;
}
//Destructor
Doc::~Doc(){}
//Doc(path)
Doc::Doc(std::string path){
  read(path);
  
}
//Doc(istream)
Doc::Doc(std::istream &file){
  this->read(file);

}

//.read(path)
void Doc::read(std::string path){
  
  ifstream file(path);
  this->read(file);

}
//read(istream)
void Doc::read(std::istream &file){
lines.clear();
string str;
while(getline(file,str)){
  for (size_t i = 0; i < str.length();i++){
    if(str[i] == '\t'){
      cerr <<  "A tab character ('\t') is read"<<'\n';
      exit(1);
    }
   }
  while(str.back()==' ' || str.back() =='\r'){
    str.pop_back();
  }
  if(!str.empty()){   
    size_t indent = 0;
    string data;
    for(size_t i = 0; i<str.length(); i++){
      if(str[i] == ' '){
           indent++;
      }
      else{
           data.push_back(str[i]);
      }
    }
    lines.push_back({indent, data});    
  }
  
}
}

  //.write(ostream)
void Doc::write(std::ostream &out) const{
  for(Line l : lines){
    out<<l.indent <<l.data<<"\n";
  }

}

//write(path)  
void Doc:: write(std::string path) const{
  ofstream file(path);
  for(Line l: lines){
    file<<l.indent<<l.data << '\n';
  }
  
}


  //.size()
size_t Doc::size() const{
  size_t length = 0;
  for(Line l: lines)
    length ++;
  
  return length;
  //return lines.size();
    
}
  //add(string)
void Doc::add(std::string line){
  size_t indent = 0;
  string data;
  for (size_t i = 0; i < line.length();i++){
    if(line[i] == '\t'){
      cerr <<  "A tab character ('\t') is read."<<'\n';
      exit(1);
    }
   }

  for(size_t i = 0; i<line.length(); i++){
    if(line[i] != ' '){
      break;
    }
    else{
      indent++;
    }
  }
  data = line.substr(indent,line.length());
  lines.push_back({indent, data});
    
}

  //.empty() 
bool Doc::empty()const {
  return lines.empty();
}

  //.indent(size_t)
size_t Doc::indent(size_t linenumber)const{
  if(linenumber >= size()){
    cerr << "The bad line number "<< linenumber << '\n';
    cerr << "The object has " <<size()<<" lines"<<'\n';
    exit(1);
  }
  return lines[linenumber].indent;
}
//.data(size_t)
string Doc::data(size_t linenumber)const{
   if(linenumber >= size()){
    cerr << "The bad line number "<< linenumber << '\n';
    cerr << "The object has " <<size()<<" lines"<<'\n';
    exit(1);
  } 
  return lines[linenumber].data;
}

  

