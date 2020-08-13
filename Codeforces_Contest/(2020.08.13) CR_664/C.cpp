#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int n, m;
int A[201], B[201];

bool Check(int x) {
	FOR(i, 1, n) {
		bool flag = false;
		FOR(j, 1, m) {
			if (((A[i] & B[j]) | x) == x) {
				flag = true;
				break;
			}
		}
		if (!flag)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	cin >> n >> m;
	FOR(i, 1, n) cin >> A[i];
	FOR(i, 1, m) cin >> B[i];
	
	FOR(x, 0, 511) {
		if (Check(x)) {
			cout << x;
			break;
		}
	}

	return 0;
}