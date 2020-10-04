#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
bool con[201][201];
int m_arr[1001];

bool Check() {
	FOR(i, 1, M - 1) {
		int a = m_arr[i];
		int b = m_arr[i + 1];
		if (!con[a][b])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N)
		FOR(j, 1, N)
			cin >> con[i][j];
	FOR(i, 1, M)
		cin >> m_arr[i];

	FOR(k, 1, N) {
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (i == j || i == k || k == j) continue;
				if (con[i][k] == 0 || con[k][j] == 0) continue;
				con[i][j] = 1;
			}
		}
	}
	FOR(i, 1, N)
		con[i][i] = 1;

	if (Check())
		cout << "YES";
	else
		cout << "NO";

	return 0;
}