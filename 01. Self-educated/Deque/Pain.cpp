#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

int a[N], dp[N];

int main () {
    freopen("Pain.inp", "r", stdin);
    freopen("Pain.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i];
    dp[0] = 0;
    // for (int i = 1; i <= n + 1; i++) dp[i] = oo;
    // a[n+1] = 0;
    // for (int i = 1; i <= n + 1; i++) {
    //     for (int j = max(0, i - k); j < i; j++) {
    //         dp[i] = min(dp[i], dp[j] + a[i]);
    //     }
    // }
    // cout << ans - dp[n+1];
    deque<pair<int,int>> q;
    q.push_back({dp[0], 0});
    for (int i = 1; i <= n + 1; i++) {
        if (i > k) {
            dp[i] = q.front().first + a[i];
            if (q.front().second <= i - k) 
                q.pop_front();
        } else {
            dp[i] = a[i];
        }
        while (!q.empty() && dp[i] < q.back().first) {
            q.pop_back();
        }
        q.push_back({dp[i], i});
    }
    cout << ans - dp[n+1];
}