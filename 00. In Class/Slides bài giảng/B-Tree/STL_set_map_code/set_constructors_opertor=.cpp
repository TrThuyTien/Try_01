#include <iostream>
#include <set>
#include <functional>

int main () {
    std::set<int> s1= {8, 10, 0, 7, 1};
    // copy constructor
    std::set<int> s2(s1);
    s2.insert(5);
    // range constructor
    std::set<int> s3(s1.begin(), s1.end());
    s3.erase(8);
    // default constructor
    std::set<int> s4;
    // operator =
    s4=s1; s4.erase(7);

    for (std::set<int>::iterator it=s1.begin(); it!=s1.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
    for (std::set<int>::iterator it=s2.begin(); it!=s2.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
    for (std::set<int>::iterator it=s3.begin(); it!=s3.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    for (std::set<int>::iterator it=s4.begin(); it!=s4.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    return 0;
}
