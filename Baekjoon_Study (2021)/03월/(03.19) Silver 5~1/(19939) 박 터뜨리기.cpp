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
	cin >> N >> K;
	int tmp = K * (K + 1) / 2;
	if (N < tmp)
		cout << -1;
	else {
		if ((N - tmp) % K == 0)
			cout << K - 1;
		else
			cout << K;
	}

	return 0;
}