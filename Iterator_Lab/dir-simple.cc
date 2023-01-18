#include <iostream>	// for cout
#include <string>	// for "…"s
#include <dirent.h>	// for opendir, readdir, closedir

using namespace std;

int main() {
    DIR *dp = opendir(".");
    while (dirent *d = readdir(dp))
	if (d->d_name != "."s && d->d_name != ".."s)
	    cout << "Filename: " << d->d_name << '\n';
    closedir(dp);
    return 0;  
}
