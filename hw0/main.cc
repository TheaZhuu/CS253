#include <iostream>
using namespace std;
#include <fstream>

int main() {
  // How many CU students does it take to change a light bulb?
  // cout << "No one doing it.\n"
  //    "Students are genius\n";
   std::ifstream f("mst3k");
   string s;
   getline(f,s);
   char c;
   f.get(c);
   cout << s<<'/' <<c<<'/'<<f.tellg();
  return 0;
}
