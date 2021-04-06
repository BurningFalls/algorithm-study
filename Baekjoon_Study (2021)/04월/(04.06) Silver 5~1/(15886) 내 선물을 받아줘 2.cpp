#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	char Map[1001];
	cin >> N;
	FOR(i, 1, N)
		cin >> Map[i];
	int cnt = 0;
	FOR(i, 1, N - 1) {
		if (Map[i] == 'E' && Map[i + 1] == 'W')
			cnt++;
	}
	cout << cnt;

	return 0;
}