#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 1000000001

int arr[100003];
int con[100003] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	arr[0] = -INF;
	arr[N + 1] = INF;
	FOR(i, 1, N)
		cin >> arr[i];
	int cnt = 0;
	FOR(i, 1, N - 1) {
		if (arr[i] <= arr[i + 1]) {
			con[i] = 1;
			cnt++;
		}
	}
	if (cnt == N - 1)
		cout << N;
	else if (cnt == N - 2) {
		int ans = 0;
		int zero_idx = 0;
		FOR(i, 1, N - 1) {
			if (con[i] == 0)
				zero_idx = i;
		}
		if (arr[zero_idx - 1] <= arr[zero_idx + 1])
			ans++;
		if (arr[zero_idx] <= arr[zero_idx + 2])
			ans++;
		cout << ans;
	}
	else {
		cout << 0;
	}


	


	return 0;
}