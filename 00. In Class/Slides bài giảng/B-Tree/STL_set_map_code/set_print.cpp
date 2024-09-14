// Kết quả in ra màn hình: 0 1 7 8 10
#include <iostream>
#include <set>

int main () {
    std::set<int> s1= {8, 10, 0, 7, 1};

    for (std::set<int>::iterator it=s1.begin(); it!=s1.end(); ++it)
        std::cout << *it << ' ';

    return 0;
}
