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

struct NODE {
	int w;
	int s;
	int e;
};

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	vector<NODE> v(N);
	int cnt = 0;
	FOR(i, 0, N - 1) {
		cin >> v[i].w >> v[i].s >> v[i].e;
	}

	FOR(bm, 0, (1 << N) - 1) {
		int sum = 0;
		FOR(i, 0, N - 1) {
			if (!(bm & (1 << i))) continue;
			sum += v[i].e - v[i].s + 1;
		}
		if (sum != K) continue;
		bool flag = true;
		FOR(i, 0, N - 1) {
			if (!(bm & (1 << i))) continue;
			if (v[i].w == 5) {
				flag = false;
			}
		}
		vector<vector<int>> check(6, vector<int>(11, 0));
		FOR(i, 0, N - 1) {
			if (!(bm & (1 << i))) continue;
			FOR(j, v[i].s, v[i].e) {
				if (check[v[i].w][j]) {
					flag = false;
				}
				else {
					check[v[i].w][j] = 1;
				}
			}
		}
		if (!flag) continue;
		cnt++;
	}
	cout << cnt;

	return 0;
}