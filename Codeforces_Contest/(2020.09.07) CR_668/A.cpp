#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int p[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		FOR(i, 1, n)
			cin >> p[i];
		ROF(i, n, 1)
			cout << p[i] << " ";
		cout << "\n";
	}

	return 0;
}