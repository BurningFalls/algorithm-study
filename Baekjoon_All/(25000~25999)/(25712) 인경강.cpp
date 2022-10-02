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

bool is_Overlap(int a, int b, int c, int d) {
	if (b < c) return false;
	if (d < a) return false;
	return true;
}


int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<int> len(M);
	vector<vector<int>> nums(M);
	vector<vector<int>> check(M);
	FOR(i, 0, M - 1) {
		cin >> len[i];
		nums[i] = vector<int>(len[i]);
		check[i] = vector<int>(len[i], 0);
	}
	FOR(i, 0, M - 1) {
		FOR(j, 0, len[i] - 1) {
			cin >> nums[i][j];
		}
	}

	bool ans = true;
	FOR(i, 0, len[0] - 1) {
		check[0][i] = 1;
	}
	FOR(i, 1, M - 1) {
		for (int j = 0; j < len[i]; j += 2) {
			bool flag = false;
			for (int k = 0; k < len[i - 1]; k += 2) {
				if (!check[i - 1][k]) continue;
				if (is_Overlap(nums[i - 1][k], nums[i - 1][k + 1], nums[i][j], nums[i][j + 1])) {
					check[i][j] = 1;
				}
			}
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < len[M - 1]; i += 2) {
		cnt += (check[M - 1][i]);
	}
	if (cnt == 0) {
		ans = false;
	}

	cout << (ans ? "YES" : "NO");

	return 0;
}