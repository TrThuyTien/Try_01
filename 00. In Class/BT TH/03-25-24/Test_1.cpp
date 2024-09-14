/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
// #include <bits/stdc++.h>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

//###INSERT CODE HERE -
void heapify (int a[], const int& n, int i) {
    int largest = i;
    int root = i;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < n && a[largest] > a[l]) largest = l;
    if (r < n && a[largest] > a[r]) largest = r;
    if (largest != root) {
        swap(a[root], a[largest]);
        heapify(a, n, largest);
    }
}

int SoNhoNhat(int a[], const int& n) {
    int b[MAXN];
    for (int i = 0; i < n; i++) 
        b[i] = a[i];
    for (int i = n/2 - 1; i >= 0; i--) 
        heapify(b, n, i);
    return b[0];
}

void XuatMang(int a[], const int& n) {
    if (n == 0) {
        std::cout << "Empty Array.";
        return;
    }
    for (int i = 0; i < n; i++) 
        std::cout << a[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    if (n!=0) std::cout << "Minimum number: " << SoNhoNhat(a, n) << std::endl;

    XuatMang(a, n);

    return 0;
}
