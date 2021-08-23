#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 1000000000001

int N, K, C;
ll A[11];
ll ANS = INF;

ll BS() {
	ll left = 1, right = INF;
	ll ans = INF;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		FOR(i, 1, N) {
			sum += mid / A[i];
		}
		if (sum >= K) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return ans;
}

void DFS(int node, int cnt) {
	if ((node == N && A[N] == 1) || cnt == C) {
		ANS = min(ANS, BS());
		return;
	}
	FOR(i, node, N) {
		if (A[i] == 1) continue;
		A[i]--;
		DFS(i, cnt + 1);
		A[i]++;
	}
}

int main() {
	FASTIO;
	cin >> N >> K >> C;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	DFS(1, 0);
	cout << ANS;

	return 0;
}