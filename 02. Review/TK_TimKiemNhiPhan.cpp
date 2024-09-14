#include <iostream>
#include <vector>

using namespace std;

#define N 10000

struct Point3D{
    float x, y, z;
    Point3D() : x(0.0), y(0.0), z(0.0) {}
};

istream& operator>>(istream& in, Point3D& p) {
    cin >> p.x >> p.y >> p.z;
    return in;
}

bool operator==(Point3D p1, Point3D p2) {
    if (p1.x != p2.x) return false;
    if (p1.y != p2.y) return false;
    if (p1.z != p2.z) return false;
    return true;
}

bool operator>(Point3D p1, Point3D p2) {
    if (p1.x < p2.x) return false;
    if (p1.x == p2.x) {
        if (p2.y < p2.y) return false;
        if (p1.y == p2.y) {
            if (p1.z <= p2.z) return false;
            return true;
        }
        return true;
    }
    return true;
}

vector<Point3D> v;
int BinarySearch(int l, int r, Point3D p) {
    int cnt = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        cnt++;
        if (v[mid] == p) return cnt;
        if (v[mid] > p) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main () {
    // freopen ("TK_TimKiemNhiPhan.inp", "r", stdin);
    // freopen ("TK_TimKiemNhiPhan.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Point3D p;
        cin >> p;
        v.push_back(p);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        Point3D p;
        cin >> p;
        int cnt = BinarySearch(0, n - 1, p);
        if (cnt == -1) cout << "KHONG\n";
        else cout << cnt << '\n';
    }
}