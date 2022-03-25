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

int N;
int ans = 0;
int Map[20][20];

pii Move(int dir) {
	int maxi = 0;
	int flag = false;
	vector<pii> v;
	if (dir == 0) {
		FOR(i, 0, N - 1) {
			v.clear();
			FOR(j, 0, N - 1) {
				if (Map[i][j] == 0) continue;
				if (v.empty()) {
					v.push_back({ Map[i][j], 0 });
					continue;
				}
				if (v.back().second == 0 && v.back().first == Map[i][j]) {
					v.back().first++;
					v.back().second = 1;
				}
				else {
					v.push_back({ Map[i][j], 0 });
				}
			}
			int vlen = v.size();
			FOR(j, 0, vlen - 1) {
				if (v[j].first != Map[i][j]) flag = true;
				Map[i][j] = v[j].first;
				maxi = max(maxi, Map[i][j]);
			}
			FOR(j, vlen, N - 1) {
				Map[i][j] = 0;
			}
		}
	}
	else if (dir == 1) {
		FOR(i, 0, N - 1) {
			v.clear();
			ROF(j, N - 1, 0) {
				if (Map[i][j] == 0) continue;
				if (v.empty()) {
					v.push_back({ Map[i][j], 0 });
					continue;
				}
				if (v.back().second == 0 && v.back().first == Map[i][j]) {
					v.back().first++;
					v.back().second = 1;
				}
				else {
					v.push_back({ Map[i][j], 0 });
				}
			}
			int vlen = v.size();
			ROF(j, N - 1, N - vlen) {
				if (v[N - j - 1].first != Map[i][j]) flag = true;
				Map[i][j] = v[N - j - 1].first;
				maxi = max(maxi, Map[i][j]);
			}
			ROF(j, N - vlen - 1, 0) {
				Map[i][j] = 0;
			}
		}
	}
	else if (dir == 2) {
		FOR(j, 0, N - 1) {
			v.clear();
			FOR(i, 0, N - 1) {
				if (Map[i][j] == 0) continue;
				if (v.empty()) {
					v.push_back({ Map[i][j], 0 });
					continue;
				}
				if (v.back().second == 0 && v.back().first == Map[i][j]) {
					v.back().first++;
					v.back().second = 1;
				}
				else {
					v.push_back({ Map[i][j], 0 });
				}
			}
			int vlen = v.size();
			FOR(i, 0, vlen - 1) {
				if (v[i].first != Map[i][j]) flag = true;
				Map[i][j] = v[i].first;
				maxi = max(maxi, Map[i][j]);
			}
			FOR(i, vlen, N - 1) {
				Map[i][j] = 0;
			}
		}
	}
	else if (dir == 3) {
		FOR(j, 0, N - 1) {
			v.clear();
			ROF(i, N - 1, 0) {
				if (Map[i][j] == 0) continue;
				if (v.empty()) {
					v.push_back({ Map[i][j], 0 });
					continue;
				}
				if (v.back().second == 0 && v.back().first == Map[i][j]) {
					v.back().first++;
					v.back().second = 1;
				}
				else {
					v.push_back({ Map[i][j], 0 });
				}
			}
			int vlen = v.size();
			ROF(i, N - 1, N - vlen) {
				if (v[N - i - 1].first != Map[i][j]) flag = true;
				Map[i][j] = v[N - i - 1].first;
				maxi = max(maxi, Map[i][j]);
			}
			ROF(i, N - vlen - 1, 0) {
				Map[i][j] = 0;
			}
		}
	}
	return { maxi, flag };
}

void DFS(int stage) {
	if (stage == 11) {
		return;
	}
	int tmp_Map[20][20];
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			tmp_Map[i][j] = Map[i][j];
		}
	}
	FOR(i, 0, 3) {
		pii tmp = Move(i);
		int maxi = tmp.first;
		int flag = tmp.second;
		ans = max(ans, maxi);
		if (ans - maxi < 10 - stage && flag) {
			DFS(stage + 1);
		}
		FOR(j, 0, N - 1) {
			FOR(k, 0, N - 1) {
				Map[j][k] = tmp_Map[j][k];
			}
		}
	}
}

int main() {
	FASTIO;
	map<int, int> mp;
	int p[11];
	p[0] = 1;
	FOR(i, 1, 10) {
		p[i] = p[i - 1] * 2;
		mp.insert({ p[i], i });
	}
	cin >> N;
	
	int maxi = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			int num;
			cin >> num;
			Map[i][j] = mp[num];
			maxi = max(maxi, Map[i][j]);
		}
	}
	ans = max(ans, maxi);

	DFS(1);

	cout << (1 << ans);

	return 0;
}