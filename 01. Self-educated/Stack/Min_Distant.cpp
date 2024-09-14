#include<bits/stdc++.h>

using namespace std;

#define oo 1000000007

int main () {
    freopen("Min_Distant.inp", "r", stdin);
    freopen("Min_Distant.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        a.push_back(val);
    }
    int ans = oo;
    stack<pair<int,int>> st;
    st.push({a[0], 0});
    for (int i = 1; i < a.size(); i++) {
        while(!st.empty() && st.top().first < a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans = min(ans, i - st.top().second);
        }
        st.push({a[i], i});
    }
    if (ans == oo) cout << "-1";
    else cout << ans;
}