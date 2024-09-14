/* Kết quả:
s1:  I UITer am

s2:
h -> 8
y -> 9
*/
#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main () {
    set<string> s{};
    s.emplace("I");
    s.emplace("am");
    s.emplace("UITer");
    // UITer sẽ không được thêm vào set nữa vì đã tồn tại
    s.emplace("UITer");

    set<pair<char, int>> s1;
    s1.emplace('y', 9);
    // Không dùng được: ms.insert('b', 25);
    s1.insert(make_pair('h', 8));

    cout << "s1: ";
    for (set<string>::iterator it=s.begin(); it!=s.end(); ++it)
        cout << ' ' << *it;
    cout << "\n\ns2:\n";
    for (set<pair<char, int>>::iterator it=s1.begin(); it!=s1.end(); ++it)
        cout << (*it).first << " -> " << it->second << endl;

    return 0;
}
