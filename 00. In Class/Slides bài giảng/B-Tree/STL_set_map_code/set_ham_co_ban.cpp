/* Kết quả:
0 1 7 8 10
size    : 5
empty   : 0
max_size: 461168601842738790
*/
#include <iostream>
#include <set>
using namespace std;
int main () {
    int a[] = {8, 10, 0, 7, 1};
    set<int> s (a, a+5);
    for (set<int>::iterator it=s.begin(); it!=s.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
    cout << "size    : " << s.size() << endl;
    cout << "empty   : " << s.empty() << endl;
    cout << "max_size: " << s.max_size() << endl;

    return 0;
}
