#include "Doc.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ofstream("data") << "\r \r  \n\n Peter  \n   Ray\r \n  Egon  \n \n\r\n";
    Doc d("data");
    assert(!d.empty());
    assert(d.size()==3);
    assert(d.indent(0) == 1);
    assert(d.indent(1) == 3);
    assert(d.indent(2) == 2);
    assert(d.data(0) == "Peter");
    assert(d.data(1) == "Ray");
    assert(d.data(2) == "Egon");

    d.add("   Winston     ");
    assert(d.size() == 4);
    assert(d.indent(3) == 3);
    assert(d.data(3) == "Winston     ");

    d.add("");
    assert(d.size() == 5);
    assert(d.indent(4) == 0);
    assert(d.data(4) == "");

    cout << "read(istream) test"<<endl;
    ifstream file("data");
    d.read(file);
    assert(!d.empty());
    assert(d.size()==3);
    assert(d.indent(0) == 1);
    assert(d.indent(1) == 3);
    assert(d.indent(2) == 2);
    assert(d.data(0) == "Peter");
    assert(d.data(1) == "Ray");
    assert(d.data(2) == "Egon");
    cout << "Done.\n";

    cout << "Doc(istream) test"<<endl;
    ifstream file1("data");
    Doc e(file1);
    assert(!e.empty());
    assert(e.size()==3);
    assert(e.indent(0) == 1);
    assert(e.indent(1) == 3);
    assert(e.indent(2) == 2);
    assert(e.data(0) == "Peter");
    assert(e.data(1) == "Ray");
    assert(e.data(2) == "Egon");
    cout << "Done.\n";

    cout << "indent test"<<endl;
    cout << e.indent(4);
    cout << "Done.\n";

    const Doc vacant;
    assert(vacant.empty() && vacant.size()==0);
    d = vacant;
    assert(d.empty() && d.size()==0);

    return 0;
}
