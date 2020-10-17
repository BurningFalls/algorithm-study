#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int x, y;
	int N;
	int ans1 = -1, ans2 = -1;
	int dist = 987654321;
	cin >> x >> y;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		if (i == 1) {
			ans1 = a;
			ans2 = b;
			dist = abs(x - a) + abs(y - b);
		}
		else {
			if (dist > abs(x - a) + abs(y - b)) {
				dist = abs(x - a) + abs(y - b);
				ans1 = a;
				ans2 = b;
			}
		}
	}
	cout << ans1 << " " << ans2;

	return 0;
}