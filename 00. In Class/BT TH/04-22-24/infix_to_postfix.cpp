/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};

//###INSERT CODE HERE -

NODE* createNode (const char& c) {
    NODE* node = new NODE;
    node->info = c;
    node->pNext = nullptr;
    return node;
}

struct STACK {
    NODE *top;
    STACK () : top(nullptr) {};
    void Push (char c) {
        if (top == nullptr) top = createNode(c);
        else {
            NODE* node = createNode(c);
            node->pNext = top;
            top = node;
        }
    }

    char Top() {
        return top->info;
    }

    void Pop() {
        if (top != nullptr)
            top = top->pNext;
    }

    bool Empty() {
        if (top == nullptr) return true;
        return false;
    }
};



void Input_infix(char infix[], int& n) {
    char c;
    n = 0;
    do {
        cin >> c;
        if (c == '#') break;
        if (c != ' ') infix[n++] = c;
    } while (true);
}

int priorityOperator(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    return 1;
}

void infix_to_postfix(char infix[MAXN], const int& ni, char postfix[MAXN], int& np) {
    np = 0;
    STACK op;
    for (int i = 0; i < ni; i++) {
        if (infix[i] == '(') op.Push(infix[i]);
        else if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[np++] = infix[i];
        } else {
            if (infix[i] == ')') {
                while (!op.Empty() && op.Top() != '(') {
                    postfix[np++] = op.Top();
                    op.Pop();
                }
                if (op.Top() == '(') op.Pop();
            } else {
                if (op.Empty()) {
                    op.Push(infix[i]);
                }
                else {
                    while (!op.Empty() && (op.Top() != '(' && priorityOperator(infix[i]) <= priorityOperator(op.Top()))) {
                        postfix[np++] = op.Top();
                        op.Pop();
                    }
                    op.Push(infix[i]);
                } 
            }
        }
    }
    while (!op.Empty()) {
        if (op.Top() != '(') postfix[np++] = op.Top();
        op.Pop();
    }
}

void Output (char postfix[], const int& np) {
    for (int i = 0; i < np; i++) 
        cout << postfix[i] << " ";
}

int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
