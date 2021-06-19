#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<string, int> mp;

int arr[1001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		mp.insert({ s, i });
	}
	FOR(i, 1, N) {
		string s;
		cin >> s;
		arr[i] = mp[s];
	}

	vector<int> v;
	int ans = 0;
	FOR(i, 1, N) {
		if (v.empty()) {
			v.push_back(arr[i]);
			continue;
		}
		if (v.back() > arr[i]) {
			while (!v.empty() && v.back() > arr[i]) {
				v.pop_back();
				ans++;
			}
		}
		v.push_back(arr[i]);
	}
	cout << ans;

	return 0;
}