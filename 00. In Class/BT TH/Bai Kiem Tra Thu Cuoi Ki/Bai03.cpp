/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
[
]
###End banned keyword*/
#include <iostream>
#include <cmath>

using namespace std;
//###INSERT CODE HERE -

struct Point {
	double x, y, z;
};

struct Node {
	Point key;
	Node* next;
};

struct List {
	Node *head, *tail;
};

Node* CreateNode(Point x) {
	Node *p = new Node;
	if (p == NULL) exit(1);
	p->key = x;
	p->next = NULL;
	return p;
}

void CreateEmptyList(List& L) {
	L.head = NULL;
	L.tail = NULL;
}

istream& operator>>(istream& in, Point& p) {
	in >> p.x >> p.y >> p.z;
	return in;
}

bool operator==(Point p1, Point p2) {
	if (p1.x != p2.x) return false;
	if (p1.y != p2.y) return false;
	if (p1.z != p2.z) return false;
	return true;
}

void addTail(List& L, Point x) {
	Node* p = CreateNode(x);
	if (L.head == NULL) {
		L.head = p;
		L.tail = p;
	} else {
		L.tail->next = p;
		L.tail = p;
	}
}

int Search(List L, Point p) {
	Node *curr = L.head;
	int id = 0;
	while (curr != NULL) {
		if (curr->key == p) return id;
		id++;
		curr = curr->next;
	}
	return -1;
}

void run() {
	List L;
	CreateEmptyList(L);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Point x;
		cin >> x;
		addTail(L, x);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		Point p;
		cin >> p;
		int f = Search(L, p);
		if (f == -1) cout << "KHONG\n";
		else cout << f << '\n';
	}
}

int main() {
	freopen("Bai03.inp", "r", stdin);
	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}