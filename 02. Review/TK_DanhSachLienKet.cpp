#include <iostream>
#include <cmath>

using namespace std;
//Write code here
struct Point3D {
    float x, y, z;
    Point3D() : x(0.0), y(0.0), z(0.0) {}
};

istream& operator>>(istream& in, Point3D& p) {
    in >> p.x >> p.y >> p.z;
    return in;
}

bool operator==(Point3D p1, Point3D p2) {
    if (p1.x != p2.x) return false;
    if (p1.y != p2.y) return false;
    if (p1.z != p2.z) return false;
    return true;
}

struct Node {
    Point3D data;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
    List() : head(nullptr), tail(nullptr){}
};

Node* CreateNode(Point3D p) {
    Node* node = new Node;
    if (node == nullptr) 
        exit(1);
    node->data = p;
    node->next = nullptr;
    return node;
}

void AddTail(List& l, Point3D p) {
    Node* node = CreateNode(p);
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

int Search(List L, Point3D p) {
    Node* curr = L.head;
    int id = 0;
    while (curr != nullptr) {
        if (curr->data == p) return id;
        id++;
        curr = curr->next;
    }
    return -1;
}

void run() {
    int n;
    cin >> n;
    List L;
    for (int i = 0; i < n; i++) {
        Point3D p;
        cin >> p;
        AddTail(L, p);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        Point3D p;
        cin >> p;
        int k = Search(L, p);
        if (k == -1) cout << "KHONG\n";
        else cout << k << "\n";
    }
}
int main() {
    freopen ("TK_DanhSachLienKet.inp", "r", stdin);
    freopen ("TK_DanhSachLienKet.out", "w", stdout);
	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}