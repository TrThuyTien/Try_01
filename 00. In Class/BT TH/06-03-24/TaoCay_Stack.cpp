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

//###INSERT CODE HERE -
#include <stack>


int main() {
	TREE T;
	int x;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << HeightOfNode(T, x);

	return 0;
}
