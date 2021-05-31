#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[100001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	if (N == 0) {
		cout << 0;
		return 0;
	}
	int cnt = 1;
	ll tmp = 0;
	ROF(i, N, 1) {
		if (tmp + arr[i] > M) {
			cnt++;
			tmp = arr[i];
		}
		else {
			tmp += arr[i];
		}
	}
	cout << cnt;

	return 0;
}