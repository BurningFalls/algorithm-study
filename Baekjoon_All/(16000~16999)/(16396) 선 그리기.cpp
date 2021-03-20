#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[10001] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		FOR(i, a, b - 1)
			arr[i] = 1;
	}
	int cnt = 0;
	FOR(i, 1, 10000) {
		if (arr[i])
			cnt++;
	}
	cout << cnt;

	return 0;
}