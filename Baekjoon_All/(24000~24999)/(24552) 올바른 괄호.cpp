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
#define MAX 100000

int main() {
	FASTIO;
	string S;
	cin >> S;
	int len = LEN(S);
	vector<vector<int>> cnt(MAX, vector<int>(2, 0));
	int left = 0, right = 0;
	FOR(i, 0, len - 1) {
		if (S[i] == '(') {
			left++;
		}
		else if (S[i] == ')') {
			right++;
		}
	}
	if (left + 1 == right) {
		FOR(i, 0, len - 1) {
			if (i != 0) {
				cnt[i][0] = cnt[i - 1][0];
				cnt[i][1] = cnt[i - 1][1];
			}
			if (S[i] == '(') {
				cnt[i][0]++;
			}
			else if (S[i] == ')') {
				cnt[i][1]++;
			}
		}
	}
	else if (left == right + 1) {
		FOR(i, 0, len - 1) {
			if (i != 0) {
				cnt[i][0] = cnt[i - 1][0];
				cnt[i][1] = cnt[i - 1][1];
			}
			if (S[len - 1 - i] == ')') {
				cnt[i][0]++;
			}
			else if (S[len - 1 - i] == '(') {
				cnt[i][1]++;
			}
		}
	}
	FOR(i, 0, len - 1) {
		if (cnt[i][0] + 1 == cnt[i][1]) {
			cout << cnt[i][1];
			break;
		}
	}


	return 0;
}