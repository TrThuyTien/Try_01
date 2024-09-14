#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

#include <algorithm>

using namespace std;

int v, e;
string vertices;
vector<vector<int>> G;
map<string, int> v_index;
string* city;

void Input() {
    cin >> e >> v;
    city = new string[v + 1];
    for (int i = 1; i <= v; i++) {
        string s;   
        cin >> s;
        v_index[s] = i;
        city[i] = s;
    }
    G.resize(v + 1);
    for (int i = 0; i <= v; i++) 
        G[i].resize(v + 1);
    for (int i = 1; i <= v; i++) 
        for (int j = 1; j <= v; j++) G[i][j] = false;
    for (int i = 0; i < e; i++) {
        string s1, s2;
        int w;
        cin >> s1 >> s2 >> w;
        int u = v_index[s1];
        int v = v_index[s2];
        G[u][v] = 1;
    }
    cin >> vertices;
}

int main () {
    freopen ("DinhKe.inp", "r", stdin);
    Input();
    int u = v_index[vertices];
    if (u < 1 || u > v) cout << "No find\n";
    else {
        bool check = true;
        for (int i = 1; i <= v; i++) 
            if (G[u][i] == 1) {
                cout << city[i] << " ";
                check = false;
            }
        if (check) cout << "No find\n";
    } 
}