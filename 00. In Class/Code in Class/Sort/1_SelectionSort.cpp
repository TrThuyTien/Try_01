#include<iostream>

using namespace std;

void input(int a[], int &n) 
{
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
}

void selectionSort (int a[], const int& n) 
{
    for (int i = 0; i < n; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) 
            if (a[index] > a[j]) index = j;
        swap(a[i], a[index]);
    }
}

void output (int a[], const int&n) 
{
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
}

int main () {
    int n;
    int arr[1000];
    input(arr, n);
    selectionSort(arr, n);
    output(arr, n);
}