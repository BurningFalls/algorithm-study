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
	cin >> N;
	vector<string> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}

	bool flag = true;
	vector<string> ans;
	FOR(i, 0, N - 1) {
		vector<char> tmp(5, ' ');
		vector<bool> check(5, 0);
		FOR(j, 0, 4) {
			if (v[i][j] == 'G') {
				tmp[j] = 'A' + j;
				check[j] = 1;
			}
			else if (v[i][j] == 'B') {
				tmp[j] = 'F';
			}
		}
		FOR(j, 0, 4) {
			if (v[i][j] == 'Y') {
				int idx = j;
				bool f = false;
				FOR(k, 0, 3) {
					idx = (idx + 1) % 5;
					if (check[idx]) continue;
					tmp[j] = idx + 'A';
					check[idx] = 1;
					f = true;
					break;
				}
				if (!f) {
					flag = false;
					break;
				}
			}
		}
		if (!flag) break;
		string s = "";
		FOR(i, 0, 4) {
			s += tmp[i];
		}
		ans.push_back(s);
	}

	if (flag) {
		cout << "ABCDE\n";
		for (string x : ans) {
			cout << x << "\n";
		}
	}
	else {
		cout << "IMPOSSIBLE";
	}

	return 0;
}