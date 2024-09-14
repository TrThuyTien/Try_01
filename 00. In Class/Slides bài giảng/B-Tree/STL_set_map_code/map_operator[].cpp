/*
map mp:
key     value
a       1
b       2
c       3
d       4
e       5
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
    std::map<char, int> mp;
    mp['a']= 1;
    mp['b']= 2;
    mp['c']= 3;
    mp['d']= 4;
    mp['e']= 5;
    cout << "map mp:\n\key\tvalue\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
        cout << itr->first << '\t' << (*itr).second << endl;
    cout << endl << endl;
    return 0;
}
