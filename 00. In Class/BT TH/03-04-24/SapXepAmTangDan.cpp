/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


//###INSERT CODE HERE -
#include<iostream>
#define MAXN 100

using namespace std;

void NhapMang(int a[], int &n) 
{
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
}

void SapXepSoAmTangDan(int a[], int n) 
{
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) continue;
        int selected = a[i];
        int j = i - 1;
        bool check = true;
        int index = i;
        while (j >= 0 && a[j] > selected) {
            if (a[j] < 0) {
                if (check) {
                    a[index] = a[j];
                    check = false;
                    index = j;
                } else {
                    a[j + 1] = a[j];
                    index = j;
                }
            } else check = true;
            j--;
        }
        a[index] = selected;
    }
}

void XuatMang(int A[], int N) {
    cout << endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}
int main() {
    int a[MAXN], n;
    NhapMang(a, n);
    int m = n;
    SapXepSoAmTangDan(a, n);
    XuatMang(a, m);
    return 0;
}
