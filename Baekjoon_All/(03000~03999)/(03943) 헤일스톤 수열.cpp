#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int maximum = N;
		while (N != 1) {
			if (N % 2 == 0)
				N /= 2;
			else if (N % 2 == 1)
				N = N * 3 + 1;
			maximum = max(maximum, N);
		}
		cout << maximum << "\n";
	}

	return 0;
}