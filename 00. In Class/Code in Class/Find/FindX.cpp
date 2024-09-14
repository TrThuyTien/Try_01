#include<iostream>

using namespace std;

int findIdX (int a[], int n, int x) {
    for (int i = 0; i < n; i++) 
        if (a[i] == x) return true;
    return false;
}

int main () {
    int n, x;
    cin >> n >> x;
    int *a;
    a = new int[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    cout << findIdX(a, n, x);
}