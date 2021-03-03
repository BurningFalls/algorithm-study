#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M;
ll height[1001][1001];
bool need[1001][1001] = { 0, };

int main() {
	FASTIO;
	ll all_sum = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> height[i][j];
			all_sum += height[i][j];
		}
	}
	FOR(i, 1, N) {
		ll maximum = 0;
		FOR(j, 1, M)
			maximum = max(maximum, height[i][j]);
		FOR(j, 1, M) {
			if (maximum == height[i][j])
				need[i][j] = 1;
		}
	}
	FOR(i, 1, M) {
		ll maximum = 0;
		FOR(j, 1, N)
			maximum = max(maximum, height[j][i]);
		FOR(j, 1, N) {
			if (maximum == height[j][i])
				need[j][i] = 1;
		}
	}
	ll sub_sum = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (!need[i][j]) continue;
			sub_sum += height[i][j];
		}
	}

	cout << all_sum - sub_sum;


	return 0;
}