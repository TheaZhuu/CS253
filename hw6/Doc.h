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

// the below is hw6
    void erase(size_t start);
    void erase(size_t start,size_t count);
    void append(const Doc &d);
    void insert(const Doc &d, size_t start);
    void replace(const Doc &d, size_t start);
    void replace(const Doc &d, size_t start,size_t count);
    
    template<typename T>
    void append(T iter1, T iter2){   
        insert(iter1, iter2, size());   
    }
    template<typename T>
    void insert (T iter1, T iter2, size_t start){
        Doc d;
        for (auto it = iter1; it!=iter2; ++it){
            d += *it;
        }
        insert (d,start);

    }
    template<typename T>
    void replace(T iter1, T iter2, size_t start){
        erase(start);
        insert(iter1,iter2,start);

    }
    template<typename T>
    void replace(T iter1, T iter2, size_t start,size_t count){
        erase(start,count);
        insert(iter1, iter2,start);

    }


    // iterator begin()const;
    // iterator end()const;
private: 
  std::vector<Line> lines;

};

    std :: istream & operator >>(std::istream & file, Doc &);
    std :: ostream & operator <<(std::ostream &os, const Doc &d);
    Doc operator + (const std::string &, const Doc &); // stiring + Doc



