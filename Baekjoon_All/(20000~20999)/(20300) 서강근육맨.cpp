#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll arr[10001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	ll maxi = 0;
	if (N % 2 == 1) {
		FOR(i, 1, N / 2)
			maxi = max(maxi, arr[i] + arr[N - i]);
	}
	else if (N % 2 == 0) {
		FOR(i, 1, N / 2)
			maxi = max(maxi, arr[i] + arr[N + 1 - i]);
		maxi = max(maxi, arr[N]);
	}

	cout << maxi;


	return 0;
}