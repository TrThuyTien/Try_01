/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

using namespace std;
#define MAXN 150000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
int binary_search(int a[], int const &n, int const &x)
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

void ChenTang(const int &x, int a[], int &n) 
{
    int k = binary_search(a, n, x);
    if (k == -1) {
        a[n] = x;
        n++;
        return;
    }
    for (int i = n - 1; i >= k; i--) {
        a[i+1] = a[i];
    }
    a[k + 1] = x;
    n++;
}

void XuatMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN];
    int x; cin >> x;
    int n; cin >> n;

    NhapMang(a, n);

    ChenTang(x, a, n);

    XuatMang(a, n);

    return 0;
}

