#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;
	int t = 0;
	int pos = m;
	int exer = 0;
	if (m + T > M) {
		cout << -1;
		return 0;
	}
	while (exer < N) {
		if (pos + T <= M) {
			pos += T;
			exer++;
			t++;
		}
		else if (pos + T > M) {
			pos = max(m, pos - R);
			t++;
		}
	}
	cout << t;

	return 0;
}