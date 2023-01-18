#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

int main() {
    // First, some stupid code just to introduce an error:
    vector<int> v = {2,42,6520,253,1003};
    cout << "My favorite number is " << v[3] << '\n';

    string filename = "/etc/resolv.conf";
    ifstream in(filename);
    assert(in.is_open());

    for (string s; getline(in, s); ) {
        string prefix = s.substr(0,6);
        if (prefix == "search")
            cout << s << '\n';
    }

    return 0;
}