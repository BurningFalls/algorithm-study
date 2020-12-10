#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 1000000001

int N;
int A[12];
int oper_cnt[5];
int oper[11];
int minimum = INF;
int maximum = -INF;

void DFS(int cnt) {
	if (cnt == N - 1) {
		int calc = A[1];
		FOR(i, 0, N - 2) {
			if (oper[i] == 1)
				calc += A[i + 2];
			else if (oper[i] == 2)
				calc -= A[i + 2];
			else if (oper[i] == 3)
				calc *= A[i + 2];
			else if (oper[i] == 4)
				calc /= A[i + 2];
		}
		minimum = min(minimum, calc);
		maximum = max(maximum, calc);
		return;
	}
	FOR(i, 1, 4) {
		if (oper_cnt[i] == 0) continue;
		oper[cnt] = i;
		oper_cnt[i]--;
		DFS(cnt + 1);
		oper_cnt[i]++;
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> A[i];
	FOR(i, 1, 4)
		cin >> oper_cnt[i];
	DFS(0);
	cout << maximum << "\n" << minimum;

	return 0;
}