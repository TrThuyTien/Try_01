#include<iostream>

using namespace std;

void input(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void merge(int a[], int l, int r) {
    int mid = (l + r) / 2;
    int i = l, j = mid + 1;
    int k = l;
    int c[1000];
    while (i <= mid || j <= r) {
        if (j > r) {
            c[k++] = a[i];
            i++;
        } else if (i > mid) {
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
    for (int i = l; i <= r; i++)
        a[i] = c[i]; 
}
void sort(int a[], const int& n) {
    int k = 1;
    while (k < n) {
        for (int i = 0; i < n; i += 2*k) {
            merge(a, i, min(i + 2*k - 1, n - 1));
        }
        k *= 2;
    }
}

void output(int a[], const int&n) 
{
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl;
}

int main () 
{
    int arr[1000], n;
    input(arr, n);
    sort(arr, n);
    output(arr, n);
}