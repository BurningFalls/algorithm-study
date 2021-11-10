#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

vector<int> cnt(1001, 0);

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<pii> v(N);
	FOR(i, 0, N - 1) {
		int a, b;
		cin >> a >> b;
		v[i] = { a, b - 1 };
		FOR(j, a, b - 1) {
			cnt[j]++;
		}
	}
	int day = 0;
	FOR(i, 0, 1000) {
		if (cnt[i] == 0) continue;
		day++;
	}
	int maxi = 0;
	FOR(i, 0, N - 1) {
		int tmp = 0;
		FOR(j, v[i].first, v[i].second) {
			if (cnt[j] == 1) {
				tmp++;
			}
		}
		maxi = max(maxi, day - tmp);
	}
	cout << maxi;


	return 0;
}