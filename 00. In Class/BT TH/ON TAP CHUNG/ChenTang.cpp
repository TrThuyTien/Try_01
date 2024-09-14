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

int LinearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) 
        if (x < a[i]) return i;
    if (n == 0) return -1; 
    return n;
} 

void ChenTang(int x, int a[], int &n) {
    int k = LinearSearch(a, n, x);
    if (k == -1) {
        a[n] = x;
    } else {
        for (int i = n - 1; i >= k; i--) 
            a[i+1] = a[i];
        a[k] = x;
    }
    n++;
}
//
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

