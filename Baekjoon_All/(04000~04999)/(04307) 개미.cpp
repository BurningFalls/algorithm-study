#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int ans_min = 0;
		int ans_max = 0;
		int L, N;
		cin >> L >> N;
		FOR(i, 1, N) {
			int ant;
			cin >> ant;
			int minimum = min(ant, L - ant);
			int maximum = max(ant, L - ant);
			ans_min = max(ans_min, minimum);
			ans_max = max(ans_max, maximum);
		}
		cout << ans_min << " ";
		cout << ans_max << "\n";
	}

	return 0;
}