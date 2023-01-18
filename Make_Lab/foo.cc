#include "foo.h"    // ensure that foo.h’s declaration of foo() matches ours.
#include <iostream>

using namespace std;

void foo() {
    // Holy smokes--the next line contains both predefined identifiers,
    // AND adjacent string constant pasting!
    // Note the lack of << where you might otherwise expect them,
    // because __FILE__ expands to the C-style string constant "foo.cc",
    // and adjacent string constants are pasted together.
    // __LINE__, on the other hand, expands to the integer 14.

    cout << "Hi from " << __func__ << " at " __FILE__ ":" << __LINE__ << '\n';
}
