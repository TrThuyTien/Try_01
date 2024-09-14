/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
void hoanvi(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}


//###INSERT CODE HERE -

void partition1(int a[], const int &l, const int &r, int& pivot, int &i, int &j) {
    if (l > r) return;
    i = l;
    j = r;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            hoanvi(a[i], a[j]);
            i++;
            j--;
        } 
    }

}
void quick_sort_ascending1(int a[], const int& l, const int& r) {
    int pivot = a[(l+r)/2];
    int i, j;
    partition1(a, l, r, pivot, i, j);
    if (l < j) quick_sort_ascending1(a, l, j);
    if (i < r) quick_sort_ascending1(a, i, r);
}

void quick_sort_ascending(int a[], const int& n) {
    quick_sort_ascending1(a, 0, n-1);
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    quick_sort_ascending(a, n);

    XuatMang(a, n);

    return 0;
}
