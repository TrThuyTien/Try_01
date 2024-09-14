/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
int binary_search_leastGreater_firstOccurrence(int a[], int const &n, int const &x)
{
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] <= x) l = m + 1;
        else r = m - 1;
    }
    if (l < n && a[l] > x) return l;
    return -1;
}
int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_leastGreater_firstOccurrence(a, n, x);

    return 0;
}


