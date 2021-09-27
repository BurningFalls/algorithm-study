#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

ll arr[100001];

int main() {
	FASTIO;
	ll N, X;
	cin >> N;
	ll sum = 0;
	FOR(i, 0, N - 1) {
		cin >> arr[i];
		sum += arr[i];
	}
	cin >> X;
	ll tmp = X / sum;
	ll ans = N * tmp;
	ll sub = sum * tmp;
	int idx = 0;
	while (sub <= X) {
		sub += arr[idx];
		idx++;
	}
	cout << ans + idx;

	return 0;
}