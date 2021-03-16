#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M;
pii group[101];
bool arr[21] = { 0, };
bool ans = false;

bool Calc() {
	FOR(i, 1, M) {
		int a = group[i].first;
		int b = group[i].second;
		bool tmp = 0;
		if (a < 0 && b < 0) {
			tmp = (!arr[-a]) | (!arr[-b]);
		}
		else if (a < 0 && b > 0) {
			tmp = (!arr[-a]) | (arr[b]);
		}
		else if (a > 0 && b < 0) {
			tmp = (arr[a]) | (!arr[-b]);
		}
		else if (a > 0 && b > 0) {
			tmp = (arr[a]) | (arr[b]);
		}
		if (tmp == 0)
			return false;
	}
	return true;
}

void DFS(int cnt) {
	if (cnt > N) {
		ans = ans | Calc();
		return;
	}
	FOR(i, 0, 1) {
		arr[cnt] = i;
		DFS(cnt + 1);
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		cin >> group[i].first >> group[i].second;
	}
	DFS(1);
	cout << ans;

	return 0;
}