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
#define MAX 51

int N, M, len;
string S;
int C = INF, L = 0;
vector<vector<char>> Map(MAX, vector<char>(MAX));
vector<int> cnt(26, 0);
vector<int> needed(26, 0);
vector<vector<pii>> pos(26, vector<pii>());
string ans = "";

int main() {
	FASTIO;
	cin >> N >> M >> len;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
			cnt[Map[i][j] - 'a']++;
			pos[Map[i][j] - 'a'].push_back({ i, j });
		}
	}
	cin >> S;
	FOR(i, 0, len - 1) {
		needed[S[i] - 'a']++;
	}

	FOR(i, 0, 25) {
		if (needed[i] == 0) continue;
		C = min(C, cnt[i] / needed[i]);
	}

	pii start = { 1, 1 };
	FOR(i, 0, C * len) {
		pii end;
		if (i != C * len) {
			int ch = S[i % len] - 'a';
			end = pos[ch].back();
			pos[ch].pop_back();
		}
		else if (i == C * len) {
			end = { N, M };
		}
		int diff = abs(end.first - start.first);
		if (start.first < end.first) {
			FOR(i, 1, diff) {
				ans += 'D';
			}
		}
		else if (start.first > end.first) {
			FOR(i, 1, diff) {
				ans += 'U';
			}
		}
		L += diff;
		diff = abs(end.second - start.second);
		if (start.second < end.second) {
			FOR(i, 1, diff) {
				ans += 'R';
			}
		}
		else if (start.second > end.second) {
			FOR(i, 1, diff) {
				ans += 'L';
			}
		}
		L += diff;
		if (i != C * len) {
			ans += 'P';
			L += 1;
		}
		start = end;
	}
	cout << C << " " << L << "\n";
	cout << ans;

	return 0;
}