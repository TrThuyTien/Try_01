#include<iostream>

using namespace std;

void input(int a[], int &n) 
{
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
}

void insertionSort(int a[], const int& n) 
{
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int pos = i - 1;
        while (pos >= 0 && a[pos] > x) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

void output(int a[], const int& n)
{
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
}

int main () {
    int n;
    int arr[1000];
    input(arr, n);
    insertionSort(arr, n);
    output(arr, n);
}