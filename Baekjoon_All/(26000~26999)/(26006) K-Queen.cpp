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

int main() {
	FASTIO;
	int N, K, R, C;
	cin >> N >> K;
	cin >> R >> C;
	vector<pii> v(K);
	FOR(i, 0, K - 1) {
		cin >> v[i].first >> v[i].second;
	}
	bool f1 = false, f2 = false;
	FOR(i, 0, K - 1) {
		if (R == v[i].first || C == v[i].second) {
			f1 = true;
			break;
		}
		if (R + C == v[i].first + v[i].second) {
			f1 = true;
			break;
		}
		if (R - C == v[i].first - v[i].second) {
			f1 = true;
			break;
		}
		if (C - R == v[i].second - v[i].first) {
			f1 = true;
			break;
		}
	}

	vector<int> dy = { -1, 0, 1, -1, 1, -1, 0, 1 };
	vector<int> dx = { -1, -1, -1, 0, 0, 1, 1, 1 };

	int total = 0;
	int cnt = 0;
	FOR(i, 0, 7) {
		int nr = R + dy[i];
		int nc = C + dx[i];
		if (nr < 1 || nc < 1 || nr > N || nc > N) continue;
		total++;
		bool f = false;
		FOR(j, 0, K - 1) {
			if (nr == v[j].first || nc == v[j].second) {
				f = true;
				break;
			}
			if (nr + nc == v[j].first + v[j].second) {
				f = true;
				break;
			}
			if (nr - nc == v[j].first - v[j].second) {
				f = true;
				break;
			}
			if (nc - nr == v[j].second - v[j].first) {
				f = true;
				break;
			}
		}
		cnt += f;
	}
	if (total == cnt) {
		f2 = true;
	}

	if (f1 && f2) {
		cout << "CHECKMATE";
	}
	else if (f1) {
		cout << "CHECK";
	}
	else if (f2) {
		cout << "STALEMATE";
	}
	else {
		cout << "NONE";
	}

	return 0;
}