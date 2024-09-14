/*
Kết quả hiện thị:
9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9
4 5 6
1 2 3 4
*/
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int, greater<int>> s1;
    set<int> s2, s3, s4;
    std::set<int>::iterator it;

    for(int i = 1; i <=9; i++ )
        s1.insert(s1.end(), i);
    for(int i = 9; i >= 1; i-- )
        s2.insert(i);
    s3.insert(s2.find(4), s2.find(7));
    int a[] = {1, 4, 2, 3, 5};
    s4.insert(a, a+4);

    for(it=s1.begin(); it!=s1.end(); it++)
        cout << *it << " ";
    cout << endl;

    for(it=s2.begin(); it!=s2.end(); it++)
        cout << *it << " ";
    cout << endl;

    for(it=s3.begin(); it!=s3.end(); it++)
        cout << *it << " ";

    cout << endl;
    for(it=s4.begin(); it!=s4.end(); it++)
        cout << *it << " ";

    return 0;
}
