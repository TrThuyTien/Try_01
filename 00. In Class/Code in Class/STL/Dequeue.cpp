#include <iostream>

using namespace std;

void heapfy (int n, int i) {
    int root = i;
    int val = a[i];
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < n && a[l] < val) root = l;
    if (r < n && a[r] < val) root = r;
    if (root != i) {
        swap (a[i], a[root]);
        heapfy(n, root);
    }
}
void insertDequeue (int x, int i) {
    a[i - 1] = x;

}
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertDequeue(x, i);
    }
}