#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct NODE {
	ll x;
	ll y;
	int idx;
	bool operator < (const NODE &t) const {
		if (x == t.x)
			return y < t.y;
		return x < t.x;
	}
};

vector<NODE> point;

int CCW(NODE a, NODE b, NODE c) {
	ll t1 = a.x * b.y + b.x * c.y + c.x * a.y;
	ll t2 = b.x * a.y + c.x * b.y + a.x * c.y;
	if (t1 - t2 > 0)
		return 1;
	else if (t1 - t2 == 0)
		return 0;
	else if (t1 - t2 < 0)
		return -1;
}

ll Calc_Dist(NODE a, NODE b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp(NODE a, NODE b) {
	int ccw = CCW(point[0], a, b);
	if (ccw == 0)
		return Calc_Dist(point[0], a) < Calc_Dist(point[0], b);
	return ccw > 0;
}

int main() {
	FASTIO;
	int C;
	cin >> C;
	while (C--) {
		point.clear();
		int N;
		cin >> N;
		FOR(i, 0, N - 1) {
			int x, y;
			cin >> x >> y;
			point.push_back({ x, y, i });
		}
		NODE mini = point[0];
		FOR(i, 1, N - 1) {
			if (point[i] < mini)
				mini = point[i];
		}
		swap(point[0], point[mini.idx]);
		sort(point.begin() + 1, point.end(), cmp);
		int idx = N - 1;
		ROF(i, N - 1, 1) {
			if (CCW(point[0], point[idx], point[idx - 1]) == 0)
				idx--;
			else
				break;
		}
		reverse(point.begin() + idx, point.end());
		for (NODE n : point)
			cout << n.idx << " ";
		cout << "\n";
	}

	return 0;
}