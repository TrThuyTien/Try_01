/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define N 100001
int e, v;
vector<vector<int>> a;
map<string, int> v_index;
bool* kt; // Kiem tra xem u da duoc di qua hay chua
string* city;

void dfs(string u) {
    stack<int> st;
    st.push(v_index[u]);
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        if (kt[x]) continue;
        cout << city[x] << " "; 
        kt[x] = 1;
        for (int y = 1; y <= v; y++) {
            if (a[x][y] == 1 && kt[y] == 0)
                st.push(y);
        }
    }
}

int main () {
    freopen ("DFS.inp", "r", stdin);
    cin >> e >> v;
    city = new string[v + 1];
    kt = new bool[v+1];
    for (int i = 0 ; i <= v; i++) kt[i] = 0;
    for (int i = 1; i <= v; i++) {
        string s;
        cin >> s;
        v_index[s] = i;
        city[i] = s;
    }
    a.resize(v + 1);
    for (int i = 0; i <= v; i++) 
        a[i].resize(v + 1);
    for (int i = 0; i <= v; i++) 
        for (int j = 0; j <= v; j++) a[i][j] = 0;

    for (int i = 0; i < e; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int u = v_index[s1];
        int v = v_index[s2];
        a[u][v] = 1;
    }
    string start;
    cin >> start;
    dfs(start);
    return 0;
}