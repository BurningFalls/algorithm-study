#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[2001][2001];

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int D1, D2;
	cin >> D1 >> D2;
	FOR(i, D1, D2) {
		FOR(j, 1, i) {
			int gcd = GCD(j, i);
			arr[j / gcd][i / gcd] = 1;
		}
	}
	int cnt = 0;
	FOR(i, 1, D2) {
		FOR(j, 1, D2) {
			if (arr[i][j])
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}