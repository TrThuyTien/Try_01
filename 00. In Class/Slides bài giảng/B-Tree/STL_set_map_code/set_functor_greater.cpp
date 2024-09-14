/*
Kết quả hiện thị:
s1: 9 8 7 6 5 4 3 2 1
s2: 9 8 7 6 5 4 3 2 1
*/
#include <iostream>
#include <set>
#include <functional>
using namespace std;
struct class_greater {
    bool operator() (const int& i, const int& j)const {
        return i>j;
    }
};
int main() {
    std::set<int, class_greater> s;
    for (int i=1; i<10; i++)
        s.insert(i);

    std::set<int, greater<int>> s1;
    for (int i=1; i<10; i++)
        s1.insert(i);

    std::set<int>::iterator it;
    cout << "s1: ";
    for(it=s.begin(); it!=s.end(); it++)
        cout << *it << " ";

    cout << "\ns2: ";
    for(it=s1.begin(); it!=s1.end(); it++)
        cout << *it << " ";


    return 0;
}
