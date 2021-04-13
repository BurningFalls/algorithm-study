#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int cnt[32770][5] = { 0, };

int main() {
	FASTIO;
	cnt[0][0] = 1;
	FOR(i, 1, 181) {
		FOR(j, 0, 32768) {
			if (j + i * i > 32768) continue;
			FOR(k, 0, 3) {
				if (cnt[j][k] != 0) {
					cnt[j + i * i][k + 1] += cnt[j][k];
				}
			}
		}
	}
	int num;
	while (true) {
		cin >> num;
		if (num == 0)
			break;
		int sum = 0;
		FOR(i, 1, 4)
			sum += cnt[num][i];
		cout << sum << "\n";
	}

	return 0;
}