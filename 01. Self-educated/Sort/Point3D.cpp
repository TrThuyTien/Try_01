#include <iostream>

using namespace std;

struct Point {
    int x, y, z;
    Point () : x(0), y(0), z(0) {};
};

istream& operator>>(istream& inp, Point& p) {
    inp >> p.x >> p.y >> p.z;
    return inp;
}

ostream& operator<<(ostream& out, const Point& p) {
    cout << p.x << " " << p.y << " " << p.z << '\n';
    return out;
}

bool operator>(const Point& p1, const Point& p2) {
    if (p1.x > p2.x) return true;
    if (p1.x < p2.x) return false;
    if (p1.y < p2.y) return true;
    if (p1.y > p2.y) return false;
    if (p1.z > p2.z) return true;
    return false;
}


void input(Point *&a, int& n) {
    cin >> n;
    a = new Point[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
}

void swap(Point& p1, Point& p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

void quickSort(Point *&a, int l, int r) {
    Point pivot = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (pivot > a[i]) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (i < r) quickSort(a, i, r);
    if (l < j) quickSort(a, l, j);
}

void output(Point *&a, const int& n) {
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
}

int main () {
    // freopen ("Point3D.inp", "r", stdin);
    // freopen ("Point3D.out", "w", stdout);
    Point *a;
    int n;
    input(a, n);
    quickSort(a, 0, n-1);
    output(a, n);
}