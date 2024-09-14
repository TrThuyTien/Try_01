/* Kết quả:
The size of s1 is : 2
The size of s2 is: 1
*/
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

struct CaseInsensitiveCompare {
    bool operator( )( const string & lhs, const string & rhs ) const {
        return strcasecmp( lhs.c_str( ), rhs.c_str( ) ) < 0;
    }
};
int main() {
    set<string> s1;
    s1.insert("Hello"); s1.emplace("HeLLo");
    cout << "The size of s1 is : " << s1.size() << endl;

    set<string, CaseInsensitiveCompare> s2;
    s2.insert("Hello"); s2.emplace("HeLLo");
    cout << "The size of s2 is: " << s2.size( ) << endl;

    return 0;
}
