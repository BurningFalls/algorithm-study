#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[20];

int main() {
	FASTIO;
	arr[0] = 1;
	FOR(i, 1, 19) {
		arr[i] = arr[i - 1] * i;
	}
	int idx = 19;
	ll N;
	cin >> N;
	if (N == 0) {
		cout << "NO";
		return 0;
	}
	while (idx >= 0 && N) {
		if (N >= arr[idx]) {
			N -= arr[idx];
		}
		idx--;
	}
	cout << ((N == 0) ? "YES" : "NO");

	return 0;
}