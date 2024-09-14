/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//###INSERT CODE HERE -
bool isMaxHeap(int *a, int n) {
    for (int i = 0; i < n / 2; i++) {
        int left = 2*i + 1;
        int right = 2* i + 2;
        if (left < n) {
            if (a[left] > a[i]) return false;
        }
        if (right < n) {
            if (a[right] > a[i]) return false;
        }
    }
    return true;
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    std::cout << "MaxHeap: " << std::boolalpha << isMaxHeap(a, n) << std::endl;

    return 0;
}
