#include "hset.h"
#include <iomanip>			// for setw()
#include <iostream>			// for cout
#include <time.h>			// for time() (duh)

using namespace std;

int main() {
    cout << setprecision(4);		// Display four significant digits

    hset<int> h;
    for (int j=0; j<20; j++)		// Put some numbers into the set
	h.insert(j*17 % 100);		// Each number is [0,100).
    h.dump();				// Let’s see what’s in there

    cout << "size=" << h.size() << ':';
    for (auto v : h)
	cout << ' ' << v;
    cout << '\n';

    hset<string> hs;
    for (auto s : {"alpha", "beta", "gamma", "delta", "epsilon", "zeta", "eta"})
	hs.insert(s);
    hs.dump();

    cout << "size=" << hs.size();
    for (auto v : hs)
	cout << ' ' << v;
    cout << '\n';

// ----------Exercise 3 -----------
    hset<double> hd;
    for (auto s : {1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9})
	hd.insert(s);
    hd.dump();

    cout << "size=" << hd.size();
    for (auto v : hd)
	cout << ' ' << v;
    cout << '\n';

}
