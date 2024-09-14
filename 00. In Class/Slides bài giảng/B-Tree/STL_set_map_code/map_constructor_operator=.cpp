#include <iostream>
#include <map>
#include <utility>     // using pair
using namespace std;

int main() {
    std::map<char, int> mp;
    mp.insert(std::pair<char,int>('a',1));
    mp.insert(std::pair<char,int>('b',2));
    mp['g']= 17;

    // default constructor
    std::map<char, int> mp1(mp.begin(), mp.end());

    // copy constructor
    std::map<char, int> mp2(mp);

    std::map<char, int> mp3;
    mp3=mp;

    cout << "mp:\nKEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
        cout << itr->first << '\t' << itr->second << endl;
    cout << endl << endl;

    cout << "mp1:\nKEY\tELEMENT\n";
    for (auto itr = mp1.begin(); itr != mp1.end(); ++itr)
        cout << itr->first << '\t' << itr->second << endl;
    cout << endl << endl;

    cout << "mp2:\nKEY\tELEMENT\n";
    for (std::map<char, int>::iterator itr = mp2.begin(); itr != mp2.end(); ++itr)
        cout << itr->first << '\t' << itr->second << endl;

    cout << endl << endl;
    cout << "mp3:\nKEY\tELEMENT\n";
    for (std::map<char, int>::iterator itr = mp3.begin(); itr != mp3.end(); ++itr)
        cout << itr->first << '\t' << itr->second << endl;

    return 0;
}
    
