#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> v[5001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int x, y;
		cin >> x >> y;
		v[y].push_back(x);
	}
	FOR(i, 1, N)
		sort(v[i].begin(), v[i].end());
	int ans = 0;
	FOR(i, 1, N) {
		int len = v[i].size();
		FOR(j, 0, len - 1) {
			if (j == 0)
				ans += v[i][j + 1] - v[i][j];
			else if (j == len - 1)
				ans += v[i][j] - v[i][j - 1];
			else {
				int left = v[i][j] - v[i][j - 1];
				int right = v[i][j + 1] - v[i][j];
				ans += min(left, right);
			}
		}
	}
	cout << ans;


	return 0;
}