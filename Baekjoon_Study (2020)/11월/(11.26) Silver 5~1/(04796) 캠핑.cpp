#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int idx = 1;
	while (true) {
		int L, P, V;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;
		int ans = L * (V / P);
		if (V / P != 0) {
			int temp = V - P * int(V / P);
			ans += min(temp, L);
		}
		cout << "Case " << idx << ": ";
		cout << ans << "\n";
		idx++;
	}

	return 0;
}