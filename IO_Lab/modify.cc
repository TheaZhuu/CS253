#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// int main(int argc, char *argv[]) {
//     if (argc != 3) {
// 	cerr << "usage: " << argv[0] << " infile outfile\n";
// 	return 1;
//     }
//     ifstream in(argv[1]);
//     if (!in) {
// 	cerr << argv[0] << ": can't open " << argv[1] << '\n';
// 	return 2;
//     }
//     ofstream out(argv[2]);
//     if (!out) {
// 	cerr << argv[0] << ": can't open " << argv[2] << '\n';
// 	return 3;
//     }

//     for (string line; getline(in, line); ) {
// 	for (size_t pos=0; (pos=line.find("Trump", pos)) != line.npos; )
// 	    line.replace(pos, 5, "Biden");
// 	out << line << '\n';
//     }

//     return 0;
// }

int main(int argc, char* argv[]) {
    if(argc !=2){
        cerr << "usage: " << argv[0] << " infile outfile\n";
        return 1;
    }
    fstream in(argv[1]);
    if (!in) {
	cerr << argv[0] << ": can't open " << argv[1] << '\n';
	return 2;
    }
    size_t s = 0;
    string before = "Trump";
    for (string line; getline(in, line); ) {
        for (size_t pos=0; (pos=line.find(before, pos)) != line.npos; pos+= before.size()){

            auto save = in.tellg();
            in.seekp(-(line.size() +1 ) + pos, ios::cur);//
            in<<"Biden";
            in.seekp(save);
            
        }
        s = s+line.size();

    }
    return 0;
}


// Note that line.npos ≡ string::npos.
// It’s a static constant, part of the string class.
// It’s a number that means “Sorry, I couldn’t find that.”
