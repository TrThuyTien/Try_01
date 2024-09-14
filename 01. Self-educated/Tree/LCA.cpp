#include<iostream>
//#include<bits/stdc++.h>
#include<vector>

const int N = 1e5 + 5;

using namespace std;

vector<int> a[N];
int par[100];

void input(int &n, int &m) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
}

void dfs(int u) {
    for (int v : a[u]) {
        par[v] = u;
        dfs(v);
    }
}

void output(int n) {
    for (int i = 1; i <= n; i++) {
        if (a[i].empty()) cout << "No edge";
        for (int u : a[i]) cout << u << " ";
        cout << '\n';
    }
}


int main () {
    freopen("LCA.inp", "r", stdin);
    freopen("LCA.out", "w", stdout);
    int n, m;
    input(n, m);
}