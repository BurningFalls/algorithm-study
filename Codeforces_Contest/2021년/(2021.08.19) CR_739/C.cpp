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
		int K;
		cin >> K;
		int sqrtk = sqrt(K);
		if (sqrtk * sqrtk == K) {
			cout << sqrtk << " " << 1 << "\n";
			continue;
		}
		int a, b, c;
		c = (sqrtk + 1) * (sqrtk + 1);
		a = c - sqrtk * 2;
		b = (a + c) / 2;
		if (a <= K && K <= b)
			cout << K - a + 1 << " " << sqrtk + 1;
		else
			cout << sqrtk + 1 << " " << c - K + 1;
		cout << "\n";
	}


	return 0;
}