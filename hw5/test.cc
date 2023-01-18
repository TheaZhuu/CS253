#include "Game.h"
#include <iostream>

using namespace std;

int main(/* int argc, char *argv[] */) {
    //
    // Instead of hard-coding all the values here, you could
    // adapt your main() from HW3, with all the getopt() processing.
    // That way, you can easily test with 14570 different values,
    // different files, etc.
    // 
    Game g;
    g.set_good("✓"); g.set_wrong("~"); g.set_bad(".");
    g.set_length(5);
    g.add_dict("/dev/null");
    g.add_dict("words.txt");
    g.add_dict("/dev/null");
    const auto &target = g.select_target();
    cout << "Guess the " << target.size() << "-letter word.\n";

    for (int count=1; count<=6; ++count) {
        cout << "Guess #" << count << ": ";
        if (string guess; !getline(cin, guess))   // end game on end-of-file
            break;
        else if (guess.size() != target.size())
            cout << "“" << guess << "” isn’t length " << target.size() << ".\n";
        else if (!g.contains(guess))
            cout << "“" << guess << "” isn’t in any dictionary.\n";
        else {
            cout << "          " <<  g.feedback(guess) << "\n";
            if (guess == target) {
                cout << "You won!\n";
                return 0;
            }
        }
    }
    cout << "You lost, the word was “" << target << "”.\n";
    return 1;
}