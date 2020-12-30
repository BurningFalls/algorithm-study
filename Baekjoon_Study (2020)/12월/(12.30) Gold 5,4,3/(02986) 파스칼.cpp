#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	int ans = 1;
	FOR(i, 2, sqrt(N)) {
		if (N % i == 0) {
			ans = N / i;
			break;
		}
	}
	cout << N - ans;

	return 0;
}