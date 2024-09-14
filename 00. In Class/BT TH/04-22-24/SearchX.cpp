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

bool searchNode(TREE T, const int& x) {
    if (T != NULL) {
        if (T->key == x) return true;
        if (T->key < x) return searchNode(T->pRight, x);
        return searchNode(T->pLeft, x);
    }
    return false;
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;
	if(searchNode(T, x)) cout << "true"; // Sinh viên lưu ý Bài này yêu cầu Xử lý trên cây nhị phân tổng quát, không phải chỉ trường hợp cây nhị phân tìm kiếm.
	else cout << "false";
	return 0;
}
