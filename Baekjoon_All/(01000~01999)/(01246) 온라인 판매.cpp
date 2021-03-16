#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M;
int P[1001];
int sum[1001];

int main() {
	FASTIO;
	cin >> N >> M;
	sum[0] = 0;
	FOR(i, 1, M) {
		cin >> P[i];
		sum[i] = sum[i - 1] + P[i];
	}
	sort(P + 1, P + M + 1, greater<int>());
	int maximum = 0;
	int ans = 0;
	FOR(i, 1, min(N, M)) {
		if (maximum < P[i] * i) {
			maximum = P[i] * i;
			ans = P[i];
		}
	}
	cout << ans << " " << maximum;


	return 0;
}