#include<bits/stdc++.h>

using namespace std;

bool isDigital(char c) {
    if (c >= '0' && c <= '9') return true;
    return false;
}

string decodeString(string s) {
    stack<int> val;
    stack<string> decode;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (isDigital(s[i])) {
            int num = 0;
            while(isDigital(s[i])) {
                num = num * 10 + int(s[i] - '0');
                i++;
            }
            val.push(num);
            i--;
        } else if (s[i] == ']') {
            int n = val.top();
            val.pop();
            string prev_str = decode.top();
            decode.pop();
            for (int k = 1; k <= n; k++) {
                prev_str += ans; 
            }
            ans = prev_str;
        } else if (s[i] == '[') {
            decode.push(ans);
            ans = "";
        } else ans += s[i];
    }
    return ans;
}

int main () {
    freopen("DecodeString.inp", "r", stdin);
    freopen("DecodeString.out", "w", stdout);
    string s;
    cin >> s;
    cout << decodeString(s);
}