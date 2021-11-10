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

vector<int> cnt(1001, 0);

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int a, b, c;
		cin >> a >> b >> c;
		FOR(j, a, b) {
			cnt[j] += c;
		}
	}
	int maxi = 0;
	FOR(i, 1, 1000) {
		maxi = max(maxi, cnt[i]);
	}
	cout << maxi;

	return 0;
}