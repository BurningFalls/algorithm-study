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
	int N, K;
	cin >> N >> K;
	vector<vector<int>> v(N, vector<int>(3));
	FOR(i, 0, N - 1) {
		FOR(j, 0, 2) {
			cin >> v[i][j];
		}
	}

	vector<vector<int>> sum(3, vector<int>(N, 0));
	int maxi = 0;
	FOR(i, 0, 2) {
		int r1 = i, r2 = (i + 1) % 3;
		vector<int> tmp;
		FOR(j, 0, N - 1) {
			tmp.push_back(v[j][r1] + v[j][r2]);
		}
		sort(ALL(tmp), greater<int>());
		int sum = 0;
		FOR(j, 0, K - 1) {
			sum += tmp[j];
		}
		maxi = max(maxi, sum);
	}
	cout << maxi;

	return 0;
}