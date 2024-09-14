#include<iostream>

using namespace std;

void input(int *&a, int &n) {
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
}

void output(int *a, const int &n) {
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl;
} 

void quickSort(int *a, int l, int r) {
    int mid = (l + r) / 2;
    int pivot = a[mid];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    cout << pivot << " : " << l << " " << r << " - ";
    output(a, r + 1);
    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

int main () {
    int *a, n;
    input(a, n);
    quickSort(a, 0, n-1);
    output(a, n);
}