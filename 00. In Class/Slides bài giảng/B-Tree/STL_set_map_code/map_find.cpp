/* Kết quả:
Tim thay.
*/
#include <iostream>
#include <map>
using namespace std;
int main () {
    map<string, int> m;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    map<string, int>::iterator it;
    it=m.find("two");
    if(it==m.end()) cout << "Khong Tim thay.";
    else cout << "Tim thay.";

    return 0;
}
