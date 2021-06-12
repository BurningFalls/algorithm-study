#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, K;
	cin >> N;
	cin >> K;
	FOR(i, 1, K) {
		int a, b;
		cin >> a >> b;
		a = min(a, (N + 1 - a));
		b = min(b, (N + 1 - b));
		cout << (min(a, b) - 1) % 3 + 1 << "\n";
	}

	return 0;
}