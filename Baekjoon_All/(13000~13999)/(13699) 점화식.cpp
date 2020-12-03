#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll T[36] = { 0, };
	T[0] = 1;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 0, i - 1)
			T[i] += T[j] * T[(i - 1) - j];
	}
	cout << T[N];

	return 0;
}