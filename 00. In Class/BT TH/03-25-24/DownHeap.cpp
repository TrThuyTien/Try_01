#include<iostream>
#define N 1000001

using namespace std;

void Input(int *&a, int &n, int &m) {
    cin >> n >> m;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void buildMaxHeap (int *a, const int& n, int i) {
    if (n < 1) return;
    int largest = i;
    int root = i;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != root) {
        swap(a[largest], a[root]);
        buildMaxHeap (a, n, largest);
    }
}

void heapSort(int *a, const int&n) {
    if (n < 1) return;
    for (int i = n/2 - 1; i >= 0; i--) 
        buildMaxHeap (a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        buildMaxHeap (a, i, 0);
    }
}

void process_1(int *a, int& n) {
    if (n < 1) return;
    swap(a[0], a[n-1]);
    n--;
    buildMaxHeap (a, n, 0);
}

void process_2(int *a, int &n) {
    if (n < 1) return;
    int maxVal = a[0];
    while (a[0] == maxVal) {
        swap(a[0], a[n-1]);
        n--;
        buildMaxHeap (a, n, 0);
    }
}

void process_3 (int *a, int &n, const int& t) {
    if (n < 1) return;
    a[0] -= t;
    buildMaxHeap (a, n , 0);
}

void process_4 (int *a, int &n, const int& t) {
    if (n < 1) return;
    int maxVal = a[0];
    while (a[0] == maxVal) {
        a[0] -= t;
        buildMaxHeap (a, n , 0);
    }
}

void Output (int *a, const int& n) {
    for (int i = n-1; i >= 0; i--) {
        cout << a[i] << "\n";
    }
}

int main () {
    freopen ("DownHeap.inp", "r", stdin);
    freopen ("DownHeap.out", "w", stdout);
    int n, m;
    int* a;
    Input(a, n, m);
    // Build heap
    for (int i = n/2 - 1; i >= 0; i--) 
        buildMaxHeap (a, n, i);
    while (m--) {
        int cases, t;
        cin >> cases;
        if (cases == -1) process_1(a, n);
        if (cases == -2) process_2(a, n);
        if (cases == -3) {
            cin >> t;
            process_3(a, n, t);
        }
        if (cases == -4) {
            cin >> t;
            process_4(a, n, t);
        }
    }
    heapSort(a, n);
    Output(a, n);
}
