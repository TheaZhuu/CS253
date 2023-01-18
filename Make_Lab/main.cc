#include <iostream>

using namespace std;

#include "bar.h"   

// This code illustrates several special predefined values.
// They each begin & end with double underscores.
//
// __func__ is the name of the current function.
// __FILE__ is the name of this source file.
// __LINE__ is the number of current line in the source file.

int main() {
    cout << "Hi from " << __func__ << " at " __FILE__ ":" << __LINE__ << '\n';
    bar();
    return 0;
}
