#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int ans = 0;
		FOR(i, 1, N - 1) {
			if (N % i == 0)
				ans += i;
		}
		cout << N << " is ";
		if (N < ans)
			cout << "an abundant";
		else if (N == ans)
			cout << "a perfect";
		else if (N > ans)
			cout << "a deficient";
		cout << " number.\n\n";
	}

	return 0;
}