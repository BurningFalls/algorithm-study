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
	int N;
	cin >> N;
	vector<int> v(N);
	vector<vector<pii>> pos(N, vector<pii>());
	FOR(i, 0, N - 1) {
		cin >> v[i];
		pos[i].push_back({ 1, v[i] });
	}
	FOR(i, 1, N - 1) {
		for (pii x : pos[i - 1]) {
			if (x.second >= v[i]) {
				pos[i].push_back({ x.first + 1, x.second + v[i] });
			}
			else {
				pos[i].push_back(x);
			}
		}
	}
	int maxi = 0;
	for (pii x : pos[N - 1]) {
		maxi = max(maxi, x.first);
	}
	cout << maxi;

	return 0;
}