#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

set<int> s;
int ans = 0;

void Check(int x) {
	while (x != 0) {
		if (s.count(x)) {
			ans = x;
		}
		x /= 2;
	}
}

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	FOR(i, 1, Q) {
		ans = 0;
		int x;
		cin >> x;
		Check(x);
		s.insert(x);
		cout << ans << "\n";
	}

	return 0;
}