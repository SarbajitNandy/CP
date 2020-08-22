#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);

	vector<int> data[26];

	int n; cin >> n;
	string s; cin >> s;

	for(int i=0;i<n;i++) {
		data[s[i]-'a'].push_back(i+1);
	}
	int q, ans; cin >> q;
	map<int, int> cnt;

	while (q--) {
		cin >> s;
		cnt.clear();
		for( auto i: s) {
			cnt[i-'a']++;
		}
		ans=-1;
		for(auto i: cnt) {
			ans = max(ans, data[i.first][i.second -1]);
		}

		cout << ans<< endl;
	}
}