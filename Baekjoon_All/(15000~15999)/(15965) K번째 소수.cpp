#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 7368787

bool is_prime[MAX + 1] = { 0, };

int main() {
	FASTIO;
	int K;
	cin >> K;
	is_prime[1] = 1;
	FOR(i, 2, MAX) {
		if (is_prime[i]) continue;
		for (int j = 2; i * j <= MAX; j++) {
			is_prime[i * j] = 1;
		}
	}
	int cnt = 0;
	FOR(i, 1, MAX) {
		if (is_prime[i] == 0)
			cnt++;
		if (cnt == K) {
			cout << i;
			break;
		}
	}

	return 0;
}