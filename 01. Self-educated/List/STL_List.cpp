#include <iostream>
#include <forward_list>

using namespace std;

int main () {
    // freopen ("STL_List.inp", "r", stdin);
    // freopen ("STL_List.out", "w", stdout);
    forward_list <int> list1;
    forward_list <int> list2;
    forward_list <int> list3;
    // using assign
    list1.assign({1, 2, 3});
    list2.assign(5, 4);
    list3.assign({4, 6, 2, 5});
    // using push_front()
    list1.emplace_front(8);
    list1.push_front(5);
    list1.pop_front();
    for (int &a : list1) 
        cout << a << " ";
    cout << endl;

    // using insert_after()

    for (int &b : list2)
        cout << b << " ";
    cout << endl;
    list3.emplace_after(4);
    for (int &c : list3) 
        cout << c << " ";
    cout << endl;
}