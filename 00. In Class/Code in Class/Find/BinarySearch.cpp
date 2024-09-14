#include<iostream>

using namespace std;

void input(int *a, int &n, int &x) {
    cin >> n >> x;
    a = new int[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
}

bool binarySearch(int *a, int l, int r, int x) {
    if (l > r) return false;
    int mid = (l + r) / 2;
    if (a[mid] == x) return true;
    if (a[mid] < x) return binarySearch(a, mid + 1, r, x);
    return binarySearch(a, l, mid-1, x);
}

int main () {
    int n, int x;
    int *a;
    input(a, n, x); 
    // Thực hiện sắp xếp mảng a   
    cout << binarySearch(a, n, x);

}