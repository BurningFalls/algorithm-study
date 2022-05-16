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

int main() {
	FASTIO;
	int N;
	string S;
	cin >> N;
	cin >> S;

	int c_cnt = 0;
	FOR(i, 0, N - 1) {
		c_cnt += (S[i] == 'C');
	}

	if (c_cnt == 0) {
		cout << 0;
		return 0;
	}

	int idx = 1;
	while (idx <= N) {
		int group = N / (idx + 1);
		int rest = N % (idx + 1);
		int cnt = group * idx + rest;
		if (cnt >= c_cnt) {
			break;
		}
		idx++;
	}
	cout << idx;

	return 0;
}