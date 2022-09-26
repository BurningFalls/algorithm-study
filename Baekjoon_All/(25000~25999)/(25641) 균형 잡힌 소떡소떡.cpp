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
	int N;
	string s;
	cin >> N;
	cin >> s;
	int s_cnt = 0, t_cnt = 0;
	FOR(i, 0, N - 1) {
		s_cnt += (s[i] == 's');
		t_cnt += (s[i] == 't');
	}
	int idx = 0;
	while (idx < N) {
		if (s_cnt == t_cnt) break;
		s_cnt -= (s[idx] == 's');
		t_cnt -= (s[idx] == 't');
		idx++;
	}
	FOR(i, idx, N - 1) {
		cout << s[i];
	}

	return 0;
}