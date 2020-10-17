#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101] = { 0, };

int main() {
	FASTIO;
	int a, b;
	int c, d;
	cin >> a >> b;
	cin >> c >> d;

	FOR(i, a, b - 1)
		arr[i] = 1;
	FOR(i, c, d - 1)
		arr[i] = 1;
	int cnt = 0;
	FOR(i, 0, 99) {
		if (arr[i] == 1)
			cnt++;
	}
	cout << cnt;

	return 0;
}