/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

using namespace std;

//###INSERT CODE HERE -
#define MAXN 150000

void NhapMang(int a[], int const &n)
{
    for (int i = 0; i < n; i++) 
        cin >> a[i];
}

int binary_search(int a[], int const &n, int const &x)
{
    int l = 0, r = n-1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return true;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}


int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);


    int i= binary_search(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";

    return 0;
}


