#include <iostream>
#include <vector>

using namespace std;

struct Point3D {
    double x, y, z;
};

int n, m;
vector<Point3D> a;

bool operator==(Point3D p1, Point3D p2) {
    if (p1.x != p2.x) return false;
    if (p1.y != p2.y) return false;
    if (p1.z != p2.z) return false;
    return true;
}

bool operator<(Point3D p1, Point3D p2) {
    if (p1.x > p2.x) return false;
    else if (p1.x < p2.x) return true;
    else if (p1.y > p2.y) return false;
    else if (p1.y < p2.y) return true;
    if (p1.z >= p2.z) return false;
    return true;
}

ostream& operator<<(ostream& out, Point3D p) {
    out << p.x << " " << p.y << " " << p.z << endl;
    return out;
}

int CountBinarySearch (int l, int r, Point3D p) {
    int cnt = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        cnt++;
        if (a[mid] == p) return cnt;
        else if (a[mid] < p) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main () {
    freopen ("Bai1.inp", "r", stdin);
    //freopen ("Bai01.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Point3D p;
        cin >> p.x >> p.y >> p.z;
        a.push_back(p);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        Point3D p;
        cin >> p.x >> p.y >> p.z;
        int k = CountBinarySearch(0, n-1, p);
        if (k == -1) cout << "KHONG\n";
        else cout << k << "\n";
    }
}