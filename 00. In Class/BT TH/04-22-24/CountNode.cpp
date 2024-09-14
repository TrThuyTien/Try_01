/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};

typedef TNODE* TREE;

void CreateEmptyTree(TREE &T) {
	T = NULL;
}

TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}

void CreateTree(TREE &T){
	int x;
	do {
		cin >> x;
		if(x==-1) break;
		Insert(T, CreateTNode(x));
	}while(true);
}

//###INSERT CODE HERE -
void inOrder(TREE T, int& cnt) {
    if (T != nullptr) {
        inOrder(T->pLeft, cnt);
        cnt++;
        inOrder(T->pRight, cnt);
    }
}

int CountNode (TREE T) {
    if (T == nullptr) return 0;
    int cnt = 0;
    inOrder(T, cnt);
    return cnt;
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << CountNode(T);
	return 0;
}
