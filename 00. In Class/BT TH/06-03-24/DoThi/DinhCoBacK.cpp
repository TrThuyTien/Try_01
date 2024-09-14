#include <iostream>
#include <string>
#include <map>

using namespace std;

int e, v;
map<string, int> v_index;
map<int, string> v_string;
map<string, int> deg;

int main () {
    cin >> e >> v;
    for (int i = 1; i <= v; i++) {
        string s;
        cin >> s;
        v_index[s] = i;
        v_string[i] = s;
    }
    for (int i = 0; i < e; i++) {
        string s1, s2;
        int w;
        cin >> s1 >> s2 >> w;
        if (v_index[s1] > 0 && v_index[s1] <= v) deg[s1] = deg[s1] + 1;
        if (v_index[s2] > 0 && v_index[s2] <= v) deg[s2] = deg[s2] + 1;
    }
    int D;
    cin >> D;
    bool check = false;
    for (int i = 1; i <= v; i++) {
        if (deg[v_string[i]] == D) {
            check = true;
            cout << v_string[i] << " ";
        }
    }
    if (!check) cout << "No find";
}