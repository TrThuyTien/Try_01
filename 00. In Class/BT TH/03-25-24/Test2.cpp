#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void quickSort(string &s, const int &l, const int &r) {
    char pivot = s[(l + r)/2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (s[i] < pivot) i++;
        while (pivot < s[j]) j--;
        if (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort (s, l, j);
    if (i < r) quickSort (s, i, r);
}
int main () {
    string s;
    cin >> s;
    int n = s.size();
    quickSort(s, 0, n - 1);
    cout << s;
}