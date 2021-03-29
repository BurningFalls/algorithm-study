#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[1000001];
vector<pii> v;

int main() {
	FASTIO;
	int ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		int kind, score, tim;
		cin >> kind;
		if (kind == 1) {
			cin >> score >> tim;
			v.push_back({ tim, score });
		}
		if (v.empty()) continue;
		v.back().first--;
		if (v.back().first == 0) {
			ans += v.back().second;
			v.pop_back();
		}
	}
	cout << ans;

	return 0;
}