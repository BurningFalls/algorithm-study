#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

ll C[100001];
ll ans = 0;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> C[i];
		ans += C[i];
	}
	sort(C + 1, C + N + 1, greater<int>());
	for (int i = 3; i <= N; i += 3) {
		ans -= C[i];
	}
	cout << ans;

	return 0;
}