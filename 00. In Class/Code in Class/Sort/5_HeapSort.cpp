#include<iostream>

using namespace std;

void input(int *&a, int &n) {
    cin >> n;
    a = new int[n];
    for (int i = 0; i  < n; i++) 
        cin >> a[i];
}

void output(int *a, const int &n) {
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl;
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int root = i;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (root != largest) {
        swap(a[root], a[largest]);
        heapify(a, n, largest);
    }

}

void heapSort(int *a, const int &n) {
    // Build heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    output(a, n);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main () {
    int *a, n;
    input(a, n);
    heapSort(a, n);
    output(a, n);
    delete[] a;
}