#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool bulb[1000001] = { 0, };
bool goal[1000001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> goal[i];
	int cnt = 0;
	FOR(i, 1, N) {
		if (bulb[i] != goal[i]) {
			FOR(j, i, min(i + 2, N))
				bulb[j] = !bulb[j];
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}