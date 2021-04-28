#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
string arr[1001];

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		string tmp = "";
		FOR(j, 1, M) {
			char x;
			cin >> x;
			tmp += x;
		}
		arr[i] = tmp;
	}
	sort(arr + 1, arr + N + 1);
	bool fail = false;
	FOR(i, 0, M - 1) {
		bool flag = false;
		FOR(j, 1, N) {
			if (arr[j][i] == '1') {
				flag = true;
				continue;
			}
			if (flag && arr[j][i] == '0') {
				fail = true;
				break;
			}
		}
		if (fail)
			break;
	}
	cout << (fail ? "NO" : "YES");

	return 0;
}