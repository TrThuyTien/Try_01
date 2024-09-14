/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <queue>
#include <cmath>
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
bool IsPerfectBinaryTree(TREE T) {
    if (T == NULL) return false;
    queue<TNODE*> q;
    q.push(T);
    q.push(NULL);
    int height = 0;
    while (!q.empty()) {
        TNODE* node = q.front();
        q.pop();
        if (node != NULL) {
            if (node->pLeft != NULL) q.push(node->pLeft);
            if (node->pRight != NULL) q.push(node->pRight);
        } else {
            height++;
            if (q.size() && q.size() != pow(2, height)) return false;
            if (!q.empty()) q.push(NULL);
        }
    }
    return true;
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << boolalpha << IsPerfectBinaryTree(T);

	return 0;
}
