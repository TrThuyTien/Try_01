/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

void NhapMang(int *a, int &n){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void XuatMang(int A[], const int &N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

//###INSERT CODE HERE -
void merge(int *a, const int& l, const int& r, const int& mid) {
    int c[MAXN];
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid || j <= r) {
        if (j > r && i <= mid) {
            c[k++] = a[i];
            i++;
        } else if (i > mid && j <= r) {
            c[k++] = a[j];
            j++;
        } else {
            if (a[i] < a[j]) {
                c[k++] = a[i];
                i++;
            } else {
                c[k++] = a[j];
                j++;
            }
        }
    }
    for (int i = 0; i < k; i++)
        a[i+l] = c[i]; 
}

void MergeSort (int *a, const int &n) {
    int k = 1;
    while (k < n) {
        for (int i = 0; i < n; i += 2*k) {
            merge(a, i, min(i + 2*k - 1, n - 1), i + k - 1);
        }
        k *= 2;
    }
}

int main() {
    int n, a[MAXN];
    NhapMang(a, n);

    MergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
