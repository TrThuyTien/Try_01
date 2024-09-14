#include <iostream>
#include <map>
#include <utility>     // using pair
using namespace std;

int main() {
    std::map<char, int> mp;
    mp['a']= 1; mp['b']= 2; mp['c']= 3; mp['d']= 4;
    mp['e']= 5; mp['f']= 6; mp['g']= 7;

    cout << "mp:\key\tvalue\n";
    for (std::map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it)
        cout << it->first << '\t' << it->second << endl;
    cout << endl << endl;

    // Xóa k sẽ gặp lỗi do k không có trong ds
    // mp.erase(mp.find('k'));
    mp.erase('a');
    mp.erase(mp.find('c'));
    mp.erase(mp.begin(), mp.find('e'));

    cout << "mp:\key\tvalue\n";
    for (std::map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it)
        cout << it->first << '\t' << it->second << endl;
    cout << endl << endl;

    return 0;
}
