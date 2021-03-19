#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string s;
int len;

int Do() {
	pii arr[4];
	FOR(i, 0, len - 1) {
		if (s[i] == 'c')
			arr[i] = { 1, 26 };
		else if (s[i] == 'd')
			arr[i] = { 30, 39 };
	}
	if (len == 1) {
		if (s == "c")
			return 26;
		else if (s == "d")
			return 10;
	}
	else if (len == 2) {
		int cnt = 0;
		FOR(i, arr[0].first, arr[0].second) {
			FOR(j, arr[1].first, arr[1].second) {
				if (i == j) continue;
				cnt++;
			}
		}
		return cnt;
	}
	else if (len == 3) {
		int cnt = 0;
		FOR(i, arr[0].first, arr[0].second) {
			FOR(j, arr[1].first, arr[1].second) {
				FOR(k, arr[2].first, arr[2].second) {
					if (i == j) continue;
					if (j == k) continue;
					cnt++;
				}
			}
		}
		return cnt;
	}
	else if (len == 4) {
		int cnt = 0;
		FOR(i, arr[0].first, arr[0].second) {
			FOR(j, arr[1].first, arr[1].second) {
				FOR(k, arr[2].first, arr[2].second) {
					FOR(m, arr[3].first, arr[3].second) {
						if (i == j) continue;
						if (j == k) continue;
						if (k == m) continue;
						cnt++;
					}
				}
			}
		}
		return cnt;
	}
}

int main() {
	FASTIO;
	cin >> s;
	len = s.size();
	cout << Do();

	return 0;
}