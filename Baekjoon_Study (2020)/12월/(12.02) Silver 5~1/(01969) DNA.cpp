#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[1001];

int main() {
	FASTIO;
	int N, M;
	string ans = "";
	int cnt = 0;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> arr[i];
	FOR(i, 0, M - 1) {
		int alpha[26] = { 0, };
		int maximum = 0;
		FOR(j, 1, N) {
			alpha[arr[j][i] - 'A']++;
		}
		FOR(j, 0, 25)
			maximum = max(maximum, alpha[j]);
		FOR(j, 0, 25) {
			if (maximum == alpha[j]) {
				char x = 'A' + j;
				ans += x;
				cnt += (N - alpha[j]);
				break;
			}
		}
	}
	cout << ans << "\n" << cnt;

	return 0;
}