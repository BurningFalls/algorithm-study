#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = LEN(s);
	vector<vector<int>> v(3, vector<int>());
	FOR(i, 0, len - 1) {
		v[s[i] - 'A'].push_back(i);
	}
	
	int ans = 0;
	int aidx = 0, bidx = 0, cidx = 0;
	while (bidx < LEN(v[1]) && cidx < LEN(v[2])) {
		if (v[1][bidx] < v[2][cidx]) {
			ans++; bidx++; cidx++;
		}
		else {
			cidx++;
		}
	}
	while (aidx < LEN(v[0]) && bidx < LEN(v[1])) {
		if (v[0][aidx] < v[1][bidx]) {
			ans++; aidx++; bidx++;
		}
		else {
			bidx++;
		}
	}
	cout << ans;

	return 0;
}