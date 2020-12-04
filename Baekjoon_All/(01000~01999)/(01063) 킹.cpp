#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string x[8] = { "R", "L", "B", "T", "RT", "LT", "RB", "LB" };
	int dy[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
	int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
	string king, rock;
	int N;
	cin >> king >> rock >> N;
	int ky = king[1] - '0';
	int kx = king[0] - 'A' + 1;
	int ry = rock[1] - '0';
	int rx = rock[0] - 'A' + 1;
	FOR(i, 1, N) {
		string order;
		cin >> order;
		int kind = 0;
		FOR(j, 0, 7) {
			if (order == x[j]) {
				kind = j;
				break;
			}
		}
		int nky = ky + dy[kind];
		int nkx = kx + dx[kind];
		if (nky < 1 || nkx < 1 || nky > 8 || nkx > 8) continue;
		if (nky == ry && nkx == rx) {
			int nry = ry + dy[kind];
			int nrx = rx + dx[kind];
			if (nry < 1 || nrx < 1 || nry > 8 || nrx > 8) continue;
			ry = nry;
			rx = nrx;
		}
		ky = nky;
		kx = nkx;
	}
	char KC = kx + 'A' - 1;
	char RC = rx + 'A' - 1;
	cout << KC << ky << "\n" << RC << ry;

	return 0;
}