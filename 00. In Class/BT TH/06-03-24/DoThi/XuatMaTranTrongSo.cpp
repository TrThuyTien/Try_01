#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int v, e; //v là số đỉnh, e là số cạnh
map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index

void Input(vector<vector<int>> &G) {
    for (int i = 0; i < v; i++) {
        string s;
        cin >> s;
        v_index[s] = i;
    }
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) 
            G[i].push_back(0);
    }
    for (int i = 0; i < e; i++) {
        string s1, s2;
        int w;
        cin >> s1 >> s2 >> w;
        int u = v_index[s1];
        int v = v_index[s2];
        G[u][v] = w;
    }
}

void Output(vector<vector<int>> G) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) 
            cout << G[i][j] << " ";
        cout << '\n';
    }
}

int main() {
	cin >> e >> v;
    vector<vector<int>> G (v, vector<int>(v, 0)); // ma trận kề
	Input(G);
	Output(G);
	return 0;
}

