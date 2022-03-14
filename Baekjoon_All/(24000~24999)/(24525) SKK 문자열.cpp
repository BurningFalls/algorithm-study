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
#define NUM 100000

int main() {
	FASTIO;
	string S;
	cin >> S;
	int len = LEN(S);
	vector<int> psum(len + 1, 0);
	vector<int> idx(300001, INF);
	vector<int> kcnt(len + 1, 0);
	vector<int> scnt(len + 1, 0);
	FOR(i, 1, len) {
		psum[i] = psum[i - 1];
		kcnt[i] = kcnt[i - 1];
		scnt[i] = scnt[i - 1];
		if (S[i - 1] == 'S') {
			psum[i] += 2;
			scnt[i] += 1;
		}
		else if (S[i - 1] == 'K') {
			psum[i] -= 1;
			kcnt[i] += 1;
		}
	}
	int ans = -1;
	FOR(i, 0, len) {
		idx[psum[i] + NUM] = min(idx[psum[i] + NUM], i);
	}
	FOR(i, 1, len) {
		int left = idx[psum[i] + NUM];
		int skk_len = i - left;
		int k_cnt = kcnt[i] - kcnt[left];
		int s_cnt = scnt[i] - scnt[left];
		if (k_cnt != 0 && s_cnt != 0) {
			ans = max(ans, skk_len);
		}
	}
	cout << ans;

	return 0;
}