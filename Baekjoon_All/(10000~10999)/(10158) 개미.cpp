#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

bool operator==(pii a, pii b) {
	return a.first == b.first && a.second == b.second;
}

int main() {
	FASTIO;
	int W, H, x, y, T;
	cin >> W >> H;
	cin >> x >> y;
	cin >> T;

	int cnt = 0;
	pii pos = { y, x };
	pii dir = { 1, 1 };
	pii d[4] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
	pii limit[4] = { {H, W}, {H, 0}, {0, W}, {0, 0} };
	bool flag = true;
	while (flag) {
		FOR(i, 0, 3) {
			if (dir == d[i]) {
				if (i == 0 && pos.first - pos.second == y - x && pos.first <= y && pos.second <= x && cnt != 0) {
					cnt += y - pos.first;
					flag = false;
					break;
				}
				int tmp = min({ abs(limit[i].first - pos.first), abs(limit[i].second - pos.second) });
				cnt += tmp;
				pos.first += dir.first * tmp;
				pos.second += dir.second * tmp;
				if (pos.first == H || pos.first == 0) dir.first *= (-1);
				if (pos.second == W || pos.second == 0) dir.second *= (-1);
				break;
			}
		}
	}
	T %= cnt;

	pos = { y, x };
	dir = { 1, 1 };
	flag = true;
	while (flag) {
		FOR(i, 0, 3) {
			if (dir == d[i]) {
				int tmp = min({ abs(limit[i].first - pos.first), abs(limit[i].second - pos.second) });
				if (T < tmp) {
					pos.first += dir.first * T;
					pos.second += dir.second * T;
					flag = false;
					break;
				}
				T -= tmp;
				pos.first += dir.first * tmp;
				pos.second += dir.second * tmp;
				if (pos.first == H || pos.first == 0) dir.first *= (-1);
				if (pos.second == W || pos.second == 0) dir.second *= (-1);
				break;
			}
		}
	}

	cout << pos.second << " " << pos.first;

	return 0;
}