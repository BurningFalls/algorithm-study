#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	PQ<pii> pq;
	vector<pii> v(M, { 0, 0 });
	int ans = 0;
	FOR(i, 0, M - 1) {
		cin >> v[i].second;
		ans += v[i].second;
	}
	FOR(i, 0, M - 1) {
		cin >> v[i].first;
	}
	FOR(i, 0, M - 1) {
		pq.push(v[i]);
	}
	N = 24 * N;
	while (!pq.empty() && N > 0) {
		int study = pq.top().first;
		int score = pq.top().second;
		pq.pop();
		int tmp = (100 - score) / study;
		int cnt = min(N, tmp);
		N -= cnt;
		ans += study * cnt;
		score += study * cnt;
		study = 100 - score;
		if (study != 0) {
			pq.push({ study, score });
		}
	}
	cout << ans;

	return 0;
}