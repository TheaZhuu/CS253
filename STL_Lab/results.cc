#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
using namespace std;

int main()
{
  //1. Reads integer,until the user enters zero
  vector <int> a;
  int input;
  while(std::cin >> input && input != 0){
      a.push_back(input);
  }
  //2.Display the integers from the vector<int>, one per line.
  for(size_t i = 0; i<a.size(); i++){
    std::cout << a[i]<< '\n';
  }

  //3.Read "all the characters" from the file path into one big string.
  string filePath = "/etc/resolv.conf";      
  ifstream file(filePath);
  if(!file){
    cerr << "Can't open from" << filePath << "\n";
    exit(1);
  }
  char c;
  string str;
  while (file.get(c)){
    str.push_back(c);
  }
   // cout <<str<<'\n';
  

  //4.Copy all the characters from the string to a multiset<char>.
   multiset<char> ms(begin(str),end(str));
   // for(auto i: ms)
   //  cout<< i;

  //5.Copy all the characters from the multiset<char> to a set<char>
   set<char> s (begin(ms),end(ms));
   //  for(auto i: s)
   //    cout << i;

   //  cout <<'\n';
   //6.Display the .size() and characters from the string,set<char>, and mutiset<char>
     //display string
     cout << "string: size=" << str.size() <<" "<<str<<  '\n';
     //display set<char>
     cout << "set: size=" << s.size() << " ";
     for(auto i: s)
       cout << i;
     cout << '\n';

     //display mutiset<char>
     cout << "mutiset: size=" << ms.size() <<" ";
     for(auto i: ms)
        cout<< i;
     cout << '\n';

  //QUESTION 7: Explains why the sizes from the previous question aren't all the same.
  // answer: In case we want to get the size of a string, we will get the whole size of string. However, if we want to get the size of a set, the system will sort each character and get rid of duplicates, then give the size of a set. Mutiset is kind of similar to set, but it can have the same characters.
     

  return 0;
}
