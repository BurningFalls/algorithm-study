#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int num[1001][1001];

int main() {
	FASTIO;
	int N, a, b;
	cin >> N >> a >> b;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> num[i][j];
		}
	}
	int js = num[a][b];
	bool flag = true;
	FOR(i, 1, N) {
		if (js < num[a][i]) {
			flag = false;
			break;
		}
		if (js < num[i][b]) {
			flag = false;
			break;
		}
	}
	cout << (flag ? "HAPPY" : "ANGRY");

	return 0;
}