#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
vector<int> group[100001];
int cnt[100001];
bool infected[100001];
bool tmp_infect[100001];
bool store_infect[100001];

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		cin >> cnt[i];
		FOR(j, 1, cnt[i]) {
			int num;
			cin >> num;
			group[i].push_back(num);
		}
	}
	FOR(i, 1, N) {
		cin >> infected[i];
		tmp_infect[i] = infected[i];
	}
	ROF(i, M, 1) {
		bool zero_flag = false;
		FOR(j, 0, cnt[i] - 1) {
			if (tmp_infect[group[i][j]] == 0) {
				zero_flag = true;
				break;
			}
		}
		if (zero_flag) {
			FOR(j, 0, cnt[i] - 1) {
				tmp_infect[group[i][j]] = 0;
			}
		}
	}
	FOR(i, 1, N) {
		store_infect[i] = tmp_infect[i];
	}
	FOR(i, 1, M) {
		bool one_flag = false;
		FOR(j, 0, cnt[i] - 1) {
			if (tmp_infect[group[i][j]] == 1) {
				one_flag = true;
				break;
			}
		}
		if (one_flag) {
			FOR(j, 0, cnt[i] - 1) {
				tmp_infect[group[i][j]] = 1;
			}
		}
	}
	bool ans = true;
	FOR(i, 1, N) {
		if (infected[i] != tmp_infect[i]) {
			ans = false;
			break;
		}
	}
	if (ans) {
		cout << "YES\n";
		FOR(i, 1, N)
			cout << store_infect[i] << " ";
	}
	else {
		cout << "NO";
	}
	

	return 0;
}