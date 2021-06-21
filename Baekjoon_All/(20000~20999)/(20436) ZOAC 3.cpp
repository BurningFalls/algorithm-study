#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _INF {
	int y;
	int x;
	bool is_left;
} INF;

INF arr[26] = {
{1, 0, 1}, {2, 4, 0}, {2, 2, 1}, {1, 2, 1}, {0, 2, 1},
{1, 3, 1}, {1, 4, 1}, {1, 5, 0}, {0, 7, 0}, {1, 6, 0},
{1, 7, 0}, {1, 8, 0}, {2, 6, 0}, {2, 5, 0}, {0, 8, 0},
{0, 9, 0}, {0, 0, 1}, {0, 3, 1}, {1, 1, 1}, {0, 4, 1},
{0, 6, 0}, {2, 3, 1}, {0, 1, 1}, {2, 1, 1}, {0, 5, 0},
{2, 0, 1} };

int main() {
	FASTIO;
	char sl, sr;
	cin >> sl >> sr;
	int ly = arr[sl - 'a'].y;
	int lx = arr[sl - 'a'].x;
	int ry = arr[sr - 'a'].y;
	int rx = arr[sr - 'a'].x;
	string s;
	cin >> s;
	int len = s.size();
	int sum = 0;
	FOR(i, 0, len - 1) {
		INF tmp = arr[s[i] - 'a'];
		if (tmp.is_left) {
			sum += abs(ly - tmp.y) + abs(lx - tmp.x);
			ly = tmp.y; lx = tmp.x;
		}
		else if (!tmp.is_left) {
			sum += abs(ry - tmp.y) + abs(rx - tmp.x);
			ry = tmp.y; rx = tmp.x;
		}
	}
	cout << sum + len;


	return 0;
}