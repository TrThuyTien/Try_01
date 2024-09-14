#include<bits/stdc++.h>

using namespace std;

bool isDigital(char c) {
    if (c >= '0' && c <= '9') return true;
    return false;
}

int priority(char op) {
    if (op == '*' || op == '/') return 2;
    return 1;
}

void calculate(vector<int> &val, char op) {
    int num2 = val.back(); val.pop_back();
    int num1 = val.back(); val.pop_back();
    switch (op) {
        case '+' :
            val.push_back(num1 + num2);
            break;
        case '-' :
            val.push_back(num1 - num2);
            break;
        case '*' :
            val.push_back(num1 * num2);
            break;
        case '/' :
            val.push_back(num1 / num2);
            break;
    }
}

int main () {
    freopen("Expression_Parsing.inp", "r", stdin);
    freopen("Expression_Parsing.out", "w", stdout);
    string s;
    cin >> s;
    vector<int> val;
    vector<char> op;
    for (int i = 0; i < s.size(); i++) {
        if (isDigital(s[i])) {
            int num = 0;
            while(i < s.size() && isDigital(s[i])) {
                num = num * 10 + int(s[i] - '0');
                i++;
            }
            val.push_back(num);
            i--;
        } else {
            char curr_op = s[i];
            while(!op.empty() && priority(op.back()) >= priority(curr_op)) {
                calculate(val, op.back());
                op.pop_back();
            }
            op.push_back(curr_op);
        }
    }
    while(!op.empty()) {
        calculate(val, op.back());
        op.pop_back();
    }
    cout << val.back();
}