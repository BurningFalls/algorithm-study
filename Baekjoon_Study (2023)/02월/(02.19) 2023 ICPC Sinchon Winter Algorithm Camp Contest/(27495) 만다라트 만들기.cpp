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
	vector<vector<string>> v(9, vector<string>(9));
	FOR(i, 0, 8) {
		FOR(j, 0, 8) {
			cin >> v[i][j];
		}
	}

	map<string, vector<string>> mp;
	vector<int> dy = { -2, -2, -2, 0, 0, 2, 2, 2 };
	vector<int> dx = { -2, 0, 2, -2, 2, -2, 0, 2 };
	int idx = 0;
	FOR(i, 3, 5) {
		FOR(j, 3, 5) {
			if (i == 4 && j == 4) continue;
			string s = v[i][j];
			vector<string> tmp;
			int ny = i + dy[idx];
			int nx = j + dx[idx];
			idx++;
			FOR(a, ny - 1, ny + 1) {
				FOR(b, nx - 1, nx + 1) {
					if (a == ny && b == nx) continue;
					tmp.push_back(v[a][b]);
				}
			}
			sort(ALL(tmp));
			mp.insert({ s, tmp });
		}
	}


	idx = 1;
	for (const auto &x : mp) {
		string name = x.first;
		vector<string> tmp = x.second;
		cout << "#" << idx << ". " << name << "\n";
		FOR(i, 0, 7) {
			cout << "#" << idx << "-" << i + 1 << ". " << tmp[i] << "\n";
		}
		idx++;
	}

	return 0;
}