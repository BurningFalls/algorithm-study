#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
string ans = "";
int CNT = 0;
string ANS;

void DFS(int sum) {
	if (sum > N)
		return;
	if (sum == N) {
		CNT++;
		if (CNT == K)
			ANS = ans;
		return;
	}
	FOR(i, 1, 3) {
		ans += (i + '0');
		DFS(sum + i);
		ans.pop_back();
	}
}

int main() {
	FASTIO;
	int cnt[11];
	cin >> N >> K;
	cnt[1] = 1;
	cnt[2] = 2;
	cnt[3] = 4;
	FOR(i, 4, 10)
		cnt[i] = cnt[i - 3] + cnt[i - 2] + cnt[i - 1];
	if (cnt[N] < K) {
		cout << -1;
		return 0;
	}
	DFS(0);
	int len = ANS.size();
	FOR(i, 0, len - 1) {
		cout << ANS[i];
		if (i != len - 1)
			cout << '+';
	}

	return 0;
}