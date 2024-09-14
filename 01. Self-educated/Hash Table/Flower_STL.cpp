#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;
	vector <int> v;
	for (int i = 0; i < A.size(); i++) 
		v.push_back(A[i]);
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		Hash[v[i]] = i+1;
	}
	vector <int> ans;
	vector <int> d;
	map<int, int>::iterator it;
	it = Hash.begin();
	d.push_back(-1);
	while (it != Hash.end()) {
		ans.push_back(v[it->second - 1]);
		d.push_back(it->second - 1);
		++it;
	}
	if (ans.size() == K) return ans;
	for (int i = 1; i < d.size(); i++) {
		int j = d[i-1] + 1;
		while (ans.size() < K && j < d[i]) {
			ans.push_back(v[d[i]]);
		}
		if (ans.size() == K) break;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ans = get_ans(a,k);
	
	for (const int& x: ans) cout << x << ' ';
	return 0;
}

