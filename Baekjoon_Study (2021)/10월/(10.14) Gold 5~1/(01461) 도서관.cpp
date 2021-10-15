#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<int> minus, plus;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		if (num > 0) {
			plus.push_back(num);
		}
		else if (num < 0) {
			minus.push_back(num);
		}
	}
	sort(ALL(plus), greater<int>());
	sort(ALL(minus));
	vector<int> v;
	for (int i = 0; i < LEN(plus); i += M) {
		v.push_back(plus[i]);
	}
	for (int i = 0; i < LEN(minus); i += M) {
		v.push_back(-minus[i]);
	}
	sort(ALL(v));
	int ans = 0;
	FOR(i, 0, LEN(v) - 2) {
		ans += v[i] * 2;
	}
	ans += v.back();
	cout << ans;

	return 0;
}