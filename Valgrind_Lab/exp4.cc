#include <iostream>
#include <ctime>
using namespace std;

void foo(int x) {
    if (x < 10)
        cout << "x is less than 10\n";
}

int main() {
    int y = 0;
    const auto now = time(nullptr);	// How many seconds since 1970 started?
    if (now == 0)			// False, unless you have a TARDIS.
	y = 99;
    foo(y);
    return 0;
}
