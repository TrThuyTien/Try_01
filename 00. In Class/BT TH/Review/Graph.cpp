#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

int main () {
    freopen("Graph.inp", "r", stdin);
    map<string, set<pair<string,int>>> ds;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        ds[u].insert({v,w});
    }
    cout << "yes";
    for (auto dinh : ds) {
        string u = dinh.first;
        cout << u << " ";
        set<pair<string,int>> dinhke = dinh.second;
        for (auto i : dinhke) {
            cout << i.first << " " << i.second << " - ";
        }
        cout << endl;
    }
}