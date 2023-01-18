#include <iostream>
#include "Directory.h"

using std::cout;

int main() {
    Directory dir(".");
    for (auto name : dir)
	cout << "Filename: " << name << '\n';
}