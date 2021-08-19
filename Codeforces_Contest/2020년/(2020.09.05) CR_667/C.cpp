#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 2100000000
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n, x, y;
		cin >> n >> x >> y;
		int minimum = INF;
		int ans1, ans2;
		FOR(start, 1, x) {
			FOR(len, 1, y - x) {
				int idx = 0;
				int temp = start;
				bool flag1 = false, flag2 = false;
				while (idx < n) {
					if (temp == x)
						flag1 = true;
					if (temp == y)
						flag2 = true;
					temp += len;
					idx++;
				}
				temp -= len;
				if (flag1 && flag2) {
					if (minimum > temp) {
						minimum = temp;
						ans1 = start;
						ans2 = len;
					}
				}
			}
		}
		int idx = 0;
		while (idx < n) {
			cout << ans1 << " ";
			ans1 += ans2;
			idx++;
		}
		cout << "\n";
	}

	return 0;
}