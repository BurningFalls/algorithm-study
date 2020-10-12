#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int M;
		cin >> M;
		int maximum = 0;
		int sum = 0;
		FOR(i, 1, M) {
			int a, b;
			cin >> a >> b;
			sum = sum + a - b;
			if (sum < 0)
				maximum = max(maximum, -sum);
		}
		cout << maximum << "\n";
	}

	return 0;
}