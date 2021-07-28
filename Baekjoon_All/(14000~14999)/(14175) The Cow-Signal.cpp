#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	char arr[12][12];
	int M, N, K;
	cin >> M >> N >> K;
	FOR(i, 0, M - 1) {
		FOR(j, 0, N - 1) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 0, M* K - 1) {
		int col = i / K;
		FOR(j, 0, N * K - 1) {
			int row = j / K;
			cout << arr[col][row];
		}
		cout << "\n";
	}


	return 0;
}