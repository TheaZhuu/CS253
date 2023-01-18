#include <iostream>
#include "ll.h"      

using namespace std;

int main() {
    LinkedList list;
    //Link link;

    for (bool done = false; !done; ) {
	unsigned int i;
	int option;

	cout << "Choose your operation:\n"
	     << "1. insert\t2. remove\t3. exit\t      4. print\t\n";

	cin >> option;

	switch (option) {
	    case 1:
		cout << "Enter the number to insert\n";
		cin >> i;
		list.insert(i);
		break;
	    case 2:
		if (list.remove(&i))
		    cout << "removed " << i << '\n';
		else
		    cout << "No numbers in the list\n";
		break;
	    case 3:
		done = true;
		break;
	     case 4:
	       list.print();
		//    cout << list;
	       break;
		 
	}
    }

    return 0;
}
