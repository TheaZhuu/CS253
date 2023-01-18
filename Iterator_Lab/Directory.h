#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED

#include <dirent.h>
#include <string>

// Normally, I’d have DirectoryIterator be a nested class, Directory::iterator,
// to avoid namespace pollution.  However, this is easier to read.

class DirectoryIterator {
  public:
    DirectoryIterator() = default;
    DirectoryIterator(DIR *, std::string s);
    DirectoryIterator& operator++();
    std::string operator*() const;
    bool operator!=(const DirectoryIterator &) const;
  private:
    DIR *dp = nullptr;
    std::string name;
    std::string str;
    bool wanted();  //Fix #2
};

class Directory {
  public:
    typedef DirectoryIterator iterator;
    Directory() = delete;		// not really necessary
    Directory(const char dirname[]);
    Directory(const char dirname[],std::string s);   //Fix #1
    ~Directory();
    iterator begin() const;
    iterator end() const;
  private:
    DIR *dp;				// null if open failed
    std::string str;
};

#endif /* DIRECTORY_H_INCLUDED */
