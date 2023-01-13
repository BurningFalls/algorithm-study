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

bool compare(pii a, pii b) {
	return a.first < b.first;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<pii> v(N + 1);
	v[0] = { 0, 0 };
	FOR(i, 1, N) {
		cin >> v[i].first >> v[i].second;
	}
	sort(ALL(v), compare);

	int ans = 0;
	int a = 0, b = 0;
	bool flag = true;
	FOR(i, 1, N) {
		FOR(j, v[i - 1].first + 1, v[i].first) {
			if ((j - 1) % 7 == 5 || (j - 1) % 7 == 6) continue;
			a++;
		}
		b += v[i].first - v[i - 1].first;
		if (a >= v[i].second) {
			a -= v[i].second;
		}
		else if (a < v[i].second) {
			v[i].second -= a;
			a = 0;
			if (b >= v[i].second) {
				b -= v[i].second;
				ans += v[i].second;
			}
			else if (b < v[i].second) {
				flag = false;
				break;
			}
		}
	}
	cout << (flag ? ans : -1);

	return 0;
}