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
	vector<int> days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int N;
	cin >> N;
	int num;
	cin >> num;
	num -= 1;
	if ((N % 4 == 0 && N % 100 != 0) || N % 400 == 0) {
		days[2]++;
	}

	int ans = 0;
	FOR(i, 1, 12) {
		vector<int> cnt(7, 0);
		FOR(j, 1, days[i]) {
			cnt[num]++;
			num = (num + 1) % 7;
		}
		FOR(i, 0, 6) {
			ans += (cnt[i] >= 5);
		}
	}
	cout << ans;

	return 0;
}