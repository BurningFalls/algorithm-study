#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[20001];

int main() {
	FASTIO;
	int N, S;
	cin >> N >> S;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	ll cnt = 0;
	FOR(i, 1, N - 1) {
		int ub = upper_bound(arr + 1 + i, arr + N + 1, S - arr[i]) - arr;
		cnt += ub - i - 1;
	}
	cout << cnt;

	return 0;
}