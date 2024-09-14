// Chèn x vào mảng đang có thứ tự tăng dần, sao cho sau khi chèn mảng vẫn đảm bảo thứ tự tăng dần
#include <iostream>
using namespace std;
void Nhap(int *a, int &n) 
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int binary_search(int *a, int n, int x){
      int l = 0, r = n-1;
      while (l <= r)
      {
          int m = (r+l)/2;
          if (a[m] == x) return m;
          else if (a[m] > x) r = m-1;
          else if (a[m] < x) l = m+1;
      }
      return -1;
}

int LonNhatNhoHon(int *a, int n, int x){
      int l = 0, r = n-1, res=-1;
      while (l <= r)      {
          int m = (r+l)/2;
          if (a[m] == x) l= m+1;
          else if (a[m] > x) {
            r = m-1;
            res=m;
          }
          else if (a[m] < x) l = m+1;
      }
      return res;
}

int  ViTri_LonNhatNhoHonX_Linear(int *a, int n, int x) 
{
    for (int i = 0; i < n; i++) {
        if (a[i] > x) return i;
    }
    return -1;
}

void DichPhai(int *a, int n, int k) 
{
    for (int i = n-1; i >= k; i++)
        a[i+1] = a[i];
}

void ChenTang_C1(int *a, int &n, int x){
    int k=  ViTri_LonNhatNhoHonX_Linear(a, n, x);
    DichPhai(a, n, k);
    a[k]=x;
}

void ChenTang_C2(int *a, int &n, int x){
    int k=  ViTri_LonNhatNhoHonX_Binary(a n, x);
    DichPhai(a, n, k);
    a[k]=x;
}
void ChenTang_C3(int *a, int &n, int x){
    int check = 0;
    if (a[n-1] <= x) a[n] = x;
    return;
    for (int i = n - 1; i > 0; i++) {
        if (a[i] > x) a[i + 1] = a[i];
        else {
            a[i] = x;
            check = 1;
            break;
        }
    }
    if (!check) a[0] = x;
}

void InsertionSort(int *a, int n)
{
    int sorted[100];
    sorted[0] = a[0];
    for (int i = 1; i < n; i++) {
        int x = a[i];
        ChenTang_C3(sorted, i - 1, x);
    }
}
int main() {
    int a[10]={1, 2, 5, 7, 8, 9}, n=6, x=6;
    ChenTang_C3(a, n, x);
    Xuat(a, n);    
    return 0;
}