#include "Date.h"
#include <fstream>	// ifstream
#include <string>	// string
#include <sstream>	// istringstream

using namespace std;

int main() {
    // Read & display some dates
    ifstream data("data");
    Date d;
    // Read each line, try to convert it to a date, complain if it fails.
    for (string s; getline(data, s); ) {
	istringstream iss(s);	// Initialize stream with string
	if (iss >> d)		// Try to convert to a date
	    cout << d << '\n';
	else
	    cerr << "Bad date \"" << s << "\"\n";
    }

    const Date a(2009,3,4);
    cout << a << '\n';		// Wed Mar 4 2009

    const Date b(a);
    cout << b << '\n';		// Wed Mar 4 2009

    Date c; c=a;
    cout << c << '\n';		// Wed Mar 4 2009

    c = c+1;
    cout << c << '\n';		// Thu Mar 5 2009
    c += 9;
    cout << c << '\n';		// Sat Mar 14 2009
    d = ++c;
    cout << c << '\n';		// Sun Mar 15 2009
    cout << d << '\n';		// Sun Mar 15 2009

    d = c++;
    cout << c << '\n';		// Mon Mar 16 2009
    cout << d << '\n';		// Sun Mar 15 2009

    Date e = d-1;
    cout << e << '\n';		// Sat Mar 14 2009
    d = e--;
    cout << d << '\n';		// Sat Mar 14 2009
    cout << e << '\n';		// Fri Mar 13 2009
    d = --e;
    cout << d << '\n';		// Thu Mar 12 2009
    cout << e << '\n';		// Thu Mar 12 2009
    e -= 5;
    cout << e << '\n';		// Sat Mar 7 2009
    e -= -2;
    cout << e << '\n';		// Mon Mar 9 2009
    cout << d-e << '\n';	// 3
    cout << e-d << '\n';	// -3

    // a==b, a<c
    cout << ((a==b) ? "== good\n" : "== bad\n");
    cout << ((a==c) ? "== bad\n"  : "== good\n");
    cout << ((a!=c) ? "!= good\n" : "!= bad\n");
    cout << ((a!=b) ? "!= bad\n"  : "!= good\n");
    cout << ((a<c)  ? "<  good\n" : "<  bad\n");
    cout << ((a<b)  ? "<  bad\n"  : "<  good\n");
    cout << ((c>a)  ? ">  good\n" : ">  bad\n");
    cout << ((b>a)  ? ">  bad\n"  : ">  good\n");
    cout << ((a<=b) ? "<= good\n" : "<= bad\n");
    cout << ((a<=c) ? "<= good\n" : "<= bad\n");
    cout << ((c<=a) ? "<= bad\n"  : "<= good\n");
    cout << ((a>=b) ? ">= good\n" : ">= bad\n");
    cout << ((c>=a) ? ">= good\n" : ">= bad\n");
    cout << ((a>=c) ? ">= bad\n"  : ">= good\n");

//7.Find the lines that contain #####. Those lines weren’t tested.
    Date z; z=a;// z = (2009,3,4)
    z.setday(15);// z = (2009,3,15)
    cout << z <<'\n';
    z.setmonth(6);// z = (2009,6,15)
    cout << z << '\n';
    z.setyear(2000);//// z = (2000,3,15)

    Date y; y = 1+y;
    cout << y << '\n';

    
    

   

    return 0;
}
