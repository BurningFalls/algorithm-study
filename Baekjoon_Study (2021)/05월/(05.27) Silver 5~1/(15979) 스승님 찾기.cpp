#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int M, N;
	cin >> M >> N;
	M = abs(M);
	N = abs(N);
	if (M == 0 && N == 0)
		cout << 0;
	else if ((M == 0 && N == 1) ||
		(M == 1 && N == 0)) {
		cout << 1;
	}
	else if (M == 0 || N == 0)
		cout << 2;
	else {
		if (GCD(M, N) == 1)
			cout << 1;
		else
			cout << 2;
	}


	return 0;
}