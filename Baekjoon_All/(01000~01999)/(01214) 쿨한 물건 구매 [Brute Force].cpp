#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int D, P, Q;
	cin >> D >> P >> Q;
	if (P < Q)
		swap(P, Q);
	int mini = 2100000000;
	FOR(i, 0, min(Q - 1, D / P + 1)) {
		int rest = max(D - P * i, 0);
		int j = ((rest % Q == 0) ? rest / Q : rest / Q + 1);
		mini = min(mini, i * P + j * Q);
	}
	cout << mini;


	return 0;
}