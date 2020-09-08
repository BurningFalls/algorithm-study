#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int N;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		cout << N << " => ";
		cout << N * N - N + 1 << "\n";
	}

	return 0;
}