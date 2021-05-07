#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007

ll arr[200001];

int main() {
	FASTIO;
	arr[1] = 1;
	arr[2] = 2;
	FOR(i, 3, 191229) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << arr[N] << "\n";
	}


	return 0;
}