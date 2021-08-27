#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

vector<pll> P, graham;

double triArea(pll a, pll b, pll c) {
	return 0.5 * abs((a.X * b.Y + b.X * c.Y + c.X * a.Y - b.X * a.Y - c.X * b.Y - a.X * c.Y));
}
double distV(pll v1, pll v2) {
	return sqrt((v1.X - v2.X) * (v1.X - v2.X) + (v1.Y - v2.Y) * (v1.Y - v2.Y));
}
double distVE(pll v, pll e1, pll e2) {
	if (v == e1 || v == e2)
		return 0.0;
	if (e1 == e2)
		return distV(v, e1);
	return 2.0 * triArea(v, e1, e2) / distV(e1, e2);
}
bool cmp1(pll a, pll b) {
	if (a.Y == b.Y)
		return a.X < b.X;
	return a.Y < b.Y;
}
bool cmp2(pll a, pll b) {
	if (a.Y * b.X == a.X * b.Y)
		return cmp1(a, b);
	return a.Y * b.X < a.X * b.Y;
}
int CCW(pll a, pll b, pll c) {
	ll t1 = a.X * b.Y + b.X * c.Y + c.X * a.Y;
	ll t2 = a.Y * b.X + b.Y * c.X + c.Y * a.X;
	if (t1 - t2 > 0) return 1;
	else if (t1 - t2 == 0) return 0;
	else if (t1 - t2 < 0) return -1;
}
void GRAHAM() {
	sort(P.begin(), P.end(), cmp1);
	ll mvX = P[0].X;
	ll mvY = P[0].Y;
	FOR(i, 0, P.size() - 1) {
		P[i].X -= mvX;
		P[i].Y -= mvY;
	}
	sort(P.begin() + 1, P.end(), cmp2);
	vector<int> S;
	S.push_back(0);
	S.push_back(1);
	int cur = 2;
	while (cur < P.size()) {
		while (S.size() >= 2) {
			int a1 = S.back();
			S.pop_back();
			int a2 = S.back();
			if (CCW(P[a2], P[a1], P[cur]) >= 0) {
				S.push_back(a1);
				break;
			}
		}
		S.push_back(cur++);
	}
	FOR(i, 0, S.size() - 1) {
		graham.push_back(make_pair(P[S[i]].X + mvX, P[S[i]].Y + mvY));
	}
}

int main() {
	FASTIO;
	cout << fixed << setprecision(2);
	int idx = 0;
	while (true) {
		P.clear();
		graham.clear();
		int N;
		cin >> N;
		if (N == 0)
			return 0;
		idx++;
		FOR(i, 0, N - 1) {
			int x, y;
			cin >> x >> y;
			P.push_back({ x, y });
		}
		GRAHAM();
		double mn = 0.0;
		FOR(i, 0, graham.size() - 1) {
			double dist = distVE(graham[i], graham[0], graham[graham.size() - 1]);
			mn = max(mn, dist);
		}
		FOR(i, 0, graham.size() - 2) {
			double localmx = 0.0;
			FOR(j, 0, graham.size() - 1) {
				double dist = distVE(graham[j], graham[i], graham[i + 1]);
				localmx = max(localmx, dist);
			}
			mn = min(mn, localmx);
		}
		mn += 0.004999999999;
		cout << "Case " << idx << ": " << mn << '\n';
	}
}