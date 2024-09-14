/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 100000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void hoanvi(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}

//###INSERT CODE HERE -

void insertion_sort_decending(int a[], const int &n) 
{
    for (int i = 1; i < n; i++) {
        int pos = i - 1;
        int x = a[i];
        while (pos >= 0 && a[pos] < x) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x; 
    }
}
void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    insertion_sort_decending(a, n);

    XuatMang(a, n);

    return 0;
}
