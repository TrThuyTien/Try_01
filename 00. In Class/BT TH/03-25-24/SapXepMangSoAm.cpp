/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


//###INSERT CODE HERE -
#include <iostream>
#define MAXN 1000

using namespace std;

void NhapMang (int a[], int& n) {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
}

void heapify(int a[], const int&n, int i) {
    int largest = i;
    int root = i;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < n && a[largest] < a[l]) largest = l;
    if (r < n && a[largest] < a[r]) largest = r;
    if (largest != root) {
        swap(a[root], a[largest]);
        heapify(a, n, largest);
    }
}

void SapXepSoAmTangDan(int a[], const int& n) {
    int b[MAXN];
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) b[m++] = a[i];
    }
    // build heap b
    for (int i = m/2 - 1; i >= 0; i--) 
        heapify(b, m, i);
    
    for (int i = m - 1; i >= 0; i--) {
        swap(b[0], b[i]);
        heapify(b, i, 0);
    }
    int j = 0;
    for (int i = 0; i < n; i++) 
        if (a[i] < 0) a[i] = b[j++];
}

void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}
int main() {
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoAmTangDan(a, n);
    XuatMang(a, n);
    return 0;
}
