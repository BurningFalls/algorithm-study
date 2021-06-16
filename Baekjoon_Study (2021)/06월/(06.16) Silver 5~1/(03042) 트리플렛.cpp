#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char Map[101][101];
pii arr[26];

int ccw(pii a, pii b, pii c) {
	int tmp1 = a.first * b.second + b.first * c.second + c.first * a.second;
	int tmp2 = a.second * b.first + b.second * c.first + c.second * a.first;
	if (tmp1 > tmp2)
		return 1;
	else if (tmp1 == tmp2)
		return 0;
	else if (tmp1 < tmp2)
		return -1;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	int cnt = 0;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
			if (Map[i][j] != '.') {
				arr[cnt] = { i, j };
				cnt++;
			}
		}
	}

	int ans = 0;
	FOR(i, 0, cnt - 1) {
		FOR(j, i + 1, cnt - 1) {
			FOR(k, j + 1, cnt - 1) {
				if (ccw(arr[i], arr[j], arr[k]) == 0)
					ans++;
			}
		}
	}
	cout << ans;


	return 0;
}