/* Kết quả:
two -> 5.5
one -> 3.5
*/
#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main () {
    pair<string, double> a;
    pair<string, double> b("one", 3.5);
    pair<string, double> c(b);
    std::pair <string, double> d;
    d = make_pair ("two", 5.5);
    pair <string, double> *e=&b;

    cout << d.first << " -> " << d.second;
    cout << endl;
    cout << e->first << " -> " << e->second  << endl;

    return 0;
}
