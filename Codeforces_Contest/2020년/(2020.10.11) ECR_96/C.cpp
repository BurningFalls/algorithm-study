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
		int N;
		cin >> N;
		cout << 2 << "\n";
		int a = N - 1;
		int b = N;
		cout << a << " " << b << "\n";
		ROF(i, a - 1, 1) {
			cout << i << " " << i + 2 << "\n";
		}
	}

	return 0;
}