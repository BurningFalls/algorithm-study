#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000000000 + 1

int N, M, K;
int permu[102][102];
string ans;
bool flag = true;

int getPermu(int a, int b) {
	if (permu[a][b] != 0)
		return permu[a][b];
	if (a == 0 || b == 0)
		return permu[a][b] = 1;
	if (permu[b][a] != 0)
		return permu[a][b] = permu[b][a];
	permu[a][b] = min(getPermu(a - 1, b) + getPermu(a, b - 1), MAX);
	return permu[a][b];
}

void getWord(int a, int z, int left) {
	if (a == 0) {
		FOR(i, 1, z)
			ans += 'z';
		return;
	}
	if (z == 0) {
		FOR(i, 1, a)
			ans += 'a';
		return;
	}
	int idx = getPermu(a - 1, z);
	
	if (left < idx) {
		ans += 'a';
		getWord(a - 1, z, left);
	}
	else {
		ans += 'z';
		getWord(a, z - 1, left - idx);
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	permu[0][0] = 1;
	if (getPermu(N, M) < K)
		cout << -1;
	else {
		getWord(N, M, K - 1);
		cout << ans;
	}

	return 0;
}