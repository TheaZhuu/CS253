#include "Directory.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

// The directory iterator pre-fetches the name.  That is, readdir()
// is called when you first create the iterator, and upon ++.
//
// An end() iterator is designated by a null pointer for its DIR *.
// When readdir() fails, we set our pointer to null.

DirectoryIterator::DirectoryIterator(DIR *dp_arg,string s) : dp(dp_arg),str(s) {
    ++*this;			// get that first entry
    // cout << str;
}

// Get the next entry in the directory (that we like) and
// put it in the member variable name.

DirectoryIterator &DirectoryIterator::operator++() {	// pre-increment
    while (auto p = readdir(dp)) {	// Read a directory entry.
	    name = p->d_name;		// C-string ⇒ C++ string
//Fix #2
	//if (name == ".")		// Stupid entry for current directory?
        if(!wanted()){
	        continue;			// Nobody wants that.
        }
	//if (name == "..")		// Stupid entry for parent directory?
        else{
	    // continue;			// Nobody wants that.
            return *this;			// Everything else, I like!
        }
    }
    dp = nullptr;			// readdir failed; don’t try again.
    return *this;
}
//Fix #2
bool DirectoryIterator::wanted(){
    if(name =="." ||name ==".."){
        return false; 
    }
    if(str !=""){
        if(strstr(name.c_str(),str.c_str())){  //Fix #3
            return true;  
        } 
    }       
    return strstr(name.c_str(),str.c_str());

}



string DirectoryIterator::operator*() const {
    return name;			// Fetched in a previous ++.
}

bool DirectoryIterator::operator!=(const DirectoryIterator &rhs) const {
    return dp != rhs.dp;
}



//////////////// Directory methods
//Fix #1
Directory::Directory(const char dirname[]) : dp(opendir(dirname)) { 
        if(!dp){
            std::stringstream ss;
            ss <<"runtime error. The directory " << dirname << " doesn't exist." << '\n';
            throw std::runtime_error(ss.str());
        }
}
//Fix #1
Directory::Directory(const char dirname[],std::string s) : dp(opendir(dirname)),str(s) { 
    // str = s;
    if(!dp){
        std::stringstream ss;
        ss <<"runtime error. The directory "<< dirname <<" doesn't exist. "<< '\n';
        throw std::runtime_error(ss.str());
    }
}
Directory::~Directory() {
    if (dp)				// Only if opendir() succeeded:
	closedir(dp);			//   should we close it.
}

Directory::iterator Directory::begin() const {
    // cout << str;
    return iterator(dp,str);
}

Directory::iterator Directory::end() const {
    return iterator();
}
