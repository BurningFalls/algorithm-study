#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	queue<pair<int, int>> q;
	ll A, B;
	int ans = -2;
	cin >> A >> B;
	q.push({ A, 0 });
	while (!q.empty()) {
		ll n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (n == B) {
			ans = cnt;
			break;
		}
		if (n * 2 <= B) {
			q.push({ n * 2, cnt + 1 });
		}
		if (n * 10 + 1 <= B) {
			q.push({ n * 10 + 1, cnt + 1 });
		}
	}
	cout << ans + 1;

	return 0;
}