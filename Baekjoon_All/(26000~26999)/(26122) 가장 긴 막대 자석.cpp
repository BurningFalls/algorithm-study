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
	int K;
	cin >> K;
	string s;
	cin >> s;

	vector<int> v;
	int cnt = 0;
	char prev = s[0];
	FOR(i, 0, K - 1) {
		if (prev != s[i]) {
			v.push_back(cnt);
			cnt = 1;
			prev = s[i];
		}
		else if (prev == s[i]) {
			cnt++;
		}
	}
	v.push_back(cnt);

	int maxi = 0;
	FOR(i, 1, LEN(v) - 1) {
		maxi = max(maxi, min(v[i], v[i - 1]));
	}
	cout << 2 * maxi;

	return 0;
}