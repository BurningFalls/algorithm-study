#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int P;
	cin >> P;
	FOR(i, 1, P) {
		int K, N;
		cin >> K >> N;
		cout << K << " ";
		cout << N * (N + 1) / 2 << " ";
		cout << N * N << " ";
		cout << N * N + N << "\n";
	}

	return 0;
}