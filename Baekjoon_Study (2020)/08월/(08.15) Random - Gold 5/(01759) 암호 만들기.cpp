#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int L, C;
char arr[16];
char ans[16];

void DFS(int node, int cnt) {
	if (cnt == L) {
		int aei = 0;
		FOR(i, 0, L - 1) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				aei++;
		}
		if (aei >= 1 && aei <= L - 2) {
			FOR(i, 0, L - 1)
				cout << ans[i];
			cout << "\n";
		}
		return;
	}
	FOR(i, node, C - 1) {
		ans[cnt] = arr[i];
		DFS(i + 1, cnt + 1);
	}
}

int main() {
	FASTIO;
	cin >> L >> C;
	FOR(i, 0, C - 1)
		cin >> arr[i];
	sort(arr, arr + C);
	DFS(0, 0);

	return 0;
}