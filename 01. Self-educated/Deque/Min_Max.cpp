#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main () {
    freopen("Min_Max.inp", "r", stdin);
    freopen("Min_Max.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    deque<pair<int,int>> dq;
    for (int i = 1; i <= n; i++) {
        if (dq.empty() || a[i] >= dq.back().first) {
            dq.push_back({a[i], i});
        } else {
            while (!dq.empty() && a[i] < dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({a[i], i});
        }
        if (i >= k) {
            cout << dq.front().first << endl;
            if (dq.front().second <= i - k + 1) 
                dq.pop_front();
        }
    }
}