#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int n;
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		FOR(i, 1, n) {
			FOR(j, 1, i) {
				cout << '*';
			}
			cout << "\n";
		}
	}

	return 0;
}