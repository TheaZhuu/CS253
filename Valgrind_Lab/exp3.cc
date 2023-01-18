#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int x = 0;

    if (time(nullptr) == 42)	// no time machine available
	x = 42;			// so this will not happen

    if (x==0)
        cout << "x is zero\n";
    else
        cout << "x is non-zero\n";

    return 0;
}
