#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool Check(int a, int b) {
	FOR(i, 2, min(a, b)) {
		if (a % i == 0 && b % i == 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		int cnt = 0;
		cin >> N;
		int tmp = sqrt(N);
		FOR(i, 1, tmp) {
			if (N % i == 0) {
				if (Check(i, N / i))
					cnt++;
			}
		}
		cout << cnt << "\n";
	}


	return 0;
}