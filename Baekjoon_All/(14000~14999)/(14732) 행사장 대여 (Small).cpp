#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[502][502] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(t, 1, N) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		FOR(i, y1, y2 - 1) {
			FOR(j, x1, x2 - 1) {
				arr[i][j] = 1;
			}
		}
	}

	int cnt = 0;
	FOR(i, 0, 500) {
		FOR(j, 0, 500) {
			if (arr[i][j])
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}