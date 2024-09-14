#include<bits/stdc++.h>

using namespace std;

bool isDigital(char c) {
    if (c >= '0' && c <= '9') return true;
    return false;
}

void addTwoNum(vector<int> &val, char op) {
    int num2 = val.back(); val.pop_back();
    int num1 = val.back(); val.pop_back();
    switch (op) {
        case '+' :
            val.push_back(num1 + num2); 
            break;
        case '-' :
            val.push_back(num1 - num2);
            break;
    }
} 

int main() {
    freopen("Sum.inp", "r", stdin);
    freopen("Sum.out", "w", stdout);
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
            if (!op.empty()) {
                addTwoNum(val, op.back());
                op.pop_back();
            }
            op.push_back(s[i]);
        }
    }
    if (!op.empty()) {
        addTwoNum(val, op.back());
        op.pop_back();
    }
    cout << val.back();
}