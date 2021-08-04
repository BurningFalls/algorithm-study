#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool cmp(pii a, pii b) {
	return a.second > b.second;
}

pii arr[1001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int T, S;
		cin >> T >> S;
		arr[i] = { T, S };
	}
	sort(arr + 1, arr + N + 1, cmp);
	int Time = arr[1].second - arr[1].first;
	FOR(i, 2, N) {
		Time = min(arr[i].second, Time);
		Time -= arr[i].first;
	}
	if (Time < 0)
		cout << -1;
	else
		cout << Time;

	return 0;
}