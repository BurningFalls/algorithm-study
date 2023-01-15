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

int Check(string s, vector<int> v) {
	sort(ALL(v));
	int maxi = 0;
	FOR(i, 0, 5) {
		if (s[i] == 'Y') {
			int cnt = 0;
			FOR(j, 0, 4) {
				cnt += (v[j] == i + 1) * (i + 1);
			}
			maxi = max(maxi, cnt);
		}
	}
	if (s[6] == 'Y') {
		if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) {
			maxi = max(maxi, v[0] * 4);
		}
		if (v[1] == v[2] && v[2] == v[3] && v[3] == v[4]) {
			maxi = max(maxi, v[1] * 4);
		}
	}
	if (s[7] == 'Y') {
		if (v[0] == v[1] && v[1] == v[2] && v[2] != v[3] && v[3] == v[4] ) {
			maxi = max(maxi, v[0] + v[1] + v[2] + v[3] + v[4]);
		}
		if (v[0] == v[1] && v[1] != v[2] && v[2] == v[3] && v[3] == v[4]) {
			maxi = max(maxi, v[0] + v[1] + v[2] + v[3] + v[4]);
		}
	}
	if (s[8] == 'Y') {
		if (v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 && v[4] == 5) {
			maxi = max(maxi, 30);
		}
	}
	if (s[9] == 'Y') {
		if (v[0] == 2 && v[1] == 3 && v[2] == 4 && v[3] == 5 && v[4] == 6) {
			maxi = max(maxi, 30);
		}
	}
	if (s[10] == 'Y') {
		if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[3] == v[4]) {
			maxi = max(maxi, 50);
		}
	}
	if (s[11] == 'Y') {
		maxi = max(maxi, v[0] + v[1] + v[2] + v[3] + v[4]);
	}
	return maxi;
}

int main() {
	FASTIO;
	string s;
	cin >> s;
	vector<int> v(5);
	int ans = 0;
	FOR(i, 0, 2) {
		cin >> v[i];
	}
	FOR(i, 1, 6) {
		v[3] = i;
		FOR(j, 1, 6) {
			v[4] = j;
			ans = max(ans, Check(s, v));
		}
	}
	cout << ans;

	return 0;
}