#include "Doc.h"
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ofstream("dataTest80") << "\r \r  \n\n MinasItil  \n   Magic\r \nHeroes  \n Why not? \n\r\n   Last Thing to do is what?\n";
    Doc d;
    ifstream in("dataTest80");
    in >> d;

    cout << "d"<<d;
    assert(d.size() == 6);
    assert(d[0].indent == 1);
    assert(d[1].indent == 3);
    assert(d[2].indent == 0);
    assert(d[3].indent == 1);
    assert(d[4].indent == 0);
    assert(d[5].indent == 3);

    assert(d[0].data == "MinasItil");
    assert(d[1].data == "Magic");
    assert(d[2].data == "Heroes");
    assert(d[3].data == "Why not?");
    assert(d[4].data == "");
    assert(d[5].data == "Last Thing to do is what?");
    return 0;
}
