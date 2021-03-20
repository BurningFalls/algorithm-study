#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
bool A[301][301];
bool B[301][301];

bool Calc(int y, int x) {
	bool ans = false;
	FOR(i, 1, N) {
		ans |= (A[y][i] & B[i][x]);
	}
	return ans;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) FOR(j, 1, N)
		cin >> A[i][j];
	FOR(i, 1, N) FOR(j, 1, N)
		cin >> B[i][j];
	int cnt = 0;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			bool tmp = Calc(i, j);
			cnt += tmp;
		}
	}
	cout << cnt;

	return 0;
}