#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 200001

struct NODE {
	int day;
	ll x;
	ll y;
};

int N, K, Q; ll R;
vector<NODE> v(MAX);

int UB(int tg) {
	int left = 0, right = K - 1;
	int ans = K - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (v[mid].day > tg) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	FASTIO;
	cin >> N >> K >> R >> Q;
	FOR(i, 0, K - 1) {
		cin >> v[i].day >> v[i].x >> v[i].y;
	}
	FOR(i, 0, Q - 1) {
		int day; ll x, y;
		cin >> day >> x >> y;
		int ub = UB(day);
		if (v[ub - 1].x == v[ub].x) {
			ll cx = v[ub - 1].x;
			ll cy = v[ub - 1].y;
			if (v[ub - 1].y < v[ub].y) {
				cy += day - v[ub - 1].day;
			}
			else if (v[ub - 1].y > v[ub].y) {
				cy -= day - v[ub - 1].day;
			}
			if (cx == x || (cx - x) * (cx - x) + (cy - y) * (cy - y) > R * R) {
				cout << "gori";
			}
			else {
				if (v[ub - 1].y < v[ub].y) {
					cout << (cx < x ? "unsafe" : "safe");
				}
				else if (v[ub - 1].y > v[ub].y) {
					cout << (cx > x ? "unsafe" : "safe");
				}
			}
		}
		else if (v[ub - 1].y == v[ub].y) {
			ll cx = v[ub - 1].x;
			ll cy = v[ub - 1].y;
			if (v[ub - 1].x < v[ub].x) {
				cx += day - v[ub - 1].day;
			}
			else if (v[ub - 1].x > v[ub].x) {
				cx -= day - v[ub - 1].day;
			}
			if (cy == y || (cx - x) * (cx - x) + (cy - y) * (cy - y) > R * R) {
				cout << "gori";
			}
			else {
				if (v[ub - 1].x < v[ub].x) {
					cout << (cy < y ? "safe" : "unsafe");
				}
				else if (v[ub - 1].x > v[ub].x) {
					cout << (cy > y ? "safe" : "unsafe");
				}
			}
		}
		cout << "\n";
	}

	return 0;
}