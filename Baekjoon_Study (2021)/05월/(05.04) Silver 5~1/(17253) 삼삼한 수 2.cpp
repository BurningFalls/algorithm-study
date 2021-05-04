#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[40];

int main() {
	FASTIO;
	ll N;
	cin >> N;
	if (N == 0) {
		cout << "NO";
		return 0;
	}
	arr[0] = 1;
	FOR(i, 1, 39)
		arr[i] = arr[i - 1] * 3;
	int idx = 0;
	while (idx <= 39 && arr[idx] <= N)
		idx++;
	idx--;
	while (idx >= 0 && N) {
		N -= arr[idx];
		idx--;
		while (idx >= 0 && arr[idx] > N)
			idx--;
	}
	cout << ((N == 0) ? "YES" : "NO");

	return 0;
}