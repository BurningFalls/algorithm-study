#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define lb long double

int N;
vector<pii> v;
pii p;

int ccw(pii a, pii b, pii c) {
	lb x = a.first * b.second + b.first * c.second + c.first * a.second;
	lb y = a.second * b.first + b.second * c.first + c.second * a.first;
	if (x - y < 0)
		return -1;
	else if (x - y > 0)
		return 1;
	else if (x - y == 0)
		return 0;
}

lb dist(pii a, pii b) {
	lb d1 = (a.first - b.first) * (a.first - b.first);
	lb d2 = (a.second - b.second) * (a.second - b.second);
	return sqrt(d1 + d2);
}

bool compare(pii a, pii b) {
	int temp = ccw(p, a, b);
	if (temp > 0)
		return true;
	else if (temp < 0)
		return false;
	else if (temp == 0) {
		return dist(p, a) < dist(p, b);
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	p = v[0];
	FOR(i, 1, N - 1) {
		if (v[i].first < p.first)
			p = v[i];
		else if (v[i].first == p.first) {
			if (v[i].second < p.second)
				p = v[i];
		}
	}
	sort(v.begin(), v.end(), compare);

	vector<pii> ans;
	FOR(i, 0, N - 1) {
		while (ans.size() >= 2 && ccw(ans[ans.size() - 2], ans[ans.size() - 1], v[i]) <= 0) {
			ans.pop_back();
		}
		ans.push_back(v[i]);
	}
	cout << ans.size();

	return 0;
}