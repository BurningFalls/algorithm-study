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

struct NODE {
	int idx;
	int score;
	int three;
	int two;
	int one;

	bool operator<(const NODE n) const {
		if (score == n.score) {
			if (three == n.three) {
				return two > n.two;
			}
			return three > n.three;
		}
		return score > n.score;
	}

	bool operator==(const NODE n) const {
		return score == n.score && three == n.three && two == n.two;
	}
};

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> score(3, 0);
	vector<vector<int>> cnt(3, vector<int>(4, 0));
	FOR(i, 0, N - 1) {
		FOR(j, 0, 2) {
			int num;
			cin >> num;
			score[j] += num;
			cnt[j][num]++;
		}
	}
	vector<NODE> v;
	FOR(i, 0, 2) {
		v.push_back({ i + 1, score[i], cnt[i][3], cnt[i][2], cnt[i][1]});
	}
	sort(ALL(v));

	if (v[0] == v[1]) {
		cout << 0 << " " << v[0].score;
	}
	else {
		cout << v[0].idx << " " << v[0].score;
	}

	return 0;
}