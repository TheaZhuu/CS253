#include <iostream>
#include <cstring>		// C-strings: for strcpy()
using namespace std;

int main() {
    char *greeting = new char[1024];
    strcpy(greeting, "Dear");
    delete [] greeting;
    cout << greeting << " Sir/Madam\n";
    return 0;
}
