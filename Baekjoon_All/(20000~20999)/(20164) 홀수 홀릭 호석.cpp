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

int mini = INF;
int maxi = 0;

void DFS(string s, int cnt) {
	int len = LEN(s);
	FOR(i, 0, len - 1) {
		if ((s[i] - '0') % 2 == 1) {
			cnt++;
		}
	}
	if (len >= 3) {
		FOR(i, 0, len - 2) {
			FOR(j, i + 1, len - 2) {
				string s1 = "", s2 = "", s3 = "";
				FOR(k, 0, len - 1) {
					if (k >= 0 && k <= i) {
						s1 += s[k];
					}
					else if (k >= i + 1 && k <= j) {
						s2 += s[k];
					}
					else if (k >= j + 1 && k <= len - 1) {
						s3 += s[k];
					}
				}
				int tmp = stoi(s1) + stoi(s2) + stoi(s3);
				DFS(to_string(tmp), cnt);
			}
		}
	}
	else if (len == 2) {
		int tmp = (s[0] - '0') + (s[1] - '0');
		DFS(to_string(tmp), cnt);
	}
	else if (len == 1) {
		mini = min(mini, cnt);
		maxi = max(maxi, cnt);
		return;
	}
}

int main() {
	FASTIO;
	string N;
	cin >> N;
	DFS(N, 0);
	cout << mini << " " << maxi;

	return 0;
}