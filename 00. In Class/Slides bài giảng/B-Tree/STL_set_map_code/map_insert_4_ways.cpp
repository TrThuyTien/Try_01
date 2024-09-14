#include <iostream>
#include <map>
#include <utility>     // using pair
using namespace std;

int main() {
    std::map<char, int> mp, mp1;
    mp.insert(std::pair<char,int>('a',1));
    mp.insert(std::pair<char,int>('b',2));
    mp.insert({'c',3});
    mp.insert({'d',4});
    mp['g']= 7;

    mp.insert(mp.find('d'), {'e', 5});
    mp1.insert(mp.begin(), mp.find('d'));


    cout << "mp:\nKEY\tELEMENT\n";
    for (std::map<char, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr)
        cout << itr->first << '\t' << itr->second << endl;
    cout << endl << endl;

    cout << "mp1:\nKEY\tELEMENT\n";
    for (std::map<char, int>::iterator itr = mp1.begin(); itr != mp1.end(); ++itr)
        cout << itr->first << '\t' << itr->second << endl;
    cout << endl << endl;

    return 0;
}
