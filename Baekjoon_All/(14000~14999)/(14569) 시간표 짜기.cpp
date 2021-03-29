#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
ll subject[1001] = { 0, };

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		int cnt;
		cin >> cnt;
		FOR(j, 1, cnt) {
			int num;
			cin >> num;
			num -= 1;
			subject[i] |= (1LL << num);
		}
	}
	cin >> M;
	FOR(i, 1, M) {
		int cnt;
		ll tmp = 0;
		cin >> cnt;
		FOR(j, 1, cnt) {
			int num;
			cin >> num;
			num -= 1;
			tmp |= (1LL << num);
		}

		int ans = 0;
		if (cnt != 0) {
			FOR(j, 1, N) {
				if ((tmp & subject[j]) == subject[j]) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}



	return 0;
}