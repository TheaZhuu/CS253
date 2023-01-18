#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<short> pi = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4};
    string alpha="abcdefghijklmnopqrstuvwxyz", digits="0123456789";
    char cbuf[100] = { };	// contains 100 '\0' chars
    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    short powers[] = {1,2,4,8,16,32,64};
    int ibuf[100];		// contains unknown values

    cout << "Exercise 0\n";
    copy(alpha.begin(), alpha.end(), cbuf);
    cout << cbuf <<'\n';

    cout << "Exercise 1\n";
    reverse(begin(cbuf), begin(cbuf)+26);
    cout << cbuf <<'\n';

    cout << "Exercise 2\n";
    transform(primes.begin(),primes.end(),ibuf,[](int n){return n+1;});
    for (auto i =0;i<10;i++){
        cout << ibuf[i] << ' ';
    }
    cout <<'\n';

    cout << "Exercise 3\n";
    if(any_of(primes.begin(),primes.end(),[](int n)bool{return !(n%2);}))
        cout << "div2\n";
    if(any_of(primes.begin(),primes.end(),[](int n)bool{return !(n%42);}))
        cout << "div42\n";

    cout << "Exercise 4\n";
    auto it = find(begin(primes),end(primes),13);
    cout << *(++it)<<'\n'; 

    cout << "Exercise 5\n";
    auto ct = count(pi.begin(),pi.end(),3);
    cout << ct <<'\n';

    cout << "Exercise 6\n";
    auto cf = count_if(pi.begin(),pi.end(),[](int a){return a<5;});
    cout<< cf <<'\n';

    cout << "Exercise 7\n";
    auto m = max_element(pi.begin(),pi.end());
    cout << *m << '\n';

    cout << "Exercise 8\n";
    sort(pi.begin(),pi.end());
    for (auto val : pi)
        cout << val;
    cout <<'\n';

    cout << "Exercise 9\n";
    lower_bound(pi.begin(),pi.end(),7);
    auto index = binary_search(pi.begin(),pi.end(),7);
    cout << index << '\n';

    cout << "Exercise 10\n";
    auto si = set_intersection(pi.begin(),pi.end(),begin(powers),end(powers),ibuf);
    for(auto *it = &ibuf[0]; it !=si; it++){
        cout << *it;
    }
    cout << '\n';
}
