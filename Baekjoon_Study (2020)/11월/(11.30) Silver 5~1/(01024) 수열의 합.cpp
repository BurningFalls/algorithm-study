#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, L;
	cin >> N >> L;
	bool flag = false;
	FOR(i, L, 100) {
		int temp = N - (i * (i + 1)) / 2;
		if (temp % i == 0) {
			int x = temp / i;
			if (x >= -1) {
				flag = true;
				FOR(j, 1, i) {
					cout << x + j << " ";
				}
				break;
			}
		}
	}
	if (!flag)
		cout << -1;

	return 0;
}