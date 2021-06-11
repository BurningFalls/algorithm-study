#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<string, int> mp;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		mp[s] += 1;
	}
	string ans;
	int maxi = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (maxi <= (*it).second) {
			maxi = (*it).second;
			ans = (*it).first;
		}
	}
	cout << ans << " " << maxi;


	return 0;
}