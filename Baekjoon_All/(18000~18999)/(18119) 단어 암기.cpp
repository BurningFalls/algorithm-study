#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[10001][26] = { 0, };
int len[10001];
int cnt[10001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		string s;
		int temp = 0;
		cin >> s;
		FOR(j, 0, s.size() - 1) {
			if (arr[i][s[j] - 'a'] == 0) {
				temp++;
				arr[i][s[j] - 'a'] = 2;
			}
		}
		len[i] = temp;
		cnt[i] = temp;
	}
	FOR(i, 1, M) {
		int o;
		char x;
		cin >> o >> x;
		if (o == 1) {
			FOR(j, 1, N) {
				if (arr[j][x - 'a'] == 2) {
					cnt[j]--;
					arr[j][x - 'a'] = 1;
				}
			}
		}
		else if (o == 2) {
			FOR(j, 1, N) {
				if (arr[j][x - 'a'] == 1) {
					cnt[j]++;
					arr[j][x - 'a'] = 2;
				}
			}
		}
		int ans = 0;
		FOR(j, 1, N) {
			if (cnt[j] == len[j])
				ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}